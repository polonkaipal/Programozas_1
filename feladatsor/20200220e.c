#include <stdio.h>

int main()
{
    int n;
    printf("magassag: ");
    scanf("%d", &n);
    int spaces, hashes;
    for (int i = 1; i <= n; ++i)
    {
        hashes = i;
        spaces = n - i;
        for (int j = 1; j <= spaces; ++j)
            printf(" ");
        for (int j = 1; j <= hashes; ++j)
            printf("#");
        printf("\n");
    }

    return 0;
}
