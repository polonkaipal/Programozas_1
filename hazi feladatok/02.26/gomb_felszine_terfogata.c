#include <stdio.h>
#include <math.h>

double get_double()
{
    double n;
    scanf("%lf", &n);
    while (n < 0)
    {
        printf("Adj meg egy pozitiv valos szamot: ");
        scanf("%lf", &n);
    }
    return n;
}

double sphere_surface(double r) { return 4.0 * r * r * M_PI; }
double sphere_volume(double r) { return 4.0 / 3 * r * r * r * M_PI; }

int main()
{
    double r;
    printf("Add meg a gomb sugarat (cm-ben): ");
    r = get_double();

    printf("A gomb felszine: %.4lf cm2\n", sphere_surface(r));
    printf("A gomb terfogata: %.4lf cm3\n", sphere_volume(r));

    return 0;
}
