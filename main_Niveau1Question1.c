#include "simulation.h"

int main()
{
	float moyNbPucerons = 0;
	float moyRatioTomatesMures = 0;
	float moyNbTours = 0;
	int mortPuceron ;

	//Choix du nb de simulations :
	int nbSimul ;
	printf("Saisir nombre de simulations : ");
	scanf("%d",&nbSimul);

	//Déclaration du potager et de l'ensemble des pucerons
	Case potager[LIGNE][COLONNE];
	ensemblePuceron ensPuc;

	//Initialisation du temps pour la fonction random
	srand(time(NULL));
	
	for (int j = 1; j < nbSimul+1; j++){

		//Initialisation du compteur de tours de la simulation :
		int nbTours = 0;

		//Initialisation de tous les pointeurs du potager sur NULL
		initialisationPotagerVide(LIGNE, COLONNE, potager);

		//Initialisation de l'ensemble de pucerons (et ajout dans le potager)
		ensPuc = creerEnsemblePuceron(NBPUCERON, LIGNE, COLONNE, potager);

		//Remplissage du potager de tomates
		remplissagePotagerTomate(LIGNE, COLONNE, potager);

		//Liaison du potager avec l'ensemble des pucerons
		for (int i = 0; i < ensPuc.nbPuceron; i++)
		{
			potager[ensPuc.tab[i].coordPuceron.x][ensPuc.tab[i].coordPuceron.y].puceronCase = &(ensPuc.tab[i]);
		}

		//Affichage du potager initialisé
		printf("\033[1mInitialisation :\033[0m\n");
		affichagePotager(LIGNE, COLONNE, potager);
		
		//Affichage du nb de puceron dans le potager
		//printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
		//nbPucerons_Potager(LIGNE, COLONNE, potager);

		//Exécution des tours de la simulation	
		while((ratioTomatesMures_Potager(LIGNE,COLONNE,potager)>0.25)&&(nbPucerons_Potager(LIGNE,COLONNE,potager)!=0))
		{
			//printf("\033[1;34mTour %d :\033[0m\n", i);
			pousseTomatesPotager(LIGNE, COLONNE, potager);
			for (int j = 0; j < ensPuc.nbPuceron; j++)
			{
				deplacementPuceron(j, &ensPuc, LIGNE, COLONNE, potager);
			}
			for (int j = 0; j < ensPuc.nbPuceron; j++)
			{
				int x = ensPuc.tab[j].coordPuceron.x;
				int y = ensPuc.tab[j].coordPuceron.y;

				mangeTomate(&(potager[x][y].tomateCase), j, &ensPuc);
				reproductionPuceron(j, &ensPuc, LIGNE, COLONNE, potager);				  // ne plus cibler le potager
				mortPuceron = vieillissementPuceron(j, &ensPuc, LIGNE, COLONNE, potager); // ne plus cibler le potager
				if (mortPuceron == 0)
				{
					reorientationPuceron(j, &ensPuc, LIGNE, COLONNE, potager); // ne plus cibler le potager
				}
				else
				{
					potager[x][y].puceronCase = NULL; // remet à NULL le pointeur de la case du puceron mort reverifier pq  ça ne fonctionne pas dans la fonction enlevePuceron
					j = j - 1;
				}
			}
			for (int i = 0; i < ensPuc.nbPuceron; i++)
			{
				potager[ensPuc.tab[i].coordPuceron.x][ensPuc.tab[i].coordPuceron.y].puceronCase = &(ensPuc.tab[i]); //voir si elle est nécessaire ?
			}
			//affichagePotager(LIGNE, COLONNE, potager);
			//printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
			nbTours++ ;
		}
		moyNbPucerons += nbPucerons_Potager(LIGNE, COLONNE, potager);
		moyRatioTomatesMures += ratioTomatesMures_Potager(LIGNE,COLONNE,potager);
		moyNbTours += nbTours;
	}
	moyNbPucerons = moyNbPucerons/nbSimul;
	moyRatioTomatesMures = moyRatioTomatesMures/nbSimul;
	moyNbTours = moyNbTours/nbSimul;
	printf("\nNb de pucerons moyen : %d\nRatio de tomates moyen: %f\nNb de Tours moyen: %d\n",moyNbPucerons,moyRatioTomatesMures,moyNbTours);
	return 0;
}