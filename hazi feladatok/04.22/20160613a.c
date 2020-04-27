#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Kevés a paraméter");
        exit(1);
    }

    int osszeg = atoi(argv[1]);
    int szorzat = atoi(argv[2]);

    // Ismétlés nélküli kombinációk előállítása
    for (int a = 1; a < 46; ++a)
    {
        for (int b = 1; b < a; ++b)
        {
            for (int c = 1; c < b; ++c)
            {
                for (int d = 1; d < c; ++d)
                {
                    for (int e = 1; e < d; ++e)
                    {
                        for (int f = 1; f < e; ++f)
                        {
                            if (a + b + c + d + e + f == osszeg)
                            {
                                // Csak akkor érdemes ellenőrizni a szorzatot, ha már jó az összeg
                                if (a * b * c * d * e * f == szorzat)
                                {
                                    printf("A keresett számok: %d, %d, %d, %d, %d, %d\n", f, e, d, c, b, a);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
