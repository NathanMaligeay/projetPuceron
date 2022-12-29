#ifndef simulation
#define simulation

typedef struct Coordonnee {
    int x;
    int y;
} Coordonnee;

typedef struct Case {
    Tomate* tomateCase;
    Puceron* puceronCase;
    Coccinelle* coccinelleCase;
} Case;

Case Potager[30][30];

typedef struct Tomate {
    Coordonnees coordTomates;
    int etatCroissance;
} Tomate;


typedef struct Coccinelle {
    Coordonnees coordCoccinelle;
    int compteurReproduction;
    int compteurVie;
    int direction;
} Coccinelle;


//Fonctions relatives aux tomates
void pousseTomate(Tomate* tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met à jour l'état de croissance de cette tomate. Si l'état est compris entre 0 et 4, alors ajoute +1 à celui-ci. Sinon ne fait rien.*/

void mortTomate(Tomate* tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met son état de croissance à 0.*/



//Fonctions relatives aux coccinelles
void deplacementCoccinelle(Coccinelle* coccinelle);
void vieillissementCoccinelle(Coccinelle* coccinelle);
void reproductionCoccinelle(Coccinelle* coccinelle);
void mortCoccinelle(Coccinelle* coccinelle);


# endif