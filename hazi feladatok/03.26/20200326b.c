#include <stdio.h>

#define MIN 1
#define MAX 99

int main()
{
    printf("Adj meg 0 végjelig egész számokat az [%d, %d] intervallumból!\n", MIN, MAX);
    int tomb[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        tomb[i] = 0;
    }

    int szam, db = 0;
    printf("Szám: ");
    scanf("%d", &szam);
    while (szam != 0)
    {
        if (szam < MIN || szam > MAX)
        {
            puts("Ez a szám kívül esik az elfogadható intervallumon!");
        }
        else
        {
            if (tomb[szam - MIN] == 0)
            {
                ++tomb[szam - MIN];
                ++db;
            }
        }
        printf("Szám: ");
        scanf("%d", &szam);
    }

    printf("\n%d db különböző szám lett megadva.\n", db);
    if (db != 0)
    {
        printf("Ezek (növekvő sorrendben): ");
    }
    // hamár kiiírtuk az összes különböző elemet,
    // akkor befejeződhet a ciklus
    int i = 0;
    while ((i < MAX) && (db != 0))
    {
        if (tomb[i] == 1)
        {
            printf("%d%s", i + MIN, db - 1 != 0 ? ", " : "\n");
            --db;
        }
        ++i;
    }

    return 0;
}
