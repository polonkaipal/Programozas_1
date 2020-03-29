#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

int benne_van(int meret, const int tomb[], int elem)
{
    for (int i = 0; i < meret; ++i)
    {
        if (tomb[i] == elem)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int main()
{
    int db;
    puts("Hány db random számot kérsz?");
    scanf("%d", &db);
    int random_szamok[db];

    int also_hatar;
    printf("Alsó határ: ");
    scanf("%d", &also_hatar);
    int felso_hatar;
    printf("Felső határ: ");
    scanf("%d", &felso_hatar);

    srand(time(NULL));
    // ha több számot kérünk, mint amennyi az intervallum
    // végtelen ciklust kapunk
    for (int i = 0; i < db; ++i)
    {
        int veletlen;
        do
        {
            veletlen = (rand() % (felso_hatar - also_hatar + 1)) + also_hatar;
        }
        while (benne_van(db, random_szamok, veletlen) == TRUE);
        random_szamok[i] = veletlen;
    }

    for (int i = 0; i < db - 1; ++i)
    {
        for (int j = i + 1; j < db; ++j)
        {
            if (random_szamok[j] < random_szamok[i])
            {
                int tmp = random_szamok[j];
                random_szamok[j] = random_szamok[i];
                random_szamok[i] = tmp;
            }
        }
    }

    printf("A generált számok: ");
    for (int i = 0; i < db; ++i)
    {
        printf("%d%s", random_szamok[i], i + 1 != db ? ", " : "\n");
    }

    return 0;
}
