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
	
	printf("Initialisation :\n");
	affichagePotager(LIGNE, COLONNE, potager);
	printf("Direction de p0 :");
	affichageInsecte(ensPuc.tab[0].direction);
	//printf("\nDirection de p1 :");
	//affichageInsecte(ensPuc.tab[1].direction);
	printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
	nbPucerons_Potager(LIGNE,COLONNE,potager);
	printf("\n");
	
	//On fait 2 tours :
	for(int i=1; i<21 ; i++){
		printf("Tour %d :\n",i);
		pousseTomatesPotager(LIGNE, COLONNE, potager);
		
		for(int j=0; j<ensPuc.nbPuceron; j++){
			deplacementPuceron(&(ensPuc.tab[j]), LIGNE, COLONNE, potager);
		}
		printf("Execution : deplacementPuceron x %d\n",ensPuc.nbPuceron);
		for(int j=0; j<ensPuc.nbPuceron; j++){
			int x = ensPuc.tab[j].coordPuceron.x;
			int y = ensPuc.tab[j].coordPuceron.y;
			
			mangeTomate(&(potager[x][y].tomateCase), potager[x][y].puceronCase);
			reproductionPuceron(potager[x][y].puceronCase,&ensPuc,LIGNE,COLONNE,potager);
			vieillissementPuceron(potager[x][y].puceronCase,&ensPuc,LIGNE,COLONNE,potager);
			if(potager[x][y].puceronCase!=NULL){
				reorientationPuceron(potager[x][y].puceronCase,LIGNE,COLONNE,potager);
			}
		}
		affichagePotager(LIGNE, COLONNE, potager);
		printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
		nbPucerons_Potager(LIGNE,COLONNE,potager);
		printf("\n");
	}


	
	
	return 0;
}
