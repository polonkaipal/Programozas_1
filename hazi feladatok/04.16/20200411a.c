#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 12

/*
    8 és 12 közötti értéket ad vissza.
*/
int gen_hossz()
{
    int min = 8;
    int max = 12;
    return (rand() % (max - min + 1)) + min;
}

/*
    Jelszó egy karakterét generálja.
*/
char gen_betu()
{
    int min = 1;
    int max = 4;
    char spec[] = {'.', ',', ';', 39};
    int valasztas = (rand() % (max - min + 1) + min);
    switch (valasztas)
    {
        case 1:
            return (rand() % ('z' - 'a' + 1)) + 'a';
            break;
        case 2:
            return (rand() % ('Z' - 'A' + 1)) + 'A';
            break;
        case 3:
            return rand() % 10 + '0'; // (rand() % (9 - 0 + 1)) + 0 + '0'
            break;
        case 4:
            return spec[rand() % 4]; // spec[(rand() % (3 - 0 + 1)) + 0]
            break;
        default:
            break;
    }
}

/*
    A főprogram:
    Egy erős jelszót generál.
*/
int main()
{
    char jelszo[SIZE + 1];

    srand(time(NULL));
    int hossz = gen_hossz();

    for (int i = 0; i < hossz; ++i)
    {
        jelszo[i] = gen_betu();
    }
    jelszo[hossz] = '\0';

    printf("%s\n", jelszo);

    return 0;
}
