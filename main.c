#include "simulation.h"

int main()
{
	srand( time( NULL ) );

	Case potager[30][30];

	Puceron tab[900];


	Tomate t1 = {{0, 0}, 6}; //6 est le stade de pousse du tomate
	Tomate t2 = {{0,1},2};
	Puceron p1 = {{0,0}, 5, 8, 1, 0}; //5 est compteur reproduction, 8 de vie
	Puceron p2 = {{0,1}, 2, 10, 1, 1};


	tab[0] = p1; 
	tab[1] = p2;

	ensemblePuceron ensPuc;
	ensPuc.tab[0] = tab[0];
	ensPuc.tab[1] = tab[1];
	ensPuc.nbPuceron = 2;

	potager[0][0].puceronCase = &p1;
	potager[0][0].tomateCase = &t1;
	potager[0][1].puceronCase = &p2;
	potager[0][1].tomateCase = &t2;

	printf(" vie puceron qui va vieillir %d\n", ensPuc.tab[0].compteurVie);
	printf("nb puceron dans l'ensemble %d\n", ensPuc.nbPuceron);


	vieillissementPuceron((&ensPuc.tab[0]), &ensPuc, 30,30,potager);

	printf("vie puceron qui a vieilli %d\n", ensPuc.tab[0].compteurVie);	
	printf("nb puceron dans ensemble %d\n", ensPuc.nbPuceron);


	return 0;
}
