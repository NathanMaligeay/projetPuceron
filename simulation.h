#ifndef simulation
#define simulation

#include<stdio.h>

typedef struct Coordonnees {
    int x;
    int y;
} Coordonnees;

typedef struct Tomate {
    Coordonnees coordTomates;
    int etatCroissance;
} Tomate;

typedef struct Puceron {
    Coordonnees coordPuceron;
    int compteurReproduction;    
    int compteurVie;
    char direction;
} Puceron;

typedef struct Coccinelle {
    Coordonnees coordCoccinelle;
    int compteurReproduction;
    int compteurVie;
    char direction;
} Coccinelle;

typedef struct Case {
    Tomate* tomateCase;
    Puceron* puceronCase;
    Coccinelle* coccinelleCase;
} Case;


//Fonctions relatives aux tomates
void pousseTomate(Tomate* tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met à jour l'état de croissance de cette tomate. Si l'état est compris entre 0 et 4, alors ajoute +1 à celui-ci. Sinon ne fait rien.*/

void mortTomate(Tomate* tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met son état de croissance à 0.*/


//Fonctions relatives aux pucerons
void directionPuceron(Puceron* puceron) ;
/*Prend en entrée un pointeur sur un objet de type Puceron et adapte la direction de celui-ci en fonction des tomates présentes dans l'environnement direct de celui-ci (=les cases attenantes à la case dans laquelle se trouve le puceron). La direction reste inchangée si une tomate mûre se trouve dans la case attenante indiquée par cette direction. Si il n'y a pas de tomates dans cette direction auquel cas ils se dirigeront dans une case attenante au hasard contenant une tomate. Si ils n’en trouvent pas, ils se d´eplaceront sur une case au hasard.*/

void vieillissementPuceron(Puceron* puceron);
void reproductionPuceron(Puceron* puceron);
void mortPuceron(Puceron* puceron);


//Fonctions relatives aux coccinelles
void deplacementCoccinelle(Coccinelle* coccinelle);
void vieillissementCoccinelle(Coccinelle* coccinelle);
void reproductionCoccinelle(Coccinelle* coccinelle);
void mortCoccinelle(Coccinelle* coccinelle);

//Fonction d'affichage du potager
void affichage(int n, int p, Case potager[n][p]);

# endif
