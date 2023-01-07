#include "infos.h"

int nbPucerons_Potager(int ligne, int colonne, Case potager[ligne][colonne]){
	int nbP=0;
	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			if(potager[i][j].puceronCase != NULL){
				nbP++;
			}
		}
	}
	return nbP;
}

int nbTomatesMures_Potager(int i, int j, Case potager[i][j])
{
	int nb = 0;
	for(int x=0; x<i; x++){
		for(int y=0; y<j; y++){
			if (potager[x][y].tomateCase.etatCroissance == 20)
			{
				nb++ ;
			}
		}
	}
	return nb;
}

float ratioTomatesMures_Potager(int i, int j, Case potager[i][j]){
	float ratio = nbTomatesMures_Potager(i, j, potager);
	ratio = ratio/(i*j);
	return ratio;
}
