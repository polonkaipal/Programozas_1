#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DB 100
#define MIN 10
#define MAX 99
#define INTERVALLUM (MAX - MIN + 1)

const char *file = "numbers.txt";

/*
    A főprogram:
    Kiír a fájlba 100 db véletlenszámot, melyek a [10, 99] zárt intervallumból kerülnek ki.
*/
int main()
{
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "A(z) %s fájlt nem lehet megyitni\n", *fp);
        exit(1);
    }

    srand(/*19990622*/ time(NULL));
    for (int i = 0; i < DB; ++i)
    {
        fprintf(fp, "%d\n", rand() % INTERVALLUM + MIN);
    }

    fclose(fp);

    return 0;
}
