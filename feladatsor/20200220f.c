#include <stdio.h>

void print_spaces(int space_number)
{
    for (int i = 0; i < space_number; ++i)
        printf(" ");
}

void print_hashes(int hash_number)
{
    for (int i = 0; i < hash_number; ++i)
        printf("#");
}

void print_triangle(int m)
{
    int spaces;
    int hashes;
    for (int i = 1; i <= m; ++i)
    {
        hashes = i * 2 - 1;
        spaces = m - i;

        print_spaces(spaces);
        print_hashes(hashes);
        print_spaces(spaces);
        printf("\n");
    }
}

int get_positive_number()
{
    int n;
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("Adj meg egy pozitiv egest szamot: ");
        scanf("%d", &n);
    }
    return n;
}

int main()
{
    printf("magassag: ");
    int m = get_positive_number();
    print_triangle(m);

    return 0;
}
