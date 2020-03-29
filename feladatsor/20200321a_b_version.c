#include <stdio.h>

#define SIZE 26 + 1    // '\0' miatt plusz 1

int main()
{
    char abc[SIZE];
    for (int i = 0; i < SIZE - 1; ++i)
    {
        abc[i] = 'a' + i;
    }
    abc[SIZE - 1] = '\0';

    printf("%s\n", abc);

    return 0;
}
