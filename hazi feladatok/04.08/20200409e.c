#include <stdio.h>
#include <stdlib.h>

#define MAX 500

/*
    Ez a függvény a bemenetre kapott input file-ból átmásolja
    az output file-ba a 0,5-nél nagyobb elemeket.
    Visszatérési értéke pedig a kiírt elemek száma.
*/
int szures(FILE *fpi, FILE *fpo)
{
    int db = 0;
    char sor[MAX];
    while (fgets(sor, MAX, fpi) != NULL)
    {
        if (atof(sor) > 0.5)
        {
            fprintf(fpo, "%s", sor);
            ++db;
        }
    }
    return db;
}

/*
    A főprogram:
    Feldolgozza a kapott txt állományt, s kiírja a 0,5-nél
    nagyobb számokat egy out.txt nevű fájlba.
    A program egyszerű log formájában tájékoztja a felhasználót
    arról, hogy mi is történik.
*/
int main()
{
    char *input_file = "in.txt";
    char *output_file = "out.txt";

    FILE *fpi = fopen(input_file, "r");
    if (fpi == NULL)
    {
        fprintf(stderr, "A fájl (%s) nem található!\n", input_file);
        exit(1);
    }

    printf("# %s sikeresen megnyitva\n", input_file);

    printf("# 0,5-nél nagyobb számok szűrése...\n");
    FILE *fpo = fopen(output_file, "w");
    int db = szures(fpi, fpo);

    printf("# szűrés vége\n");
    fclose(fpi);

    printf("# %s bezárva\n", output_file);
    fclose(fpo);

    printf("# %s-be kiírt számok mennyisége: %d db\n", output_file, db);

    return 0;
}
