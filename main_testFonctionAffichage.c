#include "simulation.h"



int main() {
	Tomate t0 = {{0,0},20};
	Tomate t1 = {{0,0},0};
	Tomate t2 = {{0,0},5};
	Puceron p0 = {{0,0},3,6,3};
	Coccinelle c0 = {{0,0},2,8,1};
	
	Case case0 = {t1, &p0, NULL};
	Case case1 = {t0, NULL, &c0};
	Case case2 = {t2, NULL, NULL};
	//printf("\nDirection de puceron0 : %c%c\n\n",p0.direction,(*case0.puceronCase).direction);
	
	Case petitPotager[3][3];
	petitPotager[0][0] = case0;
	petitPotager[0][1] = case1;
	petitPotager[0][2] = case2;
	petitPotager[1][0] = case1;
	petitPotager[1][1] = case0;
	petitPotager[1][2] = case1;
	petitPotager[2][0] = case1;
	petitPotager[2][1] = case1;
	petitPotager[2][2] = case2;
	
	
	//affichagePotager(3,3,petitPotager);
	
	Case potager[30][30];
	Tomate t = {{0,0},20};
	Case caseP = {t,NULL,NULL};
	
	for(int i=0; i<30; i++){
		for(int j=0; j<30; j++){
			t.coordTomates.x = i;
			t.coordTomates.y = j;
			caseP.tomateCase = t;
			caseP.puceronCase = &p0;
			potager[i][j] = caseP;
			//printf("i=%d , j=%d , coordTomate.x=%d , coordTomate.y=%d\n",i,j,potager[i][j].tomateCase.coordTomates.x,potager[i][j].tomateCase.coordTomates.y);
		}
	}
	affichagePotager(30,30,potager);
	//printf("Coordonnées de la tomate 1,1 : [%d][%d]\n",potager[0][0].tomateCase.coordTomates.x,potager[1][1].tomateCase.coordTomates.y);
	return 0;
}


