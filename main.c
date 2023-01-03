#include "simulation.h"

int main()
{
	srand( time( NULL ) );

	Case potager[30][30];

	Puceron tab[900];


	Tomate t1 = {{0, 0}, 6}; //6 est le stade de pousse du tomate
	Puceron p1 = {{0, 0}, 5, 8, 1, 1}; //5 est compteur reproduction, 8 de vie

	tab[0] = p1; 


	ensemblePuceron ensPuc;
	ensPuc.tab[0] = tab[0];
	ensPuc.nbPuceron = 1;
	printf("compteur vie puceron %d\n", ensPuc.tab[0].compteurVie);	

	potager[0][0].puceronCase = &p1;
	potager[0][0].tomateCase = &t1;

	printf("compteur repro %d\n", p1.compteurReproduction);
	printf("nb puceron %d\n",ensPuc.nbPuceron);
	printf("direction du vieux puceron %d\n", ensPuc.tab[0].direction);
	reproductionPuceron(&p1, &ensPuc, 30, 30, potager);
	printf("compteur repro %d\n", p1.compteurReproduction);
	printf("nb puceron %d\n",ensPuc.nbPuceron);
	printf("direction du nv puceron %d\n", ensPuc.tab[1].direction);
	printf("direction du vieux puceron %d\n", ensPuc.tab[0].direction);


	return 0;
}
