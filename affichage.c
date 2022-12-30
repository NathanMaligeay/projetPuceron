#include "simulation.h"

void affichage(int n, int p, Case potager[n][p]){
	for(int i=0; i<n; i++) {
		for (int j=0; j<p; j++) {
			if ((*potager[i][j].tomateCase).etatCroissance < 5){
				printf(".");
			}else if ((*potager[i][j].tomateCase).etatCroissance < 20){
				printf("o");
			}else {
				printf("O");
			}
			
			if (potager[i][j].puceronCase != NULL){
				printf("%c ",(*potager[i][j].puceronCase).direction); //Attention pas sûre que ce soit comme ça pour afficher un caractère ! A vérifier...
			}else if (potager[i][j].coccinelleCase != NULL){
				printf("%c%c",(*potager[i][j].coccinelleCase).direction,(*potager[i][j].coccinelleCase).direction);
			}else{
				printf("  ");
			}
			
			if (j!=p-1){
				printf("|");
			}else{
				printf("\n");
			}
		}
		if (i!=n-1){
			for(int k=0; k<p-1; k++){
				printf("___");
			}
			printf("__\n");
		}
	}
}
