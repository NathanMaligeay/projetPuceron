#include "simulation.h"

void pousseTomate(Tomate* tomate){
	if ((*tomate).etatCroissance < 20) {
		(*tomate).etatCroissance ++ ;
	}
}

void mortTomate(Tomate* tomate){
	(*tomate).etatCroissance = 0;
}

