#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    A benetre kapott változók értékeit megcseréli.
*/
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// Durstenfeld's shuffle algorithm
// helyben módosít
void shuffle(int n, int tomb[])
{
    for (int i = n - 1; i > 0; --i)
    {
        swap(&tomb[rand() % i], &tomb[i]);
    }
}

/*
    Kiírja a tömb elemeit.
*/
void print_array(const int length, const int *array)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d%s", array[i], (i + 1) < length ? ", " : "\n");
    }
}

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t_meret = sizeof(t) / sizeof(int);
    srand(/*19990622*/ time(NULL));

    // Keverés előtt:
    puts("Keverés előtt:");
    print_array(t_meret, t);
    puts("");

    // Keverés:
    puts("Keverés");
    shuffle(t_meret, t);
    puts("");

    // Keverés után
    puts("Keverés után:");
    print_array(t_meret, t);

    return 0;
}
