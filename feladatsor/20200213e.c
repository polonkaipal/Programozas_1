#include <stdio.h>

int main()
{
    printf("Adj meg egy pozitiv egesz szamot: ");
    int szam;
    scanf("%d", &szam);

    if (szam % 2 == 0) printf("A szam paros\n");
    else printf("A szam paratlan\n");
    
    return 0;
}
