#include <stdio.h>

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    if (n % 2 == 0) --n;

    for (int i = n; i > 0; i -= 2) printf("%d\n", i);

    return 0;
}