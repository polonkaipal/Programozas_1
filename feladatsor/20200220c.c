#include <stdio.h>

int get_positive_number()
{
    int n;
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("Adj meg egy pozitiv egesz szamot: ");
        scanf("%d", &n);
    }

    return n;
}

char which_is_bigger(int a, int b)
{
    if (a < b)
        return '<';
    else if (a > b)
        return '>';
    return '=';
}

int main()
{
    printf("Add meg az elso szamot: ");
    int a = get_positive_number();
    printf("Add meg a masodik szamot: ");
    int b = get_positive_number();
    printf("%c\n", which_is_bigger(a, b));

    return 0;
}
