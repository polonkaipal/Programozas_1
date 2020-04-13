#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Egy string tömb elemeinek hosszát vizsgálja,
    és visszaadja a legrövidebb elem hosszát.
*/
int legrovidebb_hossz(const int m, const char *t[])
{
    int legrovidebb = strlen(t[0]);
    for (int i = 1; i < m; ++i)
    {
        int hossz = strlen(t[i]);
        if (hossz < legrovidebb)
        {
            legrovidebb = hossz;
        }
    }
    return legrovidebb;
}

/*
    Egy string tömb elemei közül kiírja sortöréssel
    elválasztva a megadott hosszú szavakat.
*/
void adott_hosszusagu_szavak(const int m, const char *t[], const int hossz)
{
    for (int i = 0; i < m; ++i)
    {
        if (strlen(t[i]) == hossz)
        {
            printf("%s\n", t[i]);
        }
    }
}

/*
    A főprogram:
    A bemenetben kapott szavak közül kiírja a legrövidebb
    hosszú szavakat, melyek sorrendje az input sorrendjétől függ.
*/
int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Nem adtál meg egyetlen szót sem!\n");
        exit(1);
    }

    int legrovidebb = legrovidebb_hossz(argc, argv);
    adott_hosszusagu_szavak(argc, argv, legrovidebb);

    return 0;
}
