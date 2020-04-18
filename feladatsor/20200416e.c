#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
#define MIN 10
#define MAX 99
#define INTERVALLUM (MAX - MIN + 1)

/*
    A kapott mátrixot feltölti random számokkal.
*/
void matrixot_feltolt(const int meret, int tomb[meret][meret])
{
    for (int i = 0; i < meret; ++i)
    {
        for (int j = 0; j < meret; ++j)
        {
            tomb[i][j] = rand() % INTERVALLUM + MIN;
        }
    }
}

/*
    A kapott mátrixot kiíratja a konzolra.
*/
void matrixot_kiir(const int meret, const int tomb[meret][meret])
{
    for (int i = 0; i < meret; ++i)
    {
        for (int j = 0; j < meret; ++j)
        {
            printf("%d%s", tomb[i][j], (j + 1) < meret ? " " : "");
        }
        puts("");
    }
}

/*
    Összehasonlítja a főátlóban és a mellékátlóban lévő elemek összegét.
    Visszatérési értékek:
    * 0: A főátlóban és a mellékátlóban található elemek összege egyenlő.
    * 1: A főátlóban található elemek összege nagyobb.
    * -1: A mellékátlóban található elemek összege nagyobb.
*/
int osszehasonlit(const int meret, const int tomb[meret][meret])
{
    int A = 0; // A főátló összege
    int B = 0; // A mellékátló összege
    for (int i = 0; i < meret; ++i)
    {
        A += tomb[i][i]; // A főátló eleme
        B += tomb[i][meret - 1 - i]; // A mellékátló eleme
    }
    if (A > B)
    {
        return 1;
    }
    else if (A < B)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*
    A főprogram:
    Előállít egy 6 x 6 -os méretű, egészeket tartalmazó mátrixot.
    A mátrix elemeit random számokkal tölti fel, melyek a [10, 99] zárt intervallumba esnek.

    1. Kiírja a képernyőre a mátrix tartalmát.
    2. Kiírja, hogy a mátrix főátlója és a mellékátlója kisebb, egyenlő vagy nagyobb.
*/
int main()
{
    int matrix[N][N];
    srand(/*19990622*/ time(NULL));
    matrixot_feltolt(N, matrix);

    printf("A mátrix tartalma:\n\n");
    matrixot_kiir(N, matrix);
    puts("");

    switch (osszehasonlit(N, matrix))
    {
    case 1:
        puts("A főátlóban található elemek összege a nagyobb");
        break;
    case -1:
        puts("A mellékátlóban található elemek összege a nagyobb");
        break;
    default: // csak a 0 lehet
        puts("A főátlóban és a mellékátlóban található elemek összege megegyezik");
        break;
    }

    return 0;
}
