#include <stdio.h>

int main()
{
    int a;
    printf("Add meg az elso szamot: ");
    scanf("%d", &a);

    char muvelet[2];
    printf("Add meg a muveleti jelet (+, -, *, /): ");
    scanf("%s", &muvelet);

    int b;
    printf("Add meg a masodik szamot: ");
    scanf("%d", &b);

    switch(muvelet[0])
    {
        case '+':
        printf("A vegeredmeny: %d\n", a + b);
        break;

        case '-':
        printf("A vegeredmeny: %d\n", a - b);
        break;

        case '*':
        printf("A vegeredmeny: %d\n", a * b);
        break;

        case '/':
        printf("A vegeredmeny: %.2f\n", (float)a / b);
        break;

        default:
        printf("Hiba!");
    }

    return 0;
}