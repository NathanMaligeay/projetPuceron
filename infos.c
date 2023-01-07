#include "simulation.h"

int nbPucerons_Potager(int ligne, int colonne, Case potager[ligne][colonne])
{
	int nbP = 0;
	for (int i = 0; i < ligne; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			if (potager[i][j].puceronCase != NULL)
			{
				nbP++;
				printf("Adresse : %p\n", potager[i][j].puceronCase);
				printf("Puceron {{%d,%d},%d,%d,%d,%d}\n\n", potager[i][j].puceronCase->coordPuceron.x, potager[i][j].puceronCase->coordPuceron.y, potager[i][j].puceronCase->compteurReproduction, potager[i][j].puceronCase->compteurVie, potager[i][j].puceronCase->direction, potager[i][j].puceronCase->index);
			}
		}
	}
	printf("Nb puceron potager : %d\n", nbP);
	return nbP;
}
