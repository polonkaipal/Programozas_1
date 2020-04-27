#include <stdio.h>
#include <string.h>
#include <ctype.h>

void kisbetus(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = tolower(s[i]);
        ++i;
    }
}

int strcmpi(const char *s1, const char *s2)
{
    char *a = strdup(s1);
    char *b = strdup(s2);
    kisbetus(a);
    kisbetus(b);
    return strcmp(a, b);
}

void hasonlit(const char *s1, const char *s2)
{
    int eredmeny = strcmpi(s1, s2);
    if (eredmeny < 0)
    {
        printf("Kisebb %s mint %s\n", s1, s2);
    }
    else if (eredmeny > 0)
    {
        printf("Nagyobb %s mint %s\n", s1, s2);
    }
    else
    {
        printf("Egyenlő\n");
    }
}

int main()
{
    char *a = "ez";
    char *b = "EZ";
    char *c = "az";
    char *d = "íz";

    printf("%s és %s\n", a, b);
    hasonlit(a, b);
    printf("\n%s és %s\n", a, c);
    hasonlit(a, c);
    printf("\n%s és %s\n", a, d);
    hasonlit(a, d);

    return 0;
}
