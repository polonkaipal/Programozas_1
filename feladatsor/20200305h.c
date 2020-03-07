#include <stdio.h>
#include <stdlib.h>

void set_array_to_abs(int m, int t[])
{
    for (int i = 0; i < m; ++i)
        t[i] = abs(t[i]);
}

void print_array(int m, const int t[])
{
    for (int i = 0; i < m; ++i)
        printf("%d ", t[i]);
    printf("\n");
}

int main()
{
    int t1[] = { -2, -6, 5, 3, 7, -21, 19, -20, -7, 5 };
    int t1_meret = 10;

    set_array_to_abs(t1_meret, t1);
    printf("A t1 tomb elemeinek abszolutertekei: \n");
    print_array(t1_meret, t1);

    return 0;
}
