#include <stdio.h>

int main()
{
    int sum = 0, count = 0, n;
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &n);
        sum += n;
        ++count;
    }while (n != 0);

    if (count == 0)
    {
        printf("Hiba: legalabb egy db szamot meg kell adni!\n");
        return -1;
    }

    printf("\nA szamok atlaga: %.2lf", (double)sum / --count);

    return 0;
}
