#include <stdio.h>

#define SIZE 26

int main()
{
    char abc[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        abc[i] = 'a' + i;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%c ", abc[i]);
    }
    puts("");

    return 0;
}
