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
	
	//Test fonction déplacement
	Case miniPotager[2][2];

	Tomate t00 = {{0,0},2};
	Tomate t01 = {{0,1},2};
	Tomate t10 = {{1,0},8};
	Tomate t11 = {{1,1},5};
	
	Puceron p00 = {{0,0},3,8,6,1};
	
	//Puceron p01 = {{0,1},3,8,1,1};
	//Puceron p10 = {{1,0},3,8,1,1};
	
	Puceron p11 = {{1,1},3,8,4,1};

	miniPotager[0][0] = (struct Case){&t00,&p00};
	miniPotager[0][1] = (struct Case){&t01,NULL};
	miniPotager[1][0] = (struct Case){&t10,NULL};
	miniPotager[1][1] = (struct Case){&t11,&p11};
	
	printf("Valeur croissance t11 : %d\n",miniPotager[1][1].tomateCase->etatCroissance);

	printf("%d\n",presenceTomateMangeableDirection(p00, p00.direction, 2, 2, miniPotager));
	printf("%d\n",presenceTomateMangeableDirection(p11, p11.direction, 2, 2, miniPotager));
	printf("1 : %d\n",presenceInsecteDirection(p11, 1, 2, 2, miniPotager));
	printf("0 : %d\n",presenceInsecteDirection(p11, 4, 2, 2, miniPotager));
	printf("1 : %d\n",presenceInsecteDirection(p11, 8, 2, 2, miniPotager));
	printf("0 : %d\n",presenceInsecteDirection(p00, 6, 2, 2, miniPotager));
	printf("1 : %d\n",presenceInsecteDirection(p00, 1, 2, 2, miniPotager));
	printf("1 : %d\n",presenceInsecteDirection(p00, p00.direction, 2, 2, miniPotager));
	
	/*printf("Ancienne direction de p00 : %d\n",p00.direction);
	directionPuceron(&p00, 2, 2, miniPotager);
	printf("Nouvelle direction de p00 : %d\n",p00.direction);*/
	
	deplacementPuceron(&p00, 2, 2, miniPotager);
	printf("%d\n",miniPotager[0][0].puceronCase==NULL);
	deplacementPuceron(&p11, 2, 2, miniPotager);

	return 0;
}
