#include <stdio.h>

typedef struct test
{
    int index;
    int compteurDirection;
} test;

int main()
{

    test t1 = {5, 10};
    test t2 = {2, 6};

    test tab[2] = {t1, t2};
    printf("%d%d\n",tab[0].compteurDirection,tab[0].index);
    printf("%d%d\n",tab[1].compteurDirection,tab[1].index);
    tab[0] = tab[1];
    printf("%d%d\n",tab[0].compteurDirection,tab[0].index);
    printf("%d%d\n",tab[1].compteurDirection,tab[1].index);

    return 0;
}