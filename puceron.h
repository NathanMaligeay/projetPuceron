#ifndef puceron
#define puceron

#include "structure.h"

// Fonctions relatives aux pucerons

void mangeTomate(Tomate *tomate, int puceronIndex, ensemblePuceron *ensPuc);
/*Prend en entrée un pointeur sur un objet de type Tomate et un pointeur sur un objet de type Puceron et met à jour l'état de la tomate et le compteur de reproduction du Puceron si celui-ci mange la tomate.*/
/* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, et ne le modifie pas sinon , et met à jour le compteur de reproduction du puceron en conséquence.*/

void reproductionPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case *pointeurPotager[n][p]);

void testBordure(int i, int j, int n, int p, Case *pointeurPotager[n][p], Coordonnees *coord, int *flag);

int genereDirection();

int ajoutePuceron(int puceronIndex, ensemblePuceron *ensPuc, int ligne, int colonne, Case *pointeurPotager[ligne][colonne]);

int vieillissementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case *pointeurPotager[n][p]);

void enlevePuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case *pointeurPotager[n][p]);

void traduction_DirectionCoordonnees(int dir, int *n, int *p);
/**/

int presenceTomateMangeableDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int n, int p, Case *pointeurPotager[n][p]);
/*Teste la présence d'une tomate "mangeable" dans une direction donnée, en prenant comme point d'origine un autre puceron. Si une tomate "non-mangeable" est présente sur cette case, ou que la direction indiquée est en-dehors du potager, retourne 0, sinon retourne 1.*/

int presenceInsecteDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int n, int p, Case *pointeurPotager[n][p]);
/*Teste la présence d'un insecte dans une direction donnée, en prenant comme point d'origine un puceron. Si un insecte est présent sur cette case, ou que la direction indiquée est en-dehors du potager, retourne 0, sinon retourne 1.*/

void reorientationPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case *pointeurPotager[n][p]);
/*Prend en entrée un pointeur sur un objet de type Puceron et adapte la direction de celui-ci en fonction des tomates présentes dans l'environnement direct de celui-ci (=les cases attenantes à la case dans laquelle se trouve le puceron). La direction reste inchangée si une tomate "mangeable" se trouve dans la case attenante indiquée par cette direction et qu'il n'y a pas d'insecte sur cette case, ou bien si le puceron ne peut se déplacer sur aucune des cases qui l'entourent. Si il n'y a pas de tomate mangeable dans cette direction (ou qu'il y a un insecte sur cette case) alors cette fonction donne la direction indiquant la prochaine case attenante avec tomate mangeable et absence d'insecte. Si il n'y en a pas, la fonction donne la direction indiquant la prochaine case attenante avec absence d'insecte. */

void deplacementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case *pointeurPotager[n][p]);
/*Prend en entrée un pointeur sur un objet de type Puceron, met à jour la direction de celui-ci, puis modifie sa position.*/

#endif
