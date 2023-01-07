#ifndef coccinelle
#define coccinelle

#include "structure.h"
#include "puceron.h"

void mangePuceron(int coccinelleIndex, ensembleCoccinelle *ensCoc, int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p]);
void testMangePuceron(int coccinelleIndex, ensembleCoccinelle *ensCoc, int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p]);
int ajouteCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p]);
void reproductionCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p]);
void enleveCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p]);
int vieillissementCoccinelle(int coccinelleIndex, ensembleCoccinelle *ensCoc, int n, int p, Case potager[n][p]);
void presencePuceronRayon(int coccinelleIndex, ensembleCoccinelle ensCoc, int n, int p, Case potager[n][p]);


#endif
