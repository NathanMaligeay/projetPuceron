#include "tomate.h"

void pousseTomate(Tomate *tomateCible)
{
	if ((*tomateCible).etatCroissance < 20)
	{
		(*tomateCible).etatCroissance++;
	}
}

void mortTomate(Tomate *tomateCible)
{
	(*tomateCible).etatCroissance = 0;
}

void pousseTomatesPotager(int ligne, int colonne, Case potager[ligne][colonne])
{
	for (int i = 0; i < ligne; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			pousseTomate(&(potager[i][j].tomateCase));
		}
	}
}
