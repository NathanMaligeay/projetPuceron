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
    Puceron tab[900];
    int nbPuceron;
} ensemblePuceron;

// Fonctions relatives aux pucerons

void mangeTomate(Tomate *tomate, Puceron *puceron);

void reproductionPuceron(Puceron *puceron, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p]);

void ajoutePuceron(Puceron puceron, ensemblePuceron *ensPuc);

void vieillissementPuceron(Puceron *puceron, ensemblePuceron *ensPuc, potager);

void enlevePuceron(Puceron puceron, ensemblePuceron *ensPuc, potager);

// void directionPuceron(ensemblePuceron *ensPuc, Puceron *puceron);
/*Prend en entrée un pointeur sur un objet de type Puceron et adapte la direction de celui-ci en fonction des tomates présentes dans l'environnement direct de celui-ci (=les cases attenantes à la case dans laquelle se trouve le puceron). La direction reste inchangée si une tomate mûre se trouve dans la case attenante indiquée par cette direction. Si il n'y a pas de tomates dans cette direction auquel cas ils se dirigeront dans une case attenante au hasard contenant une tomate. Si ils n’en trouvent pas, ils se d´eplaceront sur une case au hasard.*/