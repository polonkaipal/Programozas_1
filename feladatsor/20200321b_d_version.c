#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    if (argc > 2)
    {
        puts("Hiba! Maximum egy paraméter adható meg!");
        exit(1);
    }
    else if (argc == 1)
    {
        puts("Hello World!");
    }
    else if ((strcmp(argv[1], "Batman") == 0)
             || (strcmp(argv[1], "Robin") == 0))
    {
        puts("Denevérveszély!");
    }
    else
    {
        printf("Hello %s!\n", argv[1]);
    }

    return 0;
}
