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
        ajoutePuceron(*puceron, ensPuc, n, p, potager);
        (*puceron).compteurReproduction = 0;
    }
};

void ajoutePuceron(Puceron puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*ensPuc).nbPuceron < 900)
    {
        Puceron nouveauPuceron;
        int n = puceron.coordPuceron.x;
        int p = puceron.coordPuceron.y;
        if ((potager[n - 1][p - 1].puceronCase == NULL) /*&& (potager[n - 1][p - 1].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p - 1};
        }
        else if ((potager[n - 1][p].puceronCase == NULL) /*&& (potager[n - 1][p].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p};
        }
        else if ((potager[n - 1][p + 1].puceronCase == NULL) /*&& (potager[n - 1][p + 1].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n - 1, p + 1};
        }
        else if ((potager[n][p - 1].puceronCase == NULL) /*&& (potager[n][p - 1].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n, p - 1};
        }
        else if ((potager[n][p + 1].puceronCase == NULL) /*&& (potager[n][p + 1].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n, p + 1};
        }
        else if ((potager[n + 1][p - 1].puceronCase == NULL) /*&& (potager[n + 1][p - 1].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p - 1};
        }
        else if ((potager[n + 1][p].puceronCase == NULL) /*&& (potager[n + 1][p].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p};
        }
        else if ((potager[n + 1][p + 1].puceronCase == NULL) /*&& (potager[n + 1][p + 1].coccinelleCase = NULL)*/)
        {
            nouveauPuceron.coordPuceron = (struct Coordonnees){n + 1, p + 1};
        }
        int nouvelleDirection = 0;
        while ((nouvelleDirection == 0) || (nouvelleDirection == 5))
        {
            nouvelleDirection = 1 + rand() % 9;
        }
        nouveauPuceron = (struct Puceron){nouveauPuceron.coordPuceron, 0, 0, nouvelleDirection, (*ensPuc).nbPuceron};
        (*ensPuc).tab[(*ensPuc).nbPuceron] = nouveauPuceron;
        (*ensPuc).nbPuceron = (*ensPuc).nbPuceron + 1;
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
    (*ensPuc).tab[puceron.index].index = puceron.index;                    // réattribue le bon index au puceron qui vient detre déplacé
    (*ensPuc).nbPuceron = (*ensPuc).nbPuceron - 1;                         // corrige le nombre de puceron total dans l'ensemble Puceron
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
