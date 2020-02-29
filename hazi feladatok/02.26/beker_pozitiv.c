#include <stdio.h>

int get_positive_int()
{
    int n;
    scanf("%d", &n);
    while(n <= 0)
    {
        printf("Adj meg egy pozitiv egesz szamot: ");
        scanf("%d", &n);
    }
    return n;
}

int main()
{
    int szam;
    printf("Adj meg egy pozitiv egesz szamot: ");
    szam = get_positive_int();
    printf("A megadott szam: %d\n", szam);

    return 0;
}