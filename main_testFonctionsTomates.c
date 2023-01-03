#include "simulation.h"

int main() {
	Tomate tomate1 = {{0,0},4};
	Tomate tomate2 = {{0,1},0};
	Tomate tomate3 = {{0,3},20};
	
	pousseTomate(&tomate1);
	printf("Etat croissance tomate1 : %d \n",tomate1.etatCroissance);
	
	pousseTomate(&tomate2);
	printf("Etat croissance tomate2 : %d \n",tomate2.etatCroissance);
	
	pousseTomate(&tomate3);
	printf("Etat croissance tomate3 : %d \n",tomate3.etatCroissance);
	
	mortTomate(&tomate1);
	printf("-Mort tomate1- \nEtat croissance tomate1 : %d \n",tomate1.etatCroissance);
	return 0;
}


