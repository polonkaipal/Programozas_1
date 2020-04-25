#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    A tömb egy véletlenszerűen kiválasztott elemét adja vissza.
*/
int choice(const int n, const int tomb[])
{
    return tomb[rand() % n];
}

int main()
{
    srand(/*19990622*/ time(NULL));
    int t[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int t_meret = sizeof(t) / sizeof(int);

    printf("A tömb egy véletlenszerű eleme: %d\n", choice(t_meret, t));

    return 0;
}
