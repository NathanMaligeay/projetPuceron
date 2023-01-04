#include "simulation.h"

ensemblePuceron creerEnsemblePuceron(int n, int ligne, int colonne, Case potager[ligne][colonne])
{
    Puceron tab[LIGNE * COLONNE];
    ensemblePuceron ensPuc;
    apparitionPuceron(n, &ensPuc, ligne, colonne, potager, tab);
    ensPuc.nbPuceron = n;
    return ensPuc;
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

void apparitionPuceron(int n, ensemblePuceron *ensPuc, int ligne, int colonne, Case potager[ligne][colonne], Puceron tab[ligne * colonne])
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
        puceron = (struct Puceron){
            {coordX, coordY},
            0,
            0,
            genereDirection(),
            i};
        (*ensPuc).tab[i] = puceron;
        potager[coordX][coordY].puceronCase = &(*ensPuc).tab[i];
    }
}
