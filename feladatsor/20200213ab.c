#include <stdio.h>

int main()
{
    printf("Add meg a teglalap egyik oldalat (cm-ben): ");
    float a;
    scanf("%f", &a);
    printf("Add meg a teglalap masik oldalat (cm-ben): ");
    float b;
    scanf("%f", &b);

    printf("A teglalap kerulete: %.2f cm\n", 2 * (a + b));
    printf("A teglalap terulete: %.2f cm2\n", a * b);

    return 0;
}
