#include "simulation.h"

int main()
{
	float moyNbPucerons = 0;
	float moyRatioTomatesMures = 0;
	float moyNbTours = 0;
	int mortPuceron ;

	//Déclaration du potager et de l'ensemble des pucerons
	Case potager[LIGNE][COLONNE];
	ensemblePuceron ensPuc;

	//Création d'un tableau de pointeurs vers les cases du tableau potager
	Case* pointeurPotager[LIGNE][COLONNE];

	for(int i=0; i<LIGNE; i++){
		for(int j=0; j<COLONNE; j++){
			pointeurPotager[i][j]=&(potager[i][j]);
		}
	}

	//Initialisation du temps pour la fonction random
	srand(time(NULL));
	
	//Choix du nb de simulations :
	int nbSimul ;
	printf("Saisir nombre de simulations : ");
	scanf("%d",&nbSimul);

	for (int j = 1; j < nbSimul+1; j++){

		//Initialisation du compteur de tours de la simulation :
		int nbTours = 0;

		//Initialisation de tous les pointeurs du potager sur NULL
		initialisationPotagerVide(LIGNE, COLONNE, pointeurPotager);

		//Initialisation de l'ensemble de pucerons (et ajout dans le potager)
		creerEnsemblePuceron(&ensPuc, NBPUCERON, LIGNE, COLONNE, pointeurPotager);

		//Remplissage du potager de tomates
		remplissagePotagerTomate(LIGNE, COLONNE, potager);

		//Affichage du potager initialisé
		printf("\033[1mInitialisation :\033[0m\n");
		affichagePotager(LIGNE, COLONNE, potager);

		//Exécution des tours de la simulation	
		while((ratioTomatesMures_Potager(LIGNE,COLONNE,potager)>0.25)&&(nbPucerons_Potager(LIGNE,COLONNE,potager)!=0))
		{
			//printf("\033[1;34mTour %d :\033[0m\n", i);
			pousseTomatesPotager(LIGNE, COLONNE, potager);
			for (int j = 0; j < ensPuc.nbPuceron; j++)
			{
				deplacementPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);
			}
			for (int j = 0; j < ensPuc.nbPuceron; j++)
			{
				int x = ensPuc.tab[j].coordPuceron.x;
				int y = ensPuc.tab[j].coordPuceron.y;

				mangeTomate(&(potager[x][y].tomateCase), j, &ensPuc);
				reproductionPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);				 
				mortPuceron = vieillissementPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);
				if (mortPuceron == 0)
				{
					reorientationPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);
				}
				else
				{
					j = j - 1;
				}
			}
			nbTours++ ;
		}
		moyNbPucerons += nbPucerons_Potager(LIGNE, COLONNE, potager);
		moyRatioTomatesMures += ratioTomatesMures_Potager(LIGNE,COLONNE,potager);
		moyNbTours += nbTours;
	}
	moyNbPucerons = moyNbPucerons/nbSimul;
	moyRatioTomatesMures = moyRatioTomatesMures/nbSimul;
	moyNbTours = moyNbTours/nbSimul;
	printf("\nNb de pucerons moyen : %f\nRatio de tomates moyen: %f\nNb de tours moyen: %f\n",moyNbPucerons,moyRatioTomatesMures,moyNbTours);
	return 0;
}