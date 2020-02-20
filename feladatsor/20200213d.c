#include <stdio.h>
#include <math.h>

int main()
{
    printf("Add meg a gomb sugarat cm-ben: ");
    float sugar;
    scanf("%f", &sugar);

    printf("A gomb felszine: %.2f\n", 4 * sugar * sugar * M_PI);
    printf("A gomb terfogata: %.2f\n", 4 / 3 * sugar * sugar * sugar * M_PI);

    return 0;
}
