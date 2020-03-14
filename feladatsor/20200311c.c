#include <stdio.h>
#include "prog1.h"
#include <string.h>
#define FALSE 0
#define TRUE 1

int is_palindrome(const string s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return FALSE;
        ++i;
        --j;
    }
    return TRUE;
}

int main()
{
    printf("%d\n", is_palindrome("abba"));
    printf("%d\n", is_palindrome("aladar"));
    printf("%d\n", is_palindrome(""));

    return 0;
}
