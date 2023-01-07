#ifndef simulation
#define simulation

#define LIGNE 10
#define COLONNE 10
#define NBPUCERON 5


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Définitions des structures:
typedef struct Coordonnees
{
    int x;
    int y;
} Coordonnees;

typedef struct Tomate
{
    Coordonnees coordTomates;
    int etatCroissance;
} Tomate;

typedef struct Coccinelle
{
    Coordonnees coordCoccinelle;
    int compteurReproduction;
    int compteurVie;
    int direction;
} Coccinelle;


typedef struct Puceron
{
    Coordonnees coordPuceron;
    int compteurReproduction;
    int compteurVie;
    int direction;
    int index;
} Puceron;

typedef struct ensemblePuceron
{
    Puceron tab[LIGNE*COLONNE];
    int nbPuceron;
} ensemblePuceron;


typedef struct Case
{
    Tomate tomateCase;
    Puceron *puceronCase;
    Coccinelle *coccinelleCase;
} Case;

// Fonctions relatives aux tomates
void pousseTomate(Tomate *tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met à jour l'état de croissance de cette tomate. Si l'état est compris entre 0 et 4, alors ajoute +1 à celui-ci. Sinon ne fait rien.*/

void pousseTomatesPotager(int ligne, int colonne, Case potager[ligne][colonne]);
/*Fais pousser toutes les tomates du potager.*/

void mortTomate(Tomate *tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met son état de croissance à 0.*/

// Fonctions relatives aux pucerons

void mangeTomate(Tomate *tomate, int puceronIndex, ensemblePuceron *ensPuc);
/*Prend en entrée un pointeur sur un objet de type Tomate et un pointeur sur un objet de type Puceron et met à jour l'état de la tomate et du le compteur de reproduction du Puceron si celui ci mange la tomate.*/

void reproductionPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p]);

int testBordure(int i, int j, int n, int p, Case* pointeurPotager[n][p]);

int genereDirection();

int ajoutePuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p]);

int vieillissementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p]);

void enlevePuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p]);

void traduction_DirectionCoordonnees(int dir, int* n, int* p);
/**/

int presenceTomateMangeableDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int i, int j, Case* pointeurPotager[i][j]);
/*Teste la présence d'une tomate "mangeable" dans une direction donnée, en prenant comme point d'origine un autre puceron. Si une tomate "non-mangeable" est présente sur cette case, ou que la direction indiquée est en-dehors du potager, retourne 0, sinon retourne 1.*/

int presenceInsecteDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int i, int j, Case* pointeurPotager[i][j]);
/*Teste la présence d'un insecte dans une direction donnée, en prenant comme point d'origine un puceron. Si un insecte est présent sur cette case, ou que la direction indiquée est en-dehors du potager, retourne 0, sinon retourne 1.*/

void reorientationPuceron(int puceronIndex, ensemblePuceron *ensPuc, int i, int j, Case* pointeurPotager[i][j]);
/*Prend en entrée un pointeur sur un objet de type Puceron et adapte la direction de celui-ci en fonction des tomates présentes dans l'environnement direct de celui-ci (=les cases attenantes à la case dans laquelle se trouve le puceron). La direction reste inchangée si une tomate "mangeable" se trouve dans la case attenante indiquée par cette direction et qu'il n'y a pas d'insecte sur cette case, ou bien si le puceron ne peut se déplacer sur aucune des cases qui l'entourent. Si il n'y a pas de tomate mangeable dans cette direction (ou qu'il y a un insecte sur cette case) alors cette fonction donne la direction indiquant la prochaine case attenante avec tomate mangeable et absence d'insecte. Si il n'y en a pas, la fonction donne la direction indiquant la prochaine case attenante avec absence d'insecte. */

void deplacementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int i, int j, Case* potager[i][j]);
/*Prend en entrée un pointeur sur un objet de type Puceron, met à jour la direction de celui-ci, puis modifie sa position.*/

// Fonctions relatives aux coccinelles
void deplacementCoccinelle(Coccinelle *coccinelle);
void vieillissementCoccinelle(Coccinelle *coccinelle);
void reproductionCoccinelle(Coccinelle *coccinelle);
void mortCoccinelle(Coccinelle *coccinelle);

// Fonctions relatives à l'initialisation du potager (niveau 1)

void initialisationPotagerVide(int ligne, int colonne, Case* pointeurPotager[ligne][colonne]);
void creerEnsemblePuceron(ensemblePuceron* ensPuc,int n, int ligne, int colonne, Case* pointeurPotager[ligne][colonne]);
void remplissagePotagerTomate(int ligne, int colonne, Case potager[ligne][colonne]);
void apparitionPuceron(int n, ensemblePuceron *ensPuc, int ligne, int colonne, Case* pointeurPotager[ligne][colonne]);

//Fonctions relatives à l'affichage du potager

void affichageInsecte(int logo);
void affichagePotager(int n, int p, Case potager[n][p]);

//Fonctions pour récupérer infos sur nos objets
int nbPucerons_Potager(int ligne, int colonne, Case potager[ligne][colonne]);
int nbTomatesMures_Potager(int i, int j, Case potager[i][j]);
float ratioTomatesMures_Potager(int i, int j, Case potager[i][j]);

#endif
