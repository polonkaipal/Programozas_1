#include <stdio.h>

const int VEG = 1000;

int main()
{
    int osszeg = 0;
    for (int i = 1; i < VEG; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            osszeg += i;
        }        
    }
    printf("Az osszeg: %d\n", osszeg);

    return 0;
}