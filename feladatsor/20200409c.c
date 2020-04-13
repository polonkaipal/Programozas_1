#include <stdio.h>
#include <stdlib.h>

#define MAX 500

/*
    A fájl sorainak meghatározása.
*/
int get_number_of_lines(FILE *fp)
{
    char sor[MAX];
    int i = 0;
    while (fgets(sor, MAX, fp) != NULL)
    {
        ++i;
    }
    return i;
}

/*
    A főprogram:
    Parancssori argumentumként megkap egy szöveges fájlnak a nevét.
    A program kiírja a képernyőre a fájl sorainak a számát.
*/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", argv[1]);
        exit(2);
    }
    else
    {
        printf("%d\n", get_number_of_lines(fp));
    }
    fclose(fp);

    return 0;
}
