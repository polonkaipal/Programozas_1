#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0, n;
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &n);
        sum += abs(n);
    }while (n != 0);

    printf("\nA szamok atlaga: %d", sum);

    return 0;
}
