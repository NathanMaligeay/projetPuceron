#include "simulation.h"

void mangePuceron(int coccinelleIndex, ensembleCoccinelle *ensCoc, int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    enlevePuceron(puceronIndex, *ensPuc, n, p, potager);
    (*ensCoc).tab[coccinelleIndex].compteurReproduction++;
}

void testMangePuceron(int coccinelleIndex, ensembleCoccinelle *ensCoc, int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    int x = (*ensCoc).tab[coccinelleIndex].coordCoccinelle.x;
    int y = (*ensCoc).tab[coccinelleIndex].coordCoccinelle.y;

    if (potager[x][y].puceronCase != NULL)
    {
        int indexPuceronMange = (*potager[x][y].puceronCase).index;
        mangePuceron(coccinelleIndex, *ensCoc, indexPuceronMange, *ensPuc, LIGNE, COLONNE, potager);
    }
    else
    {
        (*ensCoc).tab[coccinelleIndex].compteurReproduction = 0;
    }
}

// possible de factoriser les deux fonctions si je peux passer un type indéfini a ensInsecte;
// int ajouteInsecte(int insecteIndex, ensembleInsecte *ensIns, int n, int p, Case potager[n][p])
int ajouteCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p])
{
    Coordonnees nouvelleCoord;
    int flag = 0;
    if ((*ensCoc).nbCoccinelle < LIGNE * COLONNE)
    {
        Coccinelle nouvelleCoccinelle;
        int n = (*ensCoc).tab[coccinelleIndex].coordCoccinelle.x;
        int p = (*ensCoc).tab[coccinelleIndex].coordCoccinelle.y;
        testBordure2(n, p, 30, 30, potager, &nouvelleCoord, &flag);
        if (flag == 1)
        {
            nouvelleCoccinelle = (struct Coccinelle){nouvelleCoord, 0, 0};
            (*ensCoc).tab[(*ensCoc).nbCoccinelle] = nouvelleCoccinelle; // insère le nouveau puceron dans l'ensemble
            (*ensCoc).nbCoccinelle = (*ensCoc).nbCoccinelle + 1;        // incrémente de 1 le compteur de puceron de l'ensemble
            potager[nouvelleCoccinelle.coordCoccinelle.x][nouvelleCoccinelle.coordCoccinelle.y].coccinelleCase = &(*ensCoc).tab[(*ensCoc).nbCoccinelle];
        }
    }
}

void reproductionPuceron(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p])
{
    if ((*ensCoc).tab[coccinelleIndex].compteurReproduction == 3)
    {
        int result = ajouteCoccinelle(coccinelleIndex, ensCoc, n, p, potager);
        if (result == 1)
        {
            (*ensCoc).tab[coccinelleIndex].compteurReproduction = 0;
        }
    }
}

void enleveCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p])
{
    potager[(*ensCoc).tab[(*ensCoc).nbCoccinelle - 1].coordCoccinelle.x][(*ensCoc).tab[(*ensCoc).nbCoccinelle - 1].coordCoccinelle.y].coccinelleCase = &((*ensCoc).tab[coccinelleIndex]);
    (*ensCoc).tab[coccinelleIndex] = (*ensCoc).tab[(*ensCoc).nbCoccinelle - 1];                                                        // remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
    (*ensCoc).tab[coccinelleIndex].index = coccinelleIndex;                                                                            // réattribue le bon index au puceron qui vient detre déplacé
    (*ensCoc).nbCoccinelle = (*ensCoc).nbCoccinelle - 1;                                                                               // corrige le nombre de puceron total dans l'ensemble Puceron
    potager[(*ensCoc).tab[coccinelleIndex].coordCoccinelle.x][(*ensCoc).tab[coccinelleIndex].coordCoccinelle.y].coccinelleCase = NULL; // remet à NULL le pointeur de la case du puceron mort
}

int vieillissementCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p])
{
    if ((*ensCoc).tab[coccinelleIndex].compteurVie == 20)
    {
        enleveCoccinelle(coccinelleIndex, ensCoc, n, p, potager);
        return 1;
    }
    else
    {
        (*ensCoc).tab[coccinelleIndex].compteurVie++;
        return 0;
    }
}

void presencePuceronRayon(int coccinelleIndex, ensembleCoccinelle ensCoc, int n, int p, Case potager[n][p])
{
    int x = ensCoc.tab[coccinelleIndex].coordCoccinelle.x;
    int y = ensCoc.tab[coccinelleIndex].coordCoccinelle.y;

    for (int rayon = 1; rayon < 4; rayon++)
    {
        
    }
}

void deplacementCoccinelle(Coccinelle *coccinelle)
{
}