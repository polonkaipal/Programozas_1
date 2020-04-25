#include <stdio.h>
#include <string.h>

#define SIZE 500

int main()
{
    char szam[SIZE];
    printf("Szám: ");
    fgets(szam, SIZE, stdin);
    szam[strlen(szam) - 1] = '\0';

    int osszeg = 0, i = 0;
    while (szam[i] != '\0')
    {
        osszeg += szam[i] - 48; // '0' ASCII kódja 48
        ++i;
    }
    printf("\nA számjegyek összege: %d\n", osszeg);

    return 0;
}
