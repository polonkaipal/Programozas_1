#include <stdio.h>

int get_min(int m, int t[])
{
    int szam = t[0];
    for (int i = 1; i < m; ++i)
        if (t[i] < szam)
            szam = t[i];
    return szam;
}

int get_max(int m, int t[])
{
    int szam = t[0];
    for (int i = 1; i < m; ++i)
        if (t[i] > szam)
            szam = t[i];
    return szam;
}

int main()
{
    int t1[] = { 1, 10, -3, 21, 2, 201, 6, 7, 9, 11 };
    int t1_meret = 10;

    printf("A t1 tomb legkisebb eleme: %d\n", get_min(t1_meret, t1));
    printf("A t1 tomb legnagyobb eleme: %d\n", get_max(t1_meret, t1));

    return 0;
}
