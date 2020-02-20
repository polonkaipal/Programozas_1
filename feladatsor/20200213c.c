#include <stdio.h>
#include <math.h>

int main()
{
    printf("Add meg a kor sugarat cm-ben: ");
    float sugar;
    scanf("%f", &sugar);

    printf("A kor kerulete: %.2f\n", 2 * sugar * M_PI);
    printf("A kor terulete: %.2f\n", sugar * sugar * M_PI);
}