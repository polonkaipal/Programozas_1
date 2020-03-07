#include <stdio.h>

int is_even(int x)
{
    if (x % 2 == 0)
        return 1;
    return 0;
}

int is_odd(int x)
{
    if (is_even(x) == 0)
        return 1;
    return 0;
}

int get_integer()
{
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
    int szam;
    printf("Adj meg egy pozitiv egesz szamot: ");
    szam = get_integer();
    printf("A megadott szam %d: %s", szam, is_even(szam) == 1 ? "paros" : "paratlan");
    //printf("A megadott szam %d: %s", szam, is_odd(szam) == 0 ? "paros" : "paratlan");

    return 0;
}
