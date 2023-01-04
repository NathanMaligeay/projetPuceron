#include "simulation.h"

int main(){
	srand( time( NULL ) );
	//printf("initialise rand\n");
	
	Case potager[LIGNE][COLONNE];
	//printf("crée le potager\n");
	
	initialisationPotagerVide(LIGNE, COLONNE, potager);
	//Initialise tous les pointeurs du potager sur NULL

	ensemblePuceron ensPuc = creerEnsemblePuceron(NBPUCERON , LIGNE, COLONNE, potager);
	//printf("crée l'ensemble de puceron et les ajoutes dans le potager\n");
	
	remplissagePotagerTomate(LIGNE, COLONNE, potager);
	//printf("remplis le potager de tomate\n");
	
	//On fait 2 tours :
	/*for(int i=0; i<NBPUCERON ; i++){
		int x = ensPuc.tab[i].coordPuceron.x;
		int y = ensPuc.tab[i].coordPuceron.y;
		printf("Coordonnee puceron %d : %d %d\n", i, x, y);
		//printf("
		printf("Présence puceron : %d\n\n", potager[x][y].puceronCase != NULL);
	}*/

	printf("Nb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
	nbPucerons_Potager(LIGNE,COLONNE,potager);
	
	affichagePotager(LIGNE, COLONNE, potager);
	
	return 0;
}
