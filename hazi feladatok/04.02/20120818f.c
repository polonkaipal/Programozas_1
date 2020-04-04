#include <stdio.h>

#define N 100

unsigned long n_szam_negyzetosszege(int n)
{
    ++n;    // hatékonyság szempontjából
    unsigned long osszeg = 0;
    for (int i = 1; i < n; ++i)    // 1-től n-ig megy az algoritmus
    {
        osszeg += (unsigned long)i * i;
    }
    return osszeg;
}

unsigned long n_szam_osszegenek_negyzete(int n)
{
    ++n;    // hatékonyság szempontjából
    unsigned long osszeg = 0;
    for (int i = 1; i < n; ++i)    // 1-től n-ig megy az algoritmus
    {
        osszeg += (unsigned long)i;
    }
    return osszeg * osszeg;
}

int main()
{
    printf("Az első %d természetes szám összegének a ", N);
    printf("négyzete és az első %d természetes szám négyzetösszege ", N);
    printf("közti különbség:\n%lu\n", n_szam_osszegenek_negyzete(N) - n_szam_negyzetosszege(N));

    return 0;
}
