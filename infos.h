#ifndef infos
#define infos

#include "structure.h"

//Fonctions pour récupérer infos sur nos objets
int nbPucerons_Potager(int ligne, int colonne, Case potager[ligne][colonne]);
int nbTomatesMures_Potager(int i, int j, Case potager[i][j]);
float ratioTomatesMures_Potager(int i, int j, Case potager[i][j]);

#endif
