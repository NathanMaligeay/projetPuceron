#include "simulation.h"

void affichage(int n, int p, Case potager[n][p]){
	printf("\n");
	for(int i=0; i<n; i++) {
	//Affichage de chaque ligne du potager
	
		for (int j=0; j<p; j++) {
		//Affichage de chaque case du potager
		
			//Affichage de la tomate en fonction de son état de croissance
			if ((*potager[i][j].tomateCase).etatCroissance < 5){
				printf(".");
			}else if ((*potager[i][j].tomateCase).etatCroissance < 20){
				printf("o");
			}else {
				printf("O");
			}
			
			//Affichage de l'éventuel puceron/coccinelle en fonction de sa direction
			if (potager[i][j].puceronCase != NULL){
				printf("\033[%sm","32"); //met la couleur du texte en vert dans une console linux
				printf(" %c",(*potager[i][j].puceronCase).direction);
				printf("\033[%sm","0"); //réinitialise le système de couleur de la console linux
				
			}else if (potager[i][j].coccinelleCase != NULL){
				printf("\033[%sm","31"); //met la couleur du texte en rouge
				printf(" %c",(*potager[i][j].coccinelleCase).direction);
				printf("\033[%sm","0"); //réinitialise le système de couleur
				
			}else{
				printf("  ");
			}
			
			//Affichage de la séparation entre chaque case du potager et retour à la ligne, si fin de ligne
			if (j!=p-1){
				printf("|");
			}else{
				printf("\n");
			}
		}
		
		//Affichage de la séparation entre chaque ligne du potager et retour à la ligne, si fin de ligne
		if (i!=n-1){
			for(int k=0; k<p-1; k++){
				printf("___|");
			}
			printf("___\n");
		}else{
			for(int k=0; k<p-1; k++){
				printf("   |");
			}
			printf("   \n");
		}
	}
	printf("\n");
}
