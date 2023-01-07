#ifndef structure
#define structure

#define LIGNE 30
#define COLONNE 30
#define NBPUCERON 20

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
    Puceron tab[LIGNE * COLONNE];
    int nbPuceron;
} ensemblePuceron;

typedef struct Case
{
    Tomate tomateCase;
    Puceron *puceronCase;
    Coccinelle *coccinelleCase;
} Case;

#endif
