#include "simulation.h"

int main()
{
	//Initialisation du temps pour la fonction random
	srand(time(NULL));

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

	//Initialisation de tous les pointeurs du potager sur NULL
	initialisationPotagerVide(LIGNE, COLONNE, pointeurPotager);

	//Initialisation de l'ensemble de pucerons (et ajout dans le potager)
	creerEnsemblePuceron(&ensPuc, NBPUCERON, LIGNE, COLONNE, pointeurPotager);

	//Remplissage du potager de tomates
	remplissagePotagerTomate(LIGNE, COLONNE, potager);

	/* for(int i=0; i<LIGNE; i++){
		for(int j=0; j<COLONNE; j++){
			printf("Adresse : %p\n",potager[i][j].puceronCase);
		}
	}
	printf("\n"); */

	//Affichage du potager initialisé
	printf("\033[1mInitialisation :\033[0m\n");
	affichagePotager(LIGNE, COLONNE, potager);
	
	//Affichage du nb de puceron dans le potager
	printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
	nbPucerons_Potager(LIGNE, COLONNE, potager);

/*
	printf("%p\n",pointeurPotager[0][0]);
	printf("%p\n",&(potager[0][0]));
	printf("%p\n",potager[0]);
	printf("%p\n\n",potager);

	int v = ensPuc.tab[0].coordPuceron.x;
	int w = ensPuc.tab[0].coordPuceron.y;
	printf("%p\n", pointeurPotager[v][w]);
	printf("%p\n",&(potager[v][w]));
	printf("%p\n", (*pointeurPotager[v][w]).puceronCase);
	printf("%p\n",potager[v][w].puceronCase);
	printf("%p\n\n",&(ensPuc.tab[0]));

	printf("%d\n",potager[v][w].puceronCase->compteurVie);
	ensPuc.tab[0].compteurVie = 3;
	printf("%d\n",potager[v][w].puceronCase->compteurVie);
	(*pointeurPotager[v][w]).puceronCase->compteurVie = 10;
	printf("%d\n",potager[v][w].puceronCase->compteurVie);

	printf("%p\n", &(potager[ensPuc.tab[0].coordPuceron.x][ensPuc.tab[0].coordPuceron.y].puceronCase));
	printf("%p\n", &(potager[ensPuc.tab[0].coordPuceron.x][ensPuc.tab[0].coordPuceron.y]));
	printf("%p\n", potager[ensPuc.tab[0].coordPuceron.x][ensPuc.tab[0].coordPuceron.y].puceronCase);
	printf("%p\n\n", &(ensPuc.tab[0]));

	printf("%p\n", &(potager[ensPuc.tab[1].coordPuceron.x][ensPuc.tab[1].coordPuceron.y].puceronCase));
	printf("%p\n", &(potager[ensPuc.tab[1].coordPuceron.x][ensPuc.tab[1].coordPuceron.y]));
	printf("%p\n", potager[ensPuc.tab[1].coordPuceron.x][ensPuc.tab[1].coordPuceron.y].puceronCase);
	printf("%p\n\n", &(ensPuc.tab[1]));
*/
	//Choix du nb de tours de la simulation :
	int nbTours = 0;
	printf("Saisir nombre de tours : ");
	scanf("%d",&nbTours);

	//Exécution des tours de la simulation
	int mortPuceron ;

	for (int i = 1; i < nbTours+1; i++)
	{
		printf("\033[1;34mTour %d :\033[0m\n", i);
		pousseTomatesPotager(LIGNE, COLONNE, potager);

		//Traitement des actions propre à chaque puceron
		for (int j = 0; j < ensPuc.nbPuceron; j++)
		{
			deplacementPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);
			//printf("le puceron %d s'est deplacé !\n", j);
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
				reorientationPuceron3(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);
			}
			else
			{
				printf("Le puceron %d est mort.\n",j);
				j = j - 1;
			}
		}

		affichagePotager(LIGNE, COLONNE, potager);
		// for(int i=0; i<ensPuc.nbPuceron; i++){
		// 	printf("Adresse : %p\n",&(ensPuc.tab[i]));
		// 	printf("Puceron {{%d,%d},%d,%d,%d,%d}\n\n",ensPuc.tab[i].coordPuceron.x,ensPuc.tab[i].coordPuceron.y,ensPuc.tab[i].compteurReproduction,ensPuc.tab[i].compteurVie,ensPuc.tab[i].direction,ensPuc.tab[i].index);
		// }
		printf("\n\033[1;31mNb puceron ensPuc  : %d\033[0m\n", ensPuc.nbPuceron);
		nbPucerons_Potager(LIGNE, COLONNE, potager);
	}

	return 0;
}
