#include "simulation.h"

/*ensemblePuceron creerEnsemblePuceronVide()
{
    ensemblePuceron ensPuc;
    ensPuc.nbPuceron = 0;
    return ensPuc;
}

Puceron* pointeurPuceron(ensemblePuceron *ensPuc, int index)
{
    if (index < (*ensPuc).nbPuceron)
    {
        return (*ensPuc).tab[index];
    }
}
*/

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
};

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
};

int testBordure(int i, int j, int n, int p, Case potager[n][p])
{
    if ((((i > -1) && (i < 29)) && ((j > -1) && (j < 29))) && ((potager[i][j].puceronCase == NULL) /*&& ((potager[i][j].coccinelleCase == NULL)==1)*/))
    {
        return 1;
    }
    return 0;
}

int ajoutePuceron(Puceron puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    int flag = 0;
    if ((*ensPuc).nbPuceron < 900)
    {
        Puceron nouveauPuceron;
        int n = puceron.coordPuceron.x;
        int p = puceron.coordPuceron.y;
        if (testBordure(n-1,p-1,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p - 1};
                potager[n-1][p-1].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n-1,p,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p};
                potager[n-1][p].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n-1,p+1,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p + 1};
                potager[n-1][p+1].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n,p-1,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n, p - 1};
                potager[n][p-1].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n,p+1,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n, p + 1};
                potager[n][p+1].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n+1,p-1,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p - 1};
                potager[n+1][p-1].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n+1,p,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p};
                potager[n+1][p].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        else if (testBordure(n+1,p+1,30,30,potager) == 1 )
        {
            {
                nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p + 1};
                potager[n+1][p+1].puceronCase=&nouveauPuceron;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            int nouvelleDirection = 0;
            while ((nouvelleDirection == 0) || (nouvelleDirection == 5))
            {
                nouvelleDirection = 1 + rand() % 9;
            }
            nouveauPuceron = (struct Puceron){nouveauPuceron.coordPuceron, 0, 0, nouvelleDirection, (*ensPuc).nbPuceron};
            (*ensPuc).tab[(*ensPuc).nbPuceron] = nouveauPuceron;
            (*ensPuc).nbPuceron = (*ensPuc).nbPuceron + 1;
        }
    }
    return flag;
};

void vieillissementPuceron(Puceron *puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*puceron).compteurVie == 10)
    {
        enlevePuceron(*puceron, ensPuc, n, p, potager);
    }
    else
    {
        (*puceron).compteurVie ++;
    }
};

void enlevePuceron(Puceron puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{


    (*ensPuc).tab[puceron.index] = (*ensPuc).tab[(*ensPuc).nbPuceron - 1];// remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
    (*ensPuc).tab[puceron.index].index = puceron.index;// réattribue le bon index au puceron qui vient detre déplacé
    (*ensPuc).nbPuceron = (*ensPuc).nbPuceron - 1;// corrige le nombre de puceron total dans l'ensemble Puceron
    potager[puceron.coordPuceron.x][puceron.coordPuceron.y].puceronCase = NULL;
};
