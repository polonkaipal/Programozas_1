#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MIN 10
#define MAX 99
#define INTERVALLUM (MAX - MIN + 1)

typedef struct
{
    int legkisebb;
    int legnagyobb;
    double atlag;
} Adatok;

/*
    Random számokkal feltölti a tömböt.
*/
void feltolt(const int m, int *t)
{
    srand(/*19990622*/ time(NULL));
    for (int i = 0; i < m; ++i)
    {
        t[i] = (rand() % INTERVALLUM) + MIN;
    }
}

/*
    Kiírja a tömb elemeit vesszővel elválasztva, kivéve az utolsónál.
*/
void kiir(int m, int *t)
{
    for (int i = 0; i < m; ++i)
    {
        printf("%d%s", t[i], (i + 1) < m ? ", " : "");
    }
    puts("");
}

/*
    A kapott tömbről megvizsgálja a következőket:
    - a legkisebb elem
    - a legnagyobb eleme
    - a tömb elemeinek átlaga
    Ezeket az adatokat struktúrával adja vissza
*/
Adatok lekerdezes(const int m, const int *t)
{
    int min = t[0];
    int max = t[0];
    int osszeg = t[0];
    for (int i = 1; i < m; ++i)
    {
        if (t[i] < min)
        {
            min = t[i];
        }

        if (t[i] > max)
        {
            max = t[i];
        }

        osszeg += t[i];
    }
    Adatok adat = {min, max, (double)osszeg / m};
    return adat;
}

/*
    A főprogram:
    Random számokkal feltölt egy tömböt, és kiírja a tömb elemei közül:
    - a legkisebbet
    - a legnagyobbat
    - és a tömb elemeinek átlagát
    mindezt struktúrával megvalósítva.
*/
int main()
{
    int tomb[SIZE];
    feltolt(SIZE, tomb);
    Adatok a = lekerdezes(SIZE, tomb);

    printf("A tömb elemei: ");
    kiir(SIZE, tomb);
    printf("Legkisebb elem: %d\n", a.legkisebb);
    printf("Legnagyobb elem: %d\n", a.legnagyobb);
    printf("Az elemek átlaga: %.1lf\n", a.atlag);

    return 0;
}
