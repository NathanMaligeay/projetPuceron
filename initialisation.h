#ifndef initialisation
#define initialisation

#include "structure.h"
#include "puceron.h"

// Fonctions relatives à l'initialisation du potager (niveau 1)

void initialisationPotagerVide(int ligne, int colonne, Case *pointeurPotager[ligne][colonne]);
void creerEnsemblePuceron(ensemblePuceron *ensPuc, int n, int ligne, int colonne, Case *pointeurPotager[ligne][colonne]);
void remplissagePotagerTomate(int ligne, int colonne, Case potager[ligne][colonne]);
void apparitionPuceron(int n, ensemblePuceron *ensPuc, int ligne, int colonne, Case *pointeurPotager[ligne][colonne]);

#endif