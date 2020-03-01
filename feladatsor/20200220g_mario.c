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

void print_blocks(int m)
{
    int spaces;
    int hashes;
    for (int i = 1; i <= m; ++i)
    {
        spaces = m - i;
        hashes = i;

        print_spaces(spaces);
        print_hashes(hashes);
        printf("  ");
        print_hashes(hashes);
        print_spaces(spaces);
        printf("\n");
    }
}

int main()
{
    int m;
    printf("magassag: ");
    scanf("%d", &m);
    print_blocks(m);

    return 0;
}
