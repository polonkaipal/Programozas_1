#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{
    puts("Adj meg szavakat '*' végjelig!");
    char szo[SIZE];
    int legnagyobb = 0, db = 0;
    do
    {
        printf("Szó: ");
        fgets(szo, SIZE, stdin);
        int hossz = strlen(szo);
        szo[hossz - 1] = '\0';
        if (hossz > legnagyobb)
        {
            // Az utólsó karakter a '\0',
            // az nem számít bele a szó hosszába
            legnagyobb = hossz - 1;
        }
        ++db;
    }
    while (strcmp("*", szo) != 0);

    // Az utólsó szó a végjel, így le kell vonni a db változóból
    printf("\n%d db szót adtál meg. ", --db); 
    printf("A leghosszabb %d karakterből áll.\n", legnagyobb);

    return 0;
}
