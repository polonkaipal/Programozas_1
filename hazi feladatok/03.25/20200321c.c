#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        puts("Hiba! Két paramétert (számot) kell megadni.");
        exit(1);
    }
    printf("%d\n", atoi(argv[1]) + atoi(argv[2]));

    return 0;
}
