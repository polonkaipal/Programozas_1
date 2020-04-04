#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &felso_hatar);

    srand(time(NULL));
    for (int i = 0; i < db; ++i)
    {
        random_szamok[i] = (rand() % (felso_hatar - also_hatar + 1)) + also_hatar;
    }

    printf("\nA generált számok: ");
    for (int i = 0; i < db; ++i)
    {
        printf("%d%s", random_szamok[i], i + 1 != db ? ", " : "\n");
    }

    return 0;
}
