#include <stdio.h>
#include "prog1.h"
#include <string.h>

int char_count(const string s, char c)
{
    int count = 0, l = strlen(s);
    for (int i = 0; i < l; ++i)
        if (s[i] == c)
            ++count;
    return count;
}

int main()
{
    printf("%d\n", char_count("Abba", 'b'));
    printf("%d\n", char_count("Abba", 'a'));
    printf("%d\n", char_count("Abba", 'x'));

    return 0;
}
