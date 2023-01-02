#include "simulation.h"

/*int mangeTomate(Puceron puceron, int n, int p, Case Potager[n][p])
{
    /* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, si un
     puceron se trouve sur la même case 
    // factoriser si posssible
    if ((Potager[puceron.coordPuceron.x][puceron.coordPuceron.y]).tomateCase.etatCroissance > 4)
    {
        mortTomate((*Potager[puceron.coordPuceron.x][puceron.coordPuceron.y]).tomateCase);
        return 1; // renvoie 1 comme booléen
    }
    else
    {
        return 0;
    }
}; */ 

int mangeTomate(Tomate* tomate)
{
    /* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, et ne le modifie pas sinon */
    // factoriser si posssible
    if ((*tomate).etatCroissance > 4)
    {
        (*tomate).etatCroissance = 0;
        return 1; // renvoie 1 comme booléen
    }
    else
    {
        return 0;
    }
};

void reproductionPuceron(Puceron *puceron, int n, int p, Case potager[n][p], ensemblePuceron *ensPuc)
{
    if (mangeTomate(potager[(*puceron).coordPuceron.x][(*puceron).coordPuceron.y].tomateCase) == 1)
    { // fonction qui renvoie true ou false si une tomate "mangeable" est sur la meme case qu'un puceron
        (*puceron).compteurReproduction = (*puceron).compteurReproduction + 1;
        if ((*puceron).compteurReproduction == 5)
        {
            ajoutePuceron(*puceron, ensPuc);
        }
    }
    else
    {
        (*puceron).compteurReproduction = 0;
    }
};

void ajoutePuceron(Puceron puceron, ensemblePuceron *ensPuc)
{
    if ((*ensPuc).nbPuceron < 900)
    {
        (*ensPuc).tab[(*ensPuc).nbPuceron] = puceron;
    }
};

void vieillissementPuceron(Puceron *puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*puceron).compteurVie == 10)
    {
        enlevePuceron(*puceron, ensPuc, n, p, potager);
    }
    else
    {
        (*puceron).compteurVie = (*puceron).compteurVie + 1;
    }
};

void enlevePuceron(Puceron puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    (*ensPuc).tab[puceron.index] = (*ensPuc).tab[(*ensPuc).nbPuceron - 1]; // remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
    (*ensPuc).tab[puceron.index].index = puceron.index;                      // réattribue le bon index au puceron qui vient detre déplacé
    (*ensPuc).nbPuceron = (*ensPuc).nbPuceron - 1;                           // corrige le nombre de puceron total dans l'ensemble Puceron
    potager[puceron.coordPuceron.x][puceron.coordPuceron.y].puceronCase = NULL;
};

/* void directionPuceron(ensemblePuceron *ensPuc, Puceron *puceron)
{
    int dirPuc = (*ensPuc).tab[puceron.index].direction;
    if (dirPuc == 1)
    {
        (*ensPuc).tab[puceron.index].coordPuceron = {(*ensPuc).tab[puceron.index].coordPuceron.x-1,(*ensPuc).tab[puceron.index].coordPuceron.y-1}; //deplace le puceron en modifiant ses coordonnées dans l'ensemble puceron
        if (potager[puceron.coordPuceron.x-1][puceron.coordPuceron.y-1].tomateCase.etatCroissance < 4) //regarde si la tomate dans la direction du puceron est mangeable
        {
            (*ensPuc).tab[puceron.index].coordPuceron = {(*ensPuc).tab[puceron.index].coordPuceron.x,(*ensPuc).tab[puceron.index].coordPuceron.y+1};
        }
        else {

        }
    }
}; */
