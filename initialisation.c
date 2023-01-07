#include "simulation.h"

ensemblePuceron creerEnsemblePuceron(int n, int ligne, int colonne, Case potager[ligne][colonne])
{
    ensemblePuceron ensPuc;
    apparitionPuceron(n, &ensPuc, ligne, colonne, potager);
    ensPuc.nbPuceron = n;
    return ensPuc;
}

void initialisationPotagerVide(int ligne, int colonne, Case potager[ligne][colonne]){
	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			potager[i][j].puceronCase = NULL;
			potager[i][j].coccinelleCase = NULL;
		}
	}
}

void remplissagePotagerTomate(int ligne, int colonne, Case potager[ligne][colonne])
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < ligne; j++)
        { 
            Tomate tomate = {{i, j}, 20};
            potager[i][j].tomateCase = tomate;
        }
    }
}

void apparitionPuceron(int n, ensemblePuceron *ensPuc, int ligne, int colonne, Case potager[ligne][colonne])
{
    for (int i = 0; i < n; i++)
    {
        Puceron puceron;

        int coordX = rand() % ligne;
        int coordY = rand() % colonne;
        while (potager[coordX][coordY].puceronCase != NULL)
        {
            coordX = rand() % ligne;
            coordY = rand() % colonne;

        }
        puceron = (struct Puceron){{coordX, coordY},0,0,genereDirection(),i};
        
        (*ensPuc).tab[i] = puceron;
        potager[(*ensPuc).tab[i].coordPuceron.x][(*ensPuc).tab[i].coordPuceron.y].puceronCase = &((*ensPuc).tab[i]);
        //printf("Puceron (%d,%d) : {(%d,%d),%d,%d,%d,%d} i=%d\n",coordX,coordY,potager[coordX][coordY].puceronCase->coordPuceron.x,potager[coordX][coordY].puceronCase->coordPuceron.y,potager[coordX][coordY].puceronCase->compteurReproduction,potager[coordX][coordY].puceronCase->compteurVie,potager[coordX][coordY].puceronCase->direction,potager[coordX][coordY].puceronCase->index,i);
    }
}
