#include <stdio.h>
#include <stdlib.h>

#define KEZDETI_KAPACITAS 2
#define SZORZO 1.5
#define BUFFER 100

typedef struct
{
    int *elemek;
    int hossz;
    int maxHossz;
} DinamikusTomb;

void memoria_hiba()
{
    fprintf(stderr, "Hiba: Nem lehet lefoglalni a mermóriában tárhelyet.\n");
    exit(3);
}

DinamikusTomb *dt_Letrehoz()
{
    DinamikusTomb *uj = malloc(sizeof(DinamikusTomb));
    if (uj == NULL)
    {
        memoria_hiba();
    }

    uj->elemek = malloc(KEZDETI_KAPACITAS * sizeof(int));
    if (uj->elemek == NULL)
    {
        memoria_hiba();
    }

    uj->hossz = 0;
    uj->maxHossz = KEZDETI_KAPACITAS;

    return uj;
}

void dt_Hozzafuz(DinamikusTomb *ez, const int adat)
{
    if (ez->hossz == ez->maxHossz)
    {
        int uj_Kapacitas = ez->maxHossz * SZORZO;
        ez->elemek = realloc(ez->elemek, uj_Kapacitas * sizeof(int));
        if (ez->elemek == NULL)
        {
            memoria_hiba();
        }
        ez->maxHossz = uj_Kapacitas;
    }
    ez->elemek[ez->hossz] = adat;
    ++(ez->hossz);
}

void *dt_Pusztito(DinamikusTomb *ez)
{
    free(ez->elemek);
    free(ez);
    return NULL;
}

/*
    Feltölti a paraméterben kapott fájlból az adatokat.
*/
void feltolt(const char *file, DinamikusTomb *t)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "A %s fájlt nem lehet megnyitni!\n", file);
        exit(2);
    }
    char sor[BUFFER];

    while (fgets(sor, BUFFER, fp) != NULL)
    {
        dt_Hozzafuz(t, atoi(sor));
    }

    fclose(fp);
}

/*
    Megcseréli a paraméterben kapott két elemt értékét.
*/
void csere(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
    Gyorsrendezés algoritmusa. (Helyben rendez)
*/
void gyorsrendezes(int t[], int bal, int jobb)
{
    int i = bal, j = jobb, x = t[(bal + jobb) / 2];

    while (i <= j)
    {
        while (t[i] < x)
        {
            ++i;
        }
        while (t[j] > x)
        {
            --j;
        }
        if (i <= j)
        {
            csere(&t[i], &t[j]);
            ++i;
            --j;
        }
    }

    if (bal < j)
    {
        gyorsrendezes(t, bal, j);
    }
    if (i < jobb)
    {
        gyorsrendezes(t, i, jobb);
    }
}

/*
    A paraméterben megkapott dinamikus tömb tartalmát rendezi,
    majd kiírja annak tartalmát a ki.txt-be.
*/
void rendez(DinamikusTomb *ez)
{
    FILE *fp = fopen("ki.txt", "w");
    if (fp == NULL)
    {
        memoria_hiba();
    }

    gyorsrendezes(ez->elemek, 0, ez->hossz - 1);
    for (int i = 0; i < ez->hossz; ++i)
    {
        fprintf(fp, "%d\n", ez->elemek[i]);
    }
    fclose(fp);
}

/*
    A főprogram:
    Bemeneti paraméterben megadott file tartalmát rendezi.
    Mindezt dinamikus tömb segítségével.
*/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Nincs megadva paraméter!\n");
        exit(1);
    }

    char *file = argv[1];
    DinamikusTomb *tomb = dt_Letrehoz();

    feltolt(file, tomb);

    rendez(tomb);

    dt_Pusztito(tomb);

    return 0;
}
