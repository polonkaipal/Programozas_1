#include <stdio.h>

int main()
{
    int szam, osszeg = 0;
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);
        osszeg += szam;
    } while (szam != 0);
    
    printf("Elemek osszege: %d\n", osszeg);
    
    return 0;
}