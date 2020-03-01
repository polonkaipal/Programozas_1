#include <stdio.h>
int get_positive_number()
{
    int n;
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("Adj meg egy pozitiv egesz szamot: ");
        scanf("%d", &n);
    }

    return n;
}

void print_1_to_n(int n)
{
    for (int i = 1; i <= n; ++i)
        printf("%d%s", i, i + 1 <= n ? " -> " : "");
}

int main()
{
    printf("Adj meg egy pozitiv egesz szamot: ");
    int n = get_positive_number();
    print_1_to_n(n);

    return 0;
}
