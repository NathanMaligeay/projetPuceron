#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simulation.h"

void testBordure2(int i, int j, int n, int p, Case potager[n][p])
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
          //  printf("sequence n=%d p=%d\n", k, l);
            }
        }
   }
   printf("longueur tab %d\n", longueurtab);

    for (int m = 0; m < longueurtab; m++)
    {
        printf("coord %d %d\n", tab[m].x, tab[m].y);
    }
}

int main()
{
    srand(time(NULL));

    Case potager[3][3];

    Puceron p1 = {{2,0}, 0, 0, 2, 0};
    ensemblePuceron ensPuc;
    ensPuc.tab[0] = p1;
   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            potager[i][j].puceronCase = NULL;
            potager[i][j].coccinelleCase = NULL;
        }
    }

    potager[ensPuc.tab[0].coordPuceron.x][ensPuc.tab[0].coordPuceron.y].puceronCase = &p1;

    testBordure2(ensPuc.tab[0].coordPuceron.x, ensPuc.tab[0].coordPuceron.y, 3, 3, potager);

    return 0;
}