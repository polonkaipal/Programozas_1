#include <stdio.h>

void print_spaces(int n)
{
    for (int i = 0; i < n; ++i)
        printf(" ");
}

void print_stars(int n)
{
    for (int i = 0; i < n; ++i)
        printf("*");
}

int get_positive_odd_number()
{
    int n;
    scanf("%d", &n);
    while ((n % 2 == 0) || (n < 0))
    {
        printf("Adj meg egy pozitiv egesz paratlan szamot: ");
        scanf("%d", &n);
    }
    return n;
}

void print_line(int stars, int spaces)
{
    print_spaces(spaces);
    print_stars(stars);
    print_spaces(spaces);
    printf("\n");
}

void print_diamond(int n)
{
    int stars, spaces;
    for (int i = 1; i <= (n + 1) / 2; ++i)
    {
        stars = i * 2 - 1;
        spaces = (n - stars) / 2;
        print_line(stars, spaces);
    }
    for (int i = 1; i <= (n - 1) / 2; ++i)
    {
        spaces = i;
        stars = n - 2 * spaces;
        print_line(stars, spaces);
    }
}

int main()
{
    int m;
    printf("Magassag: ");
    m = get_positive_odd_number();
    print_diamond(m);

    return 0;
}
