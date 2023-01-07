#ifndef tomate
#define tomate

#include "structure.h"

// Fonctions relatives aux tomates
void pousseTomate(Tomate *tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met à jour l'état de croissance de cette tomate. Si l'état est compris entre 0 et 4, alors ajoute +1 à celui-ci. Sinon ne fait rien.*/

void pousseTomatesPotager(int ligne, int colonne, Case potager[ligne][colonne]);
/*Fais pousser toutes les tomates du potager.*/

void mortTomate(Tomate *tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met son état de croissance à 0.*/

#endif
