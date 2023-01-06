#include "simulation.h"

int main()
{
	//Initialisation du temps pour la fonction random
	srand(time(NULL));

	//Création du potager
	Case potager[LIGNE][COLONNE];

	//Initialisation de tous les pointeurs du potager sur NULL
	initialisationPotagerVide(LIGNE, COLONNE, potager);

	//Création de l'ensemble de pucerons (et ajout dans le potager)
	ensemblePuceron ensPuc = creerEnsemblePuceron(NBPUCERON, LIGNE, COLONNE, potager);

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
	nbPucerons_Potager(LIGNE, COLONNE, potager);

	//Choix du nb de tours de la simulation :
	int nbTours = 0;
	printf("Saisir nombre de tours : ");
	scanf("%d",&nbTours);

	//Exécution des tours de la simulation
	int mortPuceron = 0;

	for (int i = 1; i < nbTours+1; i++)
	{
		printf("\033[1;34mTour %d :\033[0m\n", i);
		pousseTomatesPotager(LIGNE, COLONNE, potager);
		for (int j = 0; j < ensPuc.nbPuceron; j++)
		{
			deplacementPuceron(j, &ensPuc, LIGNE, COLONNE, potager);
			//printf("le puceron %d s'est deplacé !\n", j);
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
		affichagePotager(LIGNE, COLONNE, potager);
		//printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
		nbPucerons_Potager(LIGNE, COLONNE, potager);
	}

	return 0;
}
