#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MIN 10
#define MAX 99
#define INTERVALLUM (MAX - MIN + 1)

void feltolt(int meret, int *tomb)
{
    srand(/*19990622*/ time(NULL));
    for (int i = 0; i < meret; ++i)
    {
        *tomb++ = rand() % INTERVALLUM + MIN;
    }
}

void tombot_kiir(int meret, int *tomb)
{
    for (int i = 0; i < meret; ++i)
    {
        printf("%d%s", *tomb++, i + 1 != meret ? ", " : "\n");
    }
}

void tombot_vizsgal(int meret, int tomb[], int *legkisebb, int *legnagyobb, double *atlag)
{
    int osszeg = tomb[0];
    *legkisebb = tomb[0];
    *legnagyobb = tomb[0];

    for (int i = 1; i < meret; ++i)
    {
        osszeg += tomb[i];
        if (tomb[i] < *legkisebb)
        {
            *legkisebb = tomb[i];
        }
        if (tomb[i] > *legnagyobb)
        {
            *legnagyobb = tomb[i];
        }
    }
    *atlag = (double)osszeg / meret;
}

int main()
{
    int tomb[SIZE];

    feltolt(SIZE, tomb);

    int legkisebb, legnagyobb;
    double atlag;
    tombot_vizsgal(SIZE, tomb, &legkisebb, &legnagyobb, &atlag);

    printf("A tömb elemei: ");
    tombot_kiir(SIZE, tomb);

    printf("Legkisebb elem: %d\n", legkisebb);
    printf("Legnagyobb elem: %d\n", legnagyobb);
    printf("Az elemek átlaga: %.2lf\n", atlag);

    return 0;
}
