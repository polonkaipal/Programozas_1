#include <stdio.h>

int get_positive_number()
{
    int n;
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("-> ez nem pozitiv egesz\n\n");
        printf("Pozitiv egesz: ");
        scanf("%d", &n);
    }

    return n;
}

int main()
{
    printf("Pozitiv egesz: ");
    int n = get_positive_number();
    printf("\nA pozitiv egesz: %d", n);

    return 0;
}
