#include <stdio.h>
#include "prog1.h"

int my_strlen(const string s)
{
    int i = 0;
    while(s[i] != '\0')
        ++i;
    return i;
}

int main()
{
    printf("%d\n", my_strlen("Abba"));
    printf("%d\n", my_strlen("Cecil"));
    printf("%d\n", my_strlen(""));

    return 0;
}
