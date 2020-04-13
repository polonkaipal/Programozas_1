#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 500

/*
    Beolvassa a paraméterben kapott file-t.
    Visszaadja a benne található valós számok összegét.
*/
double get_double_sum(FILE *fp)
{
    char sor[MAX];
    double osszeg = 0.0;

    while (fgets(sor, MAX, fp) != NULL)
    {
        sor[1] = '.'; // persze ez akkor jó, ha az egész rész csak 0
        osszeg += atof(sor);
    }
    return osszeg;
}

/*
    A főprogram:
    Feldolgozza a megadott fájl tartalmát.
    Kiírja a benne található valós számok összegét 20 tizedesjegypontossággal.
*/
int main()
{
    char *file = "valos_szamok.txt";
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "A fájl (%s) nem található!\n", file);
        exit(1);
    }

    double osszeg = get_double_sum(fp);

    fclose(fp);

    printf("A valós számok összege: %.20lf\n", osszeg);

    return 0;
}
