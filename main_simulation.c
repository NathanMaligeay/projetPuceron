#include "simulation.h"

int main()
{
	srand(time(NULL));
	// printf("initialise rand\n");

	Case potager[LIGNE][COLONNE];
	// printf("crée le potager\n");

	initialisationPotagerVide(LIGNE, COLONNE, potager);
	// Initialise tous les pointeurs du potager sur NULL

	ensemblePuceron ensPuc = creerEnsemblePuceron(NBPUCERON, LIGNE, COLONNE, potager);
	// printf("crée l'ensemble de puceron et les ajoutes dans le potager\n");

	remplissagePotagerTomate(LIGNE, COLONNE, potager);
	// printf("remplis le potager de tomate\n");

	// lie le potager avec l'ensemble des pucerons
	// for (int i = 0; i < ensPuc.nbPuceron; i++)
	// {
	// 	potager[ensPuc.tab[i].coordPuceron.x][ensPuc.tab[i].coordPuceron.y].puceronCase = &(ensPuc.tab[i]);
	// }

	printf("Initialisation :\n");
	affichagePotager(LIGNE, COLONNE, potager);
	// printf("\nDirection de p1 :");
	// affichageInsecte(ensPuc.tab[1].direction);
	printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
	nbPucerons_Potager(LIGNE, COLONNE, potager);
	printf("\n");

	// On fait 6 tours :

	for (int i = 1; i < 7; i++)
	{
		printf("Tour %d :\n", i);
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
			reproductionPuceron(j, &ensPuc, LIGNE, COLONNE, potager);
			int mortPuceron = vieillissementPuceron(j, &ensPuc, LIGNE, COLONNE, potager);
			if (mortPuceron == 0)
			{
				reorientationPuceron2(j, &ensPuc, LIGNE, COLONNE, potager);
			}
			else
			{
				potager[x][y].puceronCase = NULL; // remet à NULL le pointeur de la case du puceron mort  // reverifier pq  ça ne fonctionne pas dans la fonction enlevePuceron
				j = j - 1;
			}
		}
		for (int i = 0; i < ensPuc.nbPuceron; i++)
		{
			potager[ensPuc.tab[i].coordPuceron.x][ensPuc.tab[i].coordPuceron.y].puceronCase = &(ensPuc.tab[i]); // voir si elle est nécessaire ?
		}
		affichagePotager(LIGNE, COLONNE, potager);
		for (int i = 0; i < ensPuc.nbPuceron; i++)
		{
			printf("Adresse : %p\n", &(ensPuc.tab[i]));
			printf("Puceron {{%d,%d},%d,%d,%d,%d}\n\n", ensPuc.tab[i].coordPuceron.x, ensPuc.tab[i].coordPuceron.y, ensPuc.tab[i].compteurReproduction, ensPuc.tab[i].compteurVie, ensPuc.tab[i].direction, ensPuc.tab[i].index);
		}
		printf("Nb puceron ensPuc  : %d\n\n", ensPuc.nbPuceron);

		nbPucerons_Potager(LIGNE, COLONNE, potager);
		printf("le pointeur de la case du dernier puceron de l'ensemble d'index %d est NULL %d\n",ensPuc.tab[ensPuc.nbPuceron-1].index, potager[ensPuc.tab[ensPuc.nbPuceron-1].coordPuceron.x][ensPuc.tab[ensPuc.nbPuceron-1].coordPuceron.y].puceronCase == NULL);
	}

	return 0;
}
