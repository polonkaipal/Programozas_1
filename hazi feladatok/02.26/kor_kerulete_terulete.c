#include <stdio.h>
#include <math.h>

int get_positive_number()
{
    int n;
    scanf("%d", &n);
    while (n < 0)
    {
        printf("Adj meg egy pozitiv egesz szamot: ");
        scanf("%d", &n);
    }
    return n;
}

double circle_perimeter(int r) { return 2.0 * r * M_PI; }
double circle_area(int r) { return (double)r * r * M_PI; }

int main()
{
    int r;
    printf("Add meg a kor sugarat (egesz szamban cm-ben): ");
    r = get_positive_number();
    
    printf("A kor kerulete: %.4lf cm\n", circle_perimeter(r));
    printf("A kor terulete: %.4lf cm2\n", circle_area(r));
    
    return 0;
}
