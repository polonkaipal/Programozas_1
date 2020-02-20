#include <stdio.h>

int main()
{
    int szam, db = 0;
    printf("Egesz szam (vege: 0): ");
    scanf("%d", &szam);

    while(szam != 0)
    {
        printf("%d", szam);
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);
        ++db;
    }

    printf("Elemek szama: %d\n", db);
}