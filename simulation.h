#ifndef simulation
#define simulation

typedef struct Coordonnee {
    int abscisse;
    int ordonnee;
} Coordonnee;

typedef struct Case {
    Tomate* tomateCase;
    Puceron* puceronCase;
    Coccinelle* coccinelleCase;
} Case;

typedef struct Tomate {
    Coordonnees coordTomates;
    int etatCroissance;
} Tomate;

typedef struct Puceron {
    Coordonnees coordPuceron;
    int compteurReproduction;    
    int compteurVie;
    int direction;
} Puceron;

typedef struct Coccinelle {
    Coordonnees coordCoccinelle;
    int compteurReproduction;
    int compteurVie;
    int direction;
} Coccinelle;

int pousseTomate();
void mortTomate();
void deplacementPuceron() ; //direction donn´ee jusqu’`a ce qu’ils ne trouvent plus de tomates, auquel cas ils se dirigeront dans une case attenante au hasard contenant une tomate. Si ils n’en trouvent pas, ils se d´eplaceront sur une case au hasard.
void deplacementCoccinelle();
void vieillissementCoccinelle();
void vieillissementPuceron();
void reproductionPuceron();
void reproductionCoccinelle();
void mortPuceron();
void mortCoccinelle();
