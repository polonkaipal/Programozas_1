#include <stdio.h>

const int KEZDET = 1;
const int VEG = 100;

int main()
{
    int osszeg = 0;
    for (int i = KEZDET; i < VEG + 1; ++i) 
    {
        osszeg += i;
    }
    printf("A szamok osszege: %d\n", osszeg);

    return 0;
}