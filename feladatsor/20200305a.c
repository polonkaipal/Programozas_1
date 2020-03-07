#include <stdio.h>

int is_ordered(int m, const int t[])
{
    for (int i = 1; i < m; ++i)
        if (t[i - 1] > t[i])
            return 0;
    return 1;
}

int main()
{
    int t0[] = { };
    int t0_meret = 0;
    int t1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int t1_meret = 10;
    int t2[] = { 1, 3, 5, 2, 6, 8, 9, 10, 4, 7 };
    int t2_meret = 10;

    printf("A t0 tomb: %srendezett\n", is_ordered(t0_meret, t0) == 1 ? "" : "nem ");
    printf("A t1 tomb: %srendezett\n", is_ordered(t1_meret, t1) == 1 ? "" : "nem ");
    printf("A t2 tomb: %srendezett\n", is_ordered(t2_meret, t2) == 1 ? "" : "nem ");

    return 0;
}
