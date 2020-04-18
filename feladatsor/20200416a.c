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
    A kapott mátrixból kiírja a főátló elemeit.
*/
void foatlot_kiir(const int meret, const int tomb[meret][meret])
{
    for (int i = 0; i < meret; i++)
    {
        printf("%d%s", tomb[i][i], (i + 1) < meret ? ", " : "");
    }
    puts("");
}

/*
    A főprogram:
    Előállít egy 6 x 6 -os méretű, egészeket tartalmazó mátrixot.
    A mátrix elemeit random számokkal tölti fel, melyek a [10, 99] zárt intervallumba esnek.

    1. Kiírja a képernyőre a mátrix tartalmát
    2. Kiírja a képernyőre a főátló elemeit.
*/
int main()
{
    int matrix[N][N];
    srand(/*19990622*/ time(NULL));
    matrixot_feltolt(N, matrix);

    printf("A mátrix tartalma:\n\n");
    matrixot_kiir(N, matrix);

    printf("\nA főátló tartalma: ");
    foatlot_kiir(N, matrix);

    return 0;
}
