#include "structure.h"
#include "tomate.h"
#include "affichage.h"
// #include "coccinelle.h"
#include "infos.h"
#include "initialisation.h"
#include "puceron.h"

int main()
{
	float moyNbPucerons = 0;
	int mortPuceron;

	// Déclaration du potager et de l'ensemble des pucerons
	Case potager[LIGNE][COLONNE];
	ensemblePuceron ensPuc;

	// Création d'un tableau de pointeurs vers les cases du tableau potager
	Case *pointeurPotager[LIGNE][COLONNE];

	for (int i = 0; i < LIGNE; i++)
	{
		for (int j = 0; j < COLONNE; j++)
		{
			pointeurPotager[i][j] = &(potager[i][j]);
		}
	}

	// Initialisation du temps pour la fonction random
	srand(time(NULL));

	// Choix du nb de simulations :
	int nbSimul;
	printf("Saisir nombre de simulations : ");
	scanf("%d", &nbSimul);

	// Choix du nb de tours de chaque simulation :
	int nbTours = 0;
	printf("Saisir nombre de tours : ");
	scanf("%d", &nbTours);

	for (int j = 1; j < nbSimul + 1; j++)
	{
		// Initialisation de tous les pointeurs du potager sur NULL
		initialisationPotagerVide(LIGNE, COLONNE, pointeurPotager);

		// Initialisation de l'ensemble de pucerons (et ajout dans le potager)
		creerEnsemblePuceron(&ensPuc, NBPUCERON, LIGNE, COLONNE, pointeurPotager);

		// Remplissage du potager de tomates
		remplissagePotagerTomate(LIGNE, COLONNE, potager);

		// Exécution des tours de la simulation
		for (int i = 1; i < nbTours + 1; i++)
		{
			// printf("\033[1;34mTour %d :\033[0m\n", i);
			pousseTomatesPotager(LIGNE, COLONNE, potager);

			// Traitement des actions propre à chaque puceron
			for (int j = 0; j < ensPuc.nbPuceron; j++)
			{
				deplacementPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);
			}
			for (int j = 0; j < ensPuc.nbPuceron; j++)
			{
				int x = ensPuc.tab[j].coordPuceron.x;
				int y = ensPuc.tab[j].coordPuceron.y;

				mangeTomate(&(potager[x][y].tomateCase), j, &ensPuc);
				reproductionPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager);				  // ne plus cibler le potager
				mortPuceron = vieillissementPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager); // ne plus cibler le potager
				if (mortPuceron == 0)
				{
					reorientationPuceron(j, &ensPuc, LIGNE, COLONNE, pointeurPotager); // ne plus cibler le potager
				}
				else
				{
					j = j - 1;
				}
			}
			// affichagePotager(LIGNE, COLONNE, potager);
			// printf("\nNb puceron ensPuc  : %d\n", ensPuc.nbPuceron);
		}
		moyNbPucerons += nbPucerons_Potager(LIGNE, COLONNE, potager);
	}
	moyNbPucerons = moyNbPucerons / nbSimul;
	printf("\nNb de simulations : %d\nNb moyen de pucerons après %d tours : %f\n", nbSimul, nbTours, moyNbPucerons);
	return 0;
}
