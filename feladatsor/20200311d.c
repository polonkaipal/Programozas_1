#include <stdio.h>
#include "prog1.h"
#include <string.h>

int find_char(const string s, char c)
{
    int l = strlen(s);
    for (int i = 0; i < l; ++i)
        if (s[i] == c)
            return i;
    return -1;
}

int main()
{
    printf("%d\n", find_char("Abba", 'b'));
    printf("%d\n", find_char("Abba", 'a'));
    printf("%d\n", find_char("Abba", 'x'));

    return 0;
}
