#include "simulation.h"

void mangeTomate(Tomate *tomate, int puceronIndex, ensemblePuceron *ensPuc)
{
    /* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, et ne le modifie pas sinon */
    // met à jour le compteur de reproduction du puceron en conséquence.
    if ((*tomate).etatCroissance > 4)
    {
        (*ensPuc).tab[puceronIndex].compteurReproduction++;
        (*tomate).etatCroissance = 0;
    }
    else
    {
        (*ensPuc).tab[puceronIndex].compteurReproduction = 0;
    }
}

void reproductionPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*ensPuc).tab[puceronIndex].compteurReproduction == 5)
    {
        int result = ajoutePuceron2(puceronIndex, ensPuc, n, p, potager);
        if (result == 1)
        {
            (*ensPuc).tab[puceronIndex].compteurReproduction = 0;
        }
    }
}

int testBordure(int i, int j, int n, int p, Case potager[n][p])
{
    if ((((i > -1) && (i < n)) && ((j > -1) && (j < p))) && ((potager[i][j].puceronCase == NULL) && ((potager[i][j].coccinelleCase == NULL))))
    {
        return 1;
    }
    return 0;
}

void testBordure2(int i, int j, int n, int p, Case potager[n][p], Coordonnees *coord, int *flag)
{
    Coordonnees tab[8];
    int longueurtab = 0;
    for (int k = -1; k < 2; k++)
    {
        for (int l = -1; l < 2; l++)
        {
            if (!((k == 0) && (l == 0)))
            {
                if (((i + k > -1) && (j + l > -1)) && ((i + k < n) && (j + l < p)) && ((potager[i + k][j + l].puceronCase == NULL) && ((potager[i + k][j + l].coccinelleCase == NULL))))
                {
                    tab[longueurtab] = (struct Coordonnees){i + k, j + l};
                    longueurtab++;
                }
            }
        }
    }
    if (longueurtab != 0)
    {
        *flag = 1;
        int indexhasard = rand() % longueurtab;
        *coord = tab[indexhasard];
    }
}

int genereDirection()
{
    int direction = 0;
    while ((direction == 0) || (direction == 5))
    {
        direction = 1 + rand() % 9;
    }
    return direction;
}

int ajoutePuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    int flag = 0;
    if ((*ensPuc).nbPuceron < LIGNE * COLONNE)
    {
        Puceron nouveauPuceron;
        int n = (*ensPuc).tab[puceronIndex].coordPuceron.x;
        int p = (*ensPuc).tab[puceronIndex].coordPuceron.y;
        if (testBordure(n - 1, p - 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n - 1, p - 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};
                flag = 1;
            }
        }
        else if (testBordure(n - 1, p, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n - 1, p}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n - 1, p + 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n - 1, p + 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n, p - 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n, p - 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n, p + 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n, p + 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n + 1, p - 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n + 1, p - 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n + 1, p, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n + 1, p}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n + 1, p + 1, 30, 30, potager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n + 1, p + 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        if (flag == 1)
        {
            (*ensPuc).tab[(*ensPuc).nbPuceron] = nouveauPuceron; // insère le nouveau puceron dans l'ensemble
            (*ensPuc).nbPuceron = (*ensPuc).nbPuceron + 1;       // incrémente de 1 le compteur de puceron de l'ensemble
            potager[nouveauPuceron.coordPuceron.x][nouveauPuceron.coordPuceron.y].puceronCase = &(*ensPuc).tab[(*ensPuc).nbPuceron];
        }
    }
    return flag;
}

int ajoutePuceron2(int puceronIndex, ensemblePuceron *ensPuc, int ligne, int colonne, Case potager[ligne][colonne])
{
    Coordonnees nouvelleCoord;
    int flag = 0;
    if ((*ensPuc).nbPuceron < ligne * colonne)
    {
        int n = (*ensPuc).tab[puceronIndex].coordPuceron.x;
        int p = (*ensPuc).tab[puceronIndex].coordPuceron.y;
        testBordure2(n, p, ligne, colonne, potager, &nouvelleCoord, &flag);
        if (flag == 1)
        {
            Puceron nouveauPuceron = {nouvelleCoord, 0, 0, genereDirection(), (*ensPuc).nbPuceron};
            (*ensPuc).tab[(*ensPuc).nbPuceron] = nouveauPuceron; // insère le nouveau puceron dans l'ensemble
            (*ensPuc).nbPuceron = (*ensPuc).nbPuceron + 1;       // incrémente de 1 le compteur de puceron de l'ensemble
            potager[nouveauPuceron.coordPuceron.x][nouveauPuceron.coordPuceron.y].puceronCase = &(*ensPuc).tab[(*ensPuc).nbPuceron];
        }
    }
    return flag;
}

int vieillissementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if ((*ensPuc).tab[puceronIndex].compteurVie == 10)
    {
        enlevePuceron(puceronIndex, ensPuc, n, p, potager);
        return 1;
    }
    else
    {
        (*ensPuc).tab[puceronIndex].compteurVie++;
        return 0;
    }
}

void enlevePuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    potager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y].puceronCase = NULL; // remet à NULL le pointeur de la case du puceron mort
    if (puceronIndex != (*ensPuc).nbPuceron - 1)
    {
        (*ensPuc).tab[puceronIndex] = (*ensPuc).tab[(*ensPuc).nbPuceron - 1]; // remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
        (*ensPuc).tab[puceronIndex].index = puceronIndex;                     // réattribue le bon index au puceron qui vient detre déplacé
        potager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y].puceronCase = &((*ensPuc).tab[puceronIndex]);
    }
    (*ensPuc).nbPuceron = (*ensPuc).nbPuceron - 1; // corrige le nombre de puceron total dans l'ensemble Puceron
}

void traduction_DirectionCoordonnees(int dir, int *n, int *p)
{
    if (dir < 4) // sur la ligne du dessus
    {
        *n = (*n) - 1;
    }
    else if (dir > 6) // sur la ligne du dessous
    {
        *n = (*n) + 1;
    }
    if ((dir == 1) || (dir == 4) || (dir == 7)) // sur la colonne de gauche
    {
        *p = (*p) - 1;
    }
    else if ((dir == 3) || (dir == 6) || (dir == 9)) // sur la colonne de droite
    {
        *p = (*p) + 1;
    }
}

int presenceTomateMangeableDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int n, int p, Case potager[n][p])
{
    int x = ensPuc.tab[puceronIndex].coordPuceron.x;
    int y = ensPuc.tab[puceronIndex].coordPuceron.y;

    traduction_DirectionCoordonnees(dir, &x, &y); // modifie les valeurs de n et p dans la fonction presenceTomateMangeableDirection selon des conditions

    // valeurs de n et p modifiées en dessous de cette ligne

    if ((x >= 0) && (x < n) && (y >= 0) && (y < p) && (potager[x][y].tomateCase.etatCroissance > 4))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int presenceInsecteDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int n, int p, Case potager[n][p])
{
    int x = ensPuc.tab[puceronIndex].coordPuceron.x;
    int y = ensPuc.tab[puceronIndex].coordPuceron.y;

    traduction_DirectionCoordonnees(dir, &x, &y);

    if ((x >= 0) && (x < n) && (y >= 0) && (y < p) && (potager[x][y].puceronCase == NULL) && (potager[x][y].coccinelleCase == NULL))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void reorientationPuceron(int puceronIndex, ensemblePuceron *ensPuc, int i, int j, Case potager[i][j])
{
    int dir = (*ensPuc).tab[puceronIndex].direction;

    if ((presenceTomateMangeableDirection(puceronIndex, *ensPuc, dir, i, j, potager) == 0) || (presenceInsecteDirection(puceronIndex, *ensPuc, dir, i, j, potager) == 1))
    {
        // Si il n'y a pas de tomates ds la direction ou qu'un insecte est déjà sur la case, alors on cherche ds les cases attenantes
        int testDir = 1;
        int c = 0;
        while ((c < 8) && ((presenceTomateMangeableDirection(puceronIndex, *ensPuc, testDir, i, j, potager) == 0) || (presenceInsecteDirection(puceronIndex, *ensPuc, testDir, i, j, potager) == 1)))
        {
            // tant qu'on a pas pas dépassé le nb max de directions possibles, et qu'il n'y a pas de tomate mûre trouvée, on continue la boucle
            testDir++;
            if (testDir == 5)
            {
                testDir++;
            }
            c++;
        }
        if (testDir < 10)
        {
            (*ensPuc).tab[puceronIndex].direction = testDir;
        }
        else
        {
            testDir = 1;
            c = 0;
            while ((c < 8) && (presenceInsecteDirection(puceronIndex, *ensPuc, testDir, i, j, potager) == 1))
            {
                // tant qu'on a pas pas dépassé le nb max de directions possibles, et qu'il n'y a pas de case sans insecte trouvée, on continue la boucle
                testDir++;
                if (testDir == 5)
                {
                    testDir++;
                }
                c++;
            }
            if (testDir < 10)
            {
                (*ensPuc).tab[puceronIndex].direction = testDir;
            }
        }
    }
}

void reorientationPuceron2(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    int dir = (*ensPuc).tab[puceronIndex].direction;
    int nouvelleDir;
    int tab[8];
    int longueurtab = 0;

    if ((presenceTomateMangeableDirection(puceronIndex, *ensPuc, dir, n, p, potager) == 0) || (presenceInsecteDirection(puceronIndex, *ensPuc, dir, n, p, potager) == 1))
    {
        for (int k = 1; k < 10; k++) // cas ou il y a des tomates ET pas d'insectes
        {
            if (((k != dir) || (k == 5)) && ((presenceTomateMangeableDirection(puceronIndex, *ensPuc, k, n, p, potager) == 1) && (presenceInsecteDirection(puceronIndex, *ensPuc, k, n, p, potager) == 0)))
            {
                tab[longueurtab] = k;
                longueurtab++;
            }
        }
        if (longueurtab != 0) // puceron a trouvé au moins une case optimale càd avec une tomate et sans autre insecte
        {
            int indexhasard = rand() % longueurtab;
            nouvelleDir = tab[indexhasard];
            (*ensPuc).tab[puceronIndex].direction = nouvelleDir;
        }
        else
        {
            for (int k = 1; k < 10; k++) // cas ou il n'y a pas de tomate ET pas d'insectes
            {
                if (((k != dir) || (k == 5)) && ((presenceInsecteDirection(puceronIndex, *ensPuc, k, n, p, potager) == 0)))
                {
                    tab[longueurtab] = k;
                    longueurtab++;
                }
            }
            if (longueurtab != 0) // puceron a trouvé une case sans insecte
            {
                int indexhasard = rand() % longueurtab;
                nouvelleDir = tab[indexhasard];
                (*ensPuc).tab[puceronIndex].direction = nouvelleDir;
            }
        }
    }
}

void deplacementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case potager[n][p])
{
    if (presenceInsecteDirection(puceronIndex, *ensPuc, (*ensPuc).tab[puceronIndex].direction, n, p, potager) == 0)
    {
        potager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y].puceronCase = NULL; // enlève le puceron de son ancienne case dans le potager
        traduction_DirectionCoordonnees((*ensPuc).tab[puceronIndex].direction, &((*ensPuc).tab[puceronIndex].coordPuceron.x), &((*ensPuc).tab[puceronIndex].coordPuceron.y));
        potager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y].puceronCase = &((*ensPuc).tab[puceronIndex]); // ajoute le puceron dans sa nouvelle case dans le potager
    }
}
