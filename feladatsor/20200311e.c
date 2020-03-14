#include <stdio.h>
#include "prog1.h"
#include <string.h>
#define FALSE 0
#define TRUE 1

int contains_char(const string s, char c)
{
    int l = strlen(s);
    for (int i = 0; i < l; ++i)
        if (s[i] == c)
            return TRUE;
    return FALSE;
}

int main()
{
    printf("%d\n", contains_char("Abba", 'b'));
    printf("%d\n", contains_char("Abba", 'x'));

    return 0;
}
