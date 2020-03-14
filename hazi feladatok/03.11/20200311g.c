#include <stdio.h>
#include "prog1.h"
#include <string.h>

int rfind_char(const string s, char c)
{
    int l = strlen(s);
    for (int i = l - 1; i > -l; --i)
        if (s[i] == c)
            return i;
    return -1;
}

int main()
{
    printf("%d\n", rfind_char("Abba", 'b'));
    printf("%d\n", rfind_char("Abba", 'a'));
    printf("%d\n", rfind_char("Abba", 'x'));
    printf("%d\n", rfind_char("Aladar", 'a'));

    return 0;
}
