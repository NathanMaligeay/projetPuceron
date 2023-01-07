#include "simulation.h"

int nbPucerons_Potager(int ligne, int colonne, Case potager[ligne][colonne]){
	int nbP=0;
	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			if(potager[i][j].puceronCase != NULL){
				nbP++;
				// printf("Adresse : %p\n", potager[i][j].puceronCase);
				// printf("Case (%d,%d)\n",i,j);
				// printf("Puceron {{%d,%d},%d,%d,%d,%d}\n\n",potager[i][j].puceronCase->coordPuceron.x,potager[i][j].puceronCase->coordPuceron.y,potager[i][j].puceronCase->compteurReproduction,potager[i][j].puceronCase->compteurVie,potager[i][j].puceronCase->direction,potager[i][j].puceronCase->index);			
			}
		}
	}
	printf("\033[1;31mNb pucerons potager : %d\033[0m\n\n", nbP);
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
