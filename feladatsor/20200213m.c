#include <stdio.h>

int main()
{
    int szam, db = 0;
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);

        if (szam > 0) ++db;
        
    } while (szam != 0);

    printf("\nPozitiv elemek szama: %d\n", db);

    return 0;
}