#include <stdio.h>



int main() {
	for(int i=0; i<29; i++) {
		for (int j=0; j<30; j++) {
			if(j!=29){
				printf("_O|");
			}
			else{
				printf("_O");
			}
		}
		printf("\n");
	}
	for (int j=0; j<30; j++) {
		if(j!=29){
			printf(" O|");
		}
		else{
			printf(" O");
		}
	} 
	printf("\n");
}


