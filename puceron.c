#include "simulation.h"

void mangeTomate(Tomate *tomate, int puceronIndex, ensemblePuceron *ensPuc)
{
    /* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, et ne le modifie pas sinon */
    // met à jour le compteur de reproduction du puceron en conséquence.
    if ((*tomate).etatCroissance > 4)
    {
        //printf("le puceron %d a mangé !\n", puceronIndex);

        (*ensPuc).tab[puceronIndex].compteurReproduction++;
        (*tomate).etatCroissance = 0;
    }
    else
    {
        (*ensPuc).tab[puceronIndex].compteurReproduction = 0;
    }
}

void reproductionPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p])
{
    if ((*ensPuc).tab[puceronIndex].compteurReproduction == 5) // cibler l'ensemble puceron plutot que la case du potager
    {
        int result;
        printf("le puceron %d va se reproduire.\n", puceronIndex);
        result = ajoutePuceron(puceronIndex, ensPuc, n, p, pointeurPotager);
        if (result == 1)
        {
            printf("le puceron %d s'est reproduit !\n", puceronIndex);
            (*ensPuc).tab[puceronIndex].compteurReproduction = 0;
        }
    }
}

int testBordure(int i, int j, int n, int p, Case* pointeurPotager[n][p])
{
    if ((((i > -1) && (i < n)) && ((j > -1) && (j < p))) && (((*pointeurPotager[i][j]).puceronCase == NULL) /*&& (((*pointeurPotager[i][j]).coccinelleCase == NULL)==1)*/))
    {
        return 1;
    }
    return 0;
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

int ajoutePuceron(int puceronIndex, ensemblePuceron *ensPuc, int ligne, int colonne, Case* pointeurPotager[ligne][colonne])
{
    int flag = 0;
    if ((*ensPuc).nbPuceron < 900)
    {
        Puceron nouveauPuceron;
        int n = (*ensPuc).tab[puceronIndex].coordPuceron.x; // modif ici
        int p = (*ensPuc).tab[puceronIndex].coordPuceron.y; // modif ici
        
        if (testBordure(n - 1, p - 1, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n - 1, p - 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};
                flag = 1;
            }
        }
        else if (testBordure(n - 1, p, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n - 1, p}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n - 1, p + 1, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n - 1, p + 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n, p - 1, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n, p - 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n, p + 1, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n, p + 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n + 1, p - 1, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n + 1, p - 1}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n + 1, p, ligne, colonne, pointeurPotager) == 1)
        {
            {
                nouveauPuceron = (struct Puceron){{n + 1, p}, 0, 0, genereDirection(), (*ensPuc).nbPuceron};

                flag = 1;
            }
        }
        else if (testBordure(n + 1, p + 1, ligne, colonne, pointeurPotager) == 1)
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
            // Ajout de Mimi à tester :
            (*pointeurPotager[nouveauPuceron.coordPuceron.x][nouveauPuceron.coordPuceron.y]).puceronCase = &(*ensPuc).tab[(*ensPuc).nbPuceron];
        }
    }
    return flag;
}

int vieillissementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p])
{
    if ((*ensPuc).tab[puceronIndex].compteurVie == 10)
    {
        enlevePuceron(puceronIndex, ensPuc, n, p, pointeurPotager);
        //printf("le puceron %d est mort\n", puceronIndex);
        return 1;
    }
    else
    {
        (*ensPuc).tab[puceronIndex].compteurVie++;
        return 0;
    }
}

void enlevePuceron(int puceronIndex, ensemblePuceron *ensPuc, int n, int p, Case* pointeurPotager[n][p])
{
    (*pointeurPotager[(*ensPuc).tab[(*ensPuc).nbPuceron - 1].coordPuceron.x][(*ensPuc).tab[(*ensPuc).nbPuceron - 1].coordPuceron.y]).puceronCase = &((*ensPuc).tab[puceronIndex]);
    (*ensPuc).tab[puceronIndex] = (*ensPuc).tab[(*ensPuc).nbPuceron - 1];                                               // remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
    (*ensPuc).tab[puceronIndex].index = puceronIndex;                                                                   // réattribue le bon index au puceron qui vient detre déplacé
    (*ensPuc).nbPuceron = (*ensPuc).nbPuceron - 1;                                                                      // corrige le nombre de puceron total dans l'ensemble Puceron
    (*pointeurPotager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y]).puceronCase = NULL; // remet à NULL le pointeur de la case du puceron mort
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

int presenceTomateMangeableDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int i, int j, Case* pointeurPotager[i][j])
{
    int n = ensPuc.tab[puceronIndex].coordPuceron.x; // mettre *n à la place de n ? pas sur mais je crois pas
    int p = ensPuc.tab[puceronIndex].coordPuceron.y; // not certain

    traduction_DirectionCoordonnees(dir, &n, &p); // modifie les valeurs de n et p dans la fonction presenceTomateMangeableDirection selon des conditions
    // valeurs de n et p modifiées normalement

    if ((n >= 0) && (n < i) && (p >= 0) && (p < j) && ((*pointeurPotager[n][p]).tomateCase.etatCroissance > 4))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int presenceInsecteDirection(int puceronIndex, ensemblePuceron ensPuc, int dir, int i, int j, Case* pointeurPotager[i][j])
{
    int n = ensPuc.tab[puceronIndex].coordPuceron.x;
    int p = ensPuc.tab[puceronIndex].coordPuceron.y;

    traduction_DirectionCoordonnees(dir, &n, &p);

    if ((n >= 0) && (n < i) && (p >= 0) && (p < j) && ((*pointeurPotager[n][p]).puceronCase == NULL) && ((*pointeurPotager[n][p]).coccinelleCase == NULL))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void reorientationPuceron(int puceronIndex, ensemblePuceron *ensPuc, int i, int j, Case* pointeurPotager[i][j])
{
    int dir = (*ensPuc).tab[puceronIndex].direction;

    // verifier que on passe bien *ensPuc à la fonction dessous
    if ((presenceTomateMangeableDirection(puceronIndex, *ensPuc, dir, i, j, pointeurPotager) == 0) || (presenceInsecteDirection(puceronIndex, *ensPuc, dir, i, j, pointeurPotager) == 1))
    {
        // Si il n'y a pas de tomates ds la direction ou qu'un insecte est déjà sur la case, alors on cherche ds les cases attenantes
        int testDir = 1;
        int c = 0;
        while ((c < 8) && ((presenceTomateMangeableDirection(puceronIndex, *ensPuc, testDir, i, j, pointeurPotager) == 0) || (presenceInsecteDirection(puceronIndex, *ensPuc, testDir, i, j, pointeurPotager) == 1)))
        {
            // tant qu'on a pas pas dépassé le nb max de directions possibles, et qu'il n'y a pas de tomate mûre trouvée, on continue la boucle
            testDir++;
            if (testDir == 5)
            {
                testDir++;
            }
            c++;
        }
        if (testDir < 10) // ?
        {
            (*ensPuc).tab[puceronIndex].direction = testDir;
        }
        else // vérifier ici, pas sur de comprendre le code
        {
            testDir = 1;
            c = 0;
            while ((c < 8) && (presenceInsecteDirection(puceronIndex, *ensPuc, testDir, i, j, pointeurPotager) == 1))
            {
                // tant qu'on a pas pas dépassé le nb max de directions possibles, et qu'il n'y a pas de case sans insecte trouvée, on continue la boucle
                testDir++;
                if (testDir == 5)
                {
                    testDir++;
                }
                c++;
            }
            if (testDir < 10) // ?
            {
                (*ensPuc).tab[puceronIndex].direction = testDir;
            }
        }
    }
}

void deplacementPuceron(int puceronIndex, ensemblePuceron *ensPuc, int i, int j, Case* pointeurPotager[i][j]) // pas fini de modifier cette fonction
{
    // reorientationPuceron(puceron, i, j, potager); //chaque puceron scanne son environnement PQ EN COMMENTAIRE ICI ?

    if (presenceInsecteDirection(puceronIndex, *ensPuc, (*ensPuc).tab[puceronIndex].direction, i, j, pointeurPotager) == 0)
    {
        (*pointeurPotager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y]).puceronCase = NULL; // enlève le puceron de son ancienne case dans le potager
        traduction_DirectionCoordonnees((*ensPuc).tab[puceronIndex].direction, &((*ensPuc).tab[puceronIndex].coordPuceron.x), &((*ensPuc).tab[puceronIndex].coordPuceron.y)); //met à jour les coordonnées du puceron dans l'ensemble des pucerons
        (*pointeurPotager[(*ensPuc).tab[puceronIndex].coordPuceron.x][(*ensPuc).tab[puceronIndex].coordPuceron.y]).puceronCase = &((*ensPuc).tab[puceronIndex]); // ajoute le puceron dans sa nouvelle case dans le potager
    }
}
