#include <stdio.h>

void print_array_reverse(int m, int t[])
{
    for (int i = m - 1; i > -1; --i)
        printf("%d ", t[i]);
}

int main()
{
    int t1[] = { 1, 2, 3, 4, 5 };
    int t1_meret = 5;

    printf("A t1 tomb elemei forditva kiirva: \n");
    print_array_reverse(t1_meret, t1);

    return 0;
}
