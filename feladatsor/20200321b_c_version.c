#include <stdio.h>
#include <string.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    if (argc == 1)
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
