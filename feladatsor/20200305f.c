#include <stdio.h>

void print_array(int m, int t[])
{
    for (int i = 0; i < m; ++i)
        printf("%d%s", t[i], i != m - 1 ? ", " : "");
}

int main()
{
    int t1[] = { 4, 7, 34, 23, 67 };
    int t1_meret = 5;

    print_array(t1_meret, t1);

    return 0;
}
