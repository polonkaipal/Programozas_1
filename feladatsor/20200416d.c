#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 6
#define MIN 10
#define MAX 99
#define INTERVALLUM (MAX - MIN + 1)

typedef struct
{
    int min;
    int max;
} MinMax;

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
    Egy MinMax tipusú struktúrát ad vissza, amelynek tartalma
    a mátrix legkisebb és legnagyobb eleme.
*/
MinMax get_MinMax(const int meret, const int tomb[meret][meret])
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < meret; ++i)
    {
        for (int j = 0; j < meret; ++j)
        {
            if (tomb[i][j] < min)
            {
                min = tomb[i][j];
            }
            if (tomb[i][j] > max)
            {
                max = tomb[i][j];
            }
        }
    }
    MinMax elem = {min, max};
    return elem;
}

/*
    A főprogram:
    Előállít egy 6 x 6 -os méretű, egészeket tartalmazó mátrixot.
    A mátrix elemeit random számokkal tölti fel, melyek a [10, 99] zárt intervallumba esnek.

    1. Kiírja a képernyőre a mátrix tartalmát.
    2. Kiírja a mátrixban található legkisebb és legnagyobb elemet. (struktúrával megoldva)
*/
int main()
{
    int matrix[N][N];
    srand(/*19990622*/ time(NULL));
    matrixot_feltolt(N, matrix);

    printf("A mátrix tartalma:\n\n");
    matrixot_kiir(N, matrix);

    MinMax keresett_elemek = get_MinMax(N, matrix);
    printf("\nA mátrixban található legkisebb és legnagyobb elem:\n");
    printf("Legkisebb: %d\n", keresett_elemek.min);
    printf("Legnagyobb: %d\n", keresett_elemek.max);

    return 0;
}
