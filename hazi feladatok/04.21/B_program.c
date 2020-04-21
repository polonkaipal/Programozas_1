#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEZDET 2
#define SZORZO 2
#define BUFFER 100

const char *file = "numbers.txt";
char sor[BUFFER];

typedef struct
{
    int *tomb;
    int hossz;
    int maxHossz;
} DinamikusTomb;

void memoria_hiba()
{
    fprintf(stderr, "Nem sikerült lefoglalni a tárhelyet.\n");
    exit(2);
}

DinamikusTomb *dt_Letrehoz()
{
    DinamikusTomb *t = malloc(sizeof(DinamikusTomb));
    if (t == NULL)
    {
        memoria_hiba();
    }

    t->tomb = malloc(KEZDET * sizeof(int));
    if (t->tomb == NULL)
    {
        memoria_hiba();
    }

    t->hossz = 0;
    t->maxHossz = KEZDET;
    return t;
}

void dt_Hozzafuz(DinamikusTomb *t, int adat)
{
    if (t->hossz == t->maxHossz)
    {
        int uj_maxHossz = (int)(SZORZO * t->maxHossz);
        t->tomb = realloc(t->tomb, uj_maxHossz * sizeof(int));
        if (t->tomb == NULL)
        {
            memoria_hiba();
        }
        t->maxHossz = uj_maxHossz;
    }
    t->tomb[t->hossz] = adat;
    ++(t->hossz);
}

void *dt_Pusztito(DinamikusTomb *t)
{
    free(t->tomb);
    free(t);
    return NULL;
}

void Fajlt_Beolvas(FILE *fp, DinamikusTomb *t)
{
    while (fgets(sor, BUFFER, fp) != NULL)
    {
        sor[strlen(sor) - 1] = '\0';
        dt_Hozzafuz(t, atoi(sor));
    }
}

double atlag(DinamikusTomb *t)
{
    int osszeg = 0;
    for (int i = 0; i < t->hossz; ++i)
    {
        osszeg += t->tomb[i];
    }
    return (double)osszeg / t->hossz;
}

/*
    A főprogram:
    Beolvassa a fájl tartalmát egy dinamikus tömbbe.
    A program feldolgozza a dinamikus tömb elemeit és kiírja a képernyőre a dinamikus tömbben tárolt számok átlagát.
*/
int main()
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "A(z) %s fájlt nem lehet megyitni\n", *fp);
        exit(1);
    }

    DinamikusTomb *tomb = dt_Letrehoz();

    Fajlt_Beolvas(fp, tomb);

    printf("A tömb elemeinek átlaga: %lf\n", atlag(tomb));

    dt_Pusztito(tomb);

    fclose(fp);

    return 0;
}
