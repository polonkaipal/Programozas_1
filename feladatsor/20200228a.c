#include <stdio.h>
#define FALSE 0
#define TRUE 1

double get_positive_number()
{
    double n;
    scanf("%lf", &n);
    while (n <= 0)
    {
        printf("Adj meg egy pozitiv valos szamot: ");
        scanf("%lf", &n);
    }

    return n;
}

int valid_triangle(double a, double b, double c)
{
    if (a + b > c && a + c > b && b + c > a)
        return TRUE;
    return FALSE;
}

int main()
{
    printf("Add meg a haromszog elso oldalat: ");
    double a = get_positive_number();
    printf("Add meg a haromszog masodik oldalat: ");
    double b = get_positive_number();
    printf("Add meg a haromszog harmadik oldalat: ");
    double c = get_positive_number();

    printf("A haromszog %sszerkesztheto", valid_triangle(a, b, c) ? "" : "nem ");

    return 0;
}