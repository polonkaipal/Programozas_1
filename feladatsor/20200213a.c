#include <stdio.h>

int main()
{
    printf("Add meg a teglalap egyik oldalat (cm-ben): ");
    int a;
    scanf("%d", &a);
    printf("Add meg a teglalap masik oldalat (cm-ben): ");
    int b;
    scanf("%d", &b);

    printf("A teglalap kerulete: %d cm\n", 2 * (a + b));
    printf("A teglalap terulete: %d cm2\n", a * b);

    return 0;
}