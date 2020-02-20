#include <stdio.h>

int main()
{
    int szam, dbp = 0, dbm = 0;
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);

        if (szam > 0) ++dbp;
        else if(szam < 0) ++dbm;
        
    } while (szam != 0);

    printf("\nPozitiv elemek szama: %d\n", dbp);
    printf("Negativ elemek szama: %d\n", dbm);

    return 0;
}