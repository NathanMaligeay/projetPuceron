#include "simulation.h"

void pousseTomate(Tomate* tomate){
	if ((*tomate).etatCroissance < 20) {
		(*tomate).etatCroissance ++ ;
	}
}

void mortTomate(Tomate* tomate){
	(*tomate).etatCroissance = 0;
}

void pousseTomatesPotager(int ligne, int colonne, Case potager[ligne][colonne]){
	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			pousseTomate(&(potager[i][j].tomateCase));
		}
	}
	printf("Execution : pousseTomatesPotager\n");
}

