#include <stdio.h>
#define N 32
#define M 127
#define A 65
#define Z 90

void print_ascii_n_to_m(int n, int m)
{
    for (int i = n; i <= m; ++i)
        printf("%d: %c\n", i, i);
}

int get_ascii_sum_n_to_m(int n, int m)
{
    int sum = 0;
    for (int i = n; i <= m; ++i)
        sum += i;
    return sum;
}

int main()
{
    print_ascii_n_to_m(N, M);
    printf("Az angol abc nagybetuihez tartozo ASCII ertekek osszege: %d",
    get_ascii_sum_n_to_m(A, Z));

    return 0;
}
