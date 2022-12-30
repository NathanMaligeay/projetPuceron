#include "simulation.h"



int main() {
	Case potager[30][30];
	for(int i=0; i<30; i++){
		for(int j=0; j<30; j++){
			//(*potager[i][j].tomateCase) = {{i,j},20};
			(*potager[i][j].tomateCase).coordTomates.x = i;
			(*potager[i][j].tomateCase).coordTomates.y = j;
			(*potager[i][j].tomateCase).etatCroissance = 20;
			potager[i][j].puceronCase = NULL;
			potager[i][j].coccinelleCase =NULL;
		}
	}
	/*affichage(30,30,potager);
	printf("\n");*/
	return 0;
}


