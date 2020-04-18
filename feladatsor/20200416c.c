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

int foatlo_es_mellekatlo_osszege(const int meret, const int tomb[meret][meret])
{
    int osszeg = 0;
    for (int i = 0; i < meret; i++)
    {
        osszeg += tomb[i][i]; // A főátló eleme
        osszeg += tomb[i][meret - 1 - i]; /// A mellékátló eleme
    }
    return osszeg;
}

/*
    A főprogram:
    Előállít egy 6 x 6 -os méretű, egészeket tartalmazó mátrixot.
    A mátrix elemeit random számokkal tölti fel, melyek a [10, 99] zárt intervallumba esnek.

    1. Kiírja a képernyőre a mátrix tartalmát.
    2. Kiírja a főátlóban és a mellékátlóban lévő elemek összegét.
*/
int main()
{
    int matrix[N][N];
    srand(/*19990622*/ time(NULL));
    matrixot_feltolt(N, matrix);

    printf("A mátrix tartalma:\n\n");
    matrixot_kiir(N, matrix);

    printf("\nA főátlóban és a mellékátlóban ");
    printf("található elemek összege: %d\n", foatlo_es_mellekatlo_osszege(N, matrix));

    return 0;
}
