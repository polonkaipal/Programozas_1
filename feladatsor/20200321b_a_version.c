#include <stdio.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        puts("Hello World!");
    }
    else
    {
        printf("Hello %s!\n", argv[1]);
    }

    return 0;
}
