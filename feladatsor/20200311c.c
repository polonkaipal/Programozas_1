#include <stdio.h>
#include "prog1.h"
#include <string.h>

int is_palindrome(const string s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return 0;
        ++i;
        --j;
    }
    return 1;
}

int main()
{
    printf("%d\n", is_palindrome("abba"));
    printf("%d\n", is_palindrome("aladar"));
    printf("%d\n", is_palindrome(""));

    return 0;
}
