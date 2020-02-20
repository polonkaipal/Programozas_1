#include <stdio.h>

int main()
{
    int szam, db = 0;
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);
        ++db;
    } while (szam != 0);

    // Ha az első szám 0 már azt is bele fogja számolni, ezért db - 1 a helyes eredény
    printf("\nElemek szama: %d\n", db - 1);

    return 0;
}