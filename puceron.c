#include "simulation.h"

void mangeTomate(Tomate *tomate, Puceron *puceron)
{
    /* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, et ne le modifie pas sinon */
    // met à jour le compteur de reproduction du puceron en conséquence.
    if ((*tomate).etatCroissance > 4)
    {
        (*puceron).compteurReproduction++;
        (*tomate).etatCroissance = 0;
    }
    else
    {
        (*puceron).compteurReproduction = 0;
    }
}

void reproductionPuceron(Puceron *puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*puceron).compteurReproduction == 5)
    {
        int result;
        result = ajoutePuceron(*puceron, ensPuc, n, p, potager);
        if (result == 1)
        {
            (*puceron).compteurReproduction = 0; // ajouter condition si reproduction fonctionnelle
        }
    }
}

int testBordure(int i, int j, int n, int p, Case potager[n][p])
{
    if ((((i > -1) && (i < 29)) && ((j > -1) && (j < 29))) && ((potager[i][j].puceronCase == NULL) /*&& ((potager[i][j].coccinelleCase == NULL)==1)*/))
    {
        return 1;
    }
    return 0;
}

int genereDirection()
{
    int direction = 0;
    while ((direction == 0) || (direction == 5))
    {
        direction = 1 + rand() % 9;
    }
    return direction;
}

int ajoutePuceron(Puceron puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    int flag = 0;
    if ((*ensPuc).nbPuceron < 900)
    {
        Puceron nouveauPuceron;
        int n = puceron.coordPuceron.x;
        int p = puceron.coordPuceron.y;
        if (testBordure(n - 1, p - 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p - 1};
                potager[n - 1][p - 1].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n - 1, p, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p};
                potager[n - 1][p].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n - 1, p + 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p + 1};
                potager[n - 1][p + 1].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n, p - 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n, p - 1};
                potager[n][p - 1].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n, p + 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n, p + 1};
                potager[n][p + 1].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n + 1, p - 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p - 1};
                potager[n + 1][p - 1].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n + 1, p, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p};
                potager[n + 1][p].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n + 1, p + 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p + 1};
                potager[n + 1][p + 1].puceronCase = &nouveauPuceron;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            nouveauPuceron = (struct Puceron){nouveauPuceron.coordPuceron, 0, 0, genereDirection(), (*ensPuc).nbPuceron};
            (*ensPuc).tab[(*ensPuc).nbPuceron] = nouveauPuceron;
            (*ensPuc).nbPuceron = (*ensPuc).nbPuceron + 1;
        }
    }
    return flag;
}

void vieillissementPuceron(Puceron *puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*puceron).compteurVie == 10)
    {
        enlevePuceron(*puceron, ensPuc, n, p, potager);
    }
    else
    {
        (*puceron).compteurVie++;
    }
}

void enlevePuceron(Puceron puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{

    (*ensPuc).tab[puceron.index] = (*ensPuc).tab[(*ensPuc).nbPuceron - 1]; // remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
    (*ensPuc).tab[puceron.index].index = puceron.index;                    // réattribue le bon index au puceron qui vient detre déplacé
    (*ensPuc).nbPuceron = (*ensPuc).nbPuceron - 1;                         // corrige le nombre de puceron total dans l'ensemble Puceron
    potager[puceron.coordPuceron.x][puceron.coordPuceron.y].puceronCase = NULL;
}

void traduction_DirectionCoordonnees(int dir, int* n, int* p){
	if (dir<4){
		*n = (*n)-1;
	}else if (dir>6){
		*n = (*n)+1;
	}

	if ((dir == 1)||(dir == 4)||(dir == 7)){
		*p = (*p)-1;
	}else if ((dir == 3)||(dir == 6)||(dir == 9)){
		*p = (*p)+1;
	}
}

int presenceTomateMangeableDirection(Puceron puceron, int dir, int i, int j, Case potager[i][j]){
	int n = puceron.coordPuceron.x;
	int p = puceron.coordPuceron.y;

	traduction_DirectionCoordonnees(dir, &n, &p);

	if ((n>=0) && (n<i) && (p>=0) && (p<j) && (potager[n][p].tomateCase.etatCroissance > 4)){
		return 1;
	}else{
		return 0;
	}
}

int presenceInsecteDirection(Puceron puceron, int dir, int i, int j, Case potager[i][j]){
	int n = puceron.coordPuceron.x;
	int p = puceron.coordPuceron.y;

	traduction_DirectionCoordonnees(dir, &n, &p);

	if ((n>=0) && (n<i) && (p>=0) && (p<j) && (potager[n][p].puceronCase == NULL) && (potager[n][p].coccinelleCase == NULL)){
		return 0;
	}else{
		return 1;
	}
}


void directionPuceron(Puceron *puceron, int i, int j, Case potager[i][j]){
	int dir = (*puceron).direction;
	
	if ((presenceTomateMangeableDirection((*puceron),dir,i,j,potager) == 0)||(presenceInsecteDirection((*puceron),dir,i,j,potager)==1)){
	//Si il n'y a pas de tomates ds la direction ou qu'un insecte est déjà sur la case, alors on cherche ds les cases attenantes
		int testDir=1;
		int c=0;
		while ((c<8)&&((presenceTomateMangeableDirection((*puceron),testDir,i,j,potager)==0)||(presenceInsecteDirection((*puceron),testDir,i,j,potager)==1))){ 
		//tant qu'on a pas pas dépassé le nb max de directions possibles, et qu'il n'y a pas de tomate mûre trouvée, on continue la boucle
			testDir ++;
			if (testDir==5){
				testDir ++;
			}
			c++;
		}
		if (testDir<10){
			(*puceron).direction = testDir;
		}else{
			testDir=1;
			c=0;
			while ((c<8)&&(presenceInsecteDirection((*puceron),testDir,i,j,potager)==1)){ 
			//tant qu'on a pas pas dépassé le nb max de directions possibles, et qu'il n'y a pas de case sans insecte trouvée, on continue la boucle
				testDir ++;
				if (testDir==5){
					testDir ++;
				}
				c++;
			}
			if (testDir<10){
				(*puceron).direction = testDir;
			}
		}
	}
}

void deplacementPuceron(Puceron *puceron, int i, int j, Case potager[i][j]){
	directionPuceron(puceron, i, j, potager);
	
	if (presenceInsecteDirection((*puceron),(*puceron).direction,i,j,potager)==0){
		potager[(*puceron).coordPuceron.x][(*puceron).coordPuceron.y].puceronCase = NULL; //enlève le puceron de son ancienne case dans le potager
		traduction_DirectionCoordonnees((*puceron).direction, &((*puceron).coordPuceron.x), &((*puceron).coordPuceron.y));
		potager[(*puceron).coordPuceron.x][(*puceron).coordPuceron.y].puceronCase = puceron; //ajoute le puceron dans sa nouvelle case dans le potager
	}
}
