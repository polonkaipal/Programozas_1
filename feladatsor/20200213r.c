#include <stdio.h>

int main()
{
    float suly;
    printf("Testsúly (kg): ");
    scanf("%f", &suly);

    float magassag;
    printf("Testmagasság (cm): ");
    scanf("%f", &magassag);

    printf("Az On testtömegindexe: %.2f\n", suly / (magassag * magassag / 10000));

    return 0;
}