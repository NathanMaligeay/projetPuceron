#include "simulation.h"

int nbPucerons_Potager(int ligne, int colonne, Case potager[ligne][colonne]){
	int nbP=0;
	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			if(potager[i][j].puceronCase != NULL){
				nbP++;
			}
		}
	}
	printf("Nb pucerons dans le potager : %d\n\n", nbP);
	return nbP;
}
