#include "simulation.h"


int main() {

	Case potager[30][30];

	Puceron tab[900];

	Tomate t1 = {{0,0},4};
	Puceron p1 = {{0,0},3,8,1,1};

	ensemblePuceron ensPuc = {tab, 1};
	

	potager[0][0].puceronCase = &p1 ;
	potager[0][0].tomateCase = &t1 ;

	

}


