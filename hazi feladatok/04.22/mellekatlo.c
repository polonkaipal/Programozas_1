#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
#define MIN 10
#define MAX 99
#define INTERVALLUM (MAX - MIN + 1)

/*
    Egy N x N -es mátrixot feltölt véletlen számokkal.
*/
void matrixot_feltolt(const int n, int m[n][n])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            m[i][j] = rand() % INTERVALLUM + MIN;
        }
    }
}

/*
    Egy N x N -es mátrix tartalmát írja ki a konzolra.
*/
void matrixot_kiir(const int n, const int m[n][n])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d%s", m[i][j], (j + 1) < n ? "\t" : "\n");
        }
    }
}

/*
    Egy N x N -es mátrix mellékátlóját írja ki a konzolra.
*/
void mellekatlot_kiir(const int n, const int m[n][n])
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d%s", m[i][n - 1 - i], (i + 1) < n ? ", " : "\n");
    }
}

/*
    A főprogram:
    Egy N x N -es mátrixot létrehoz, és kiírja a mellékátlóját.
*/
int main()
{
    srand(/*19990622*/ time(NULL));
    int matrix[N][N];

    matrixot_feltolt(N, matrix);

    matrixot_kiir(N, matrix);

    printf("\nA mellékátló tartalma: \n");
    mellekatlot_kiir(N, matrix);

    return 0;
}
