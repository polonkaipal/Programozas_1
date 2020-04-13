#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define SIZE 500

/*
    Ellenőrzi a kapott stringre az alábbiakat:
    - csak alfanumerikus karakterek (a-z, A-Z, 0-9) szerepelnek benne, ill. az aláhúzás jel ('_')
    - alfanumerikus karakterrel vagy aláhúzás jellel ('_') kezdődik [vagyis nem szerepelhet számjegy az elején]
    - legalább egy karakter hosszú

    Ha igaz mindegyik feltétel 1-et ad vissza, küldönben 0-t.
*/
int is_valid_c_identifier(const char *input)
{
    if (strcmp(input, "") == 1)
    {
        return 0;
    }

    bool contains_only_alfanumeric_caracters_and_underline = true;
    bool does_not_begin_numeric_caracter = false;
    bool is_greater_than_one = false;

    int i = 0;
    while (input[i] != '\0')
    {
        if ((isalnum(input[i]) == 0) && (input[i] != '_'))
        {
            contains_only_alfanumeric_caracters_and_underline = false;
            ++i;
            break;
        }
        ++i;
    }

    if (isalpha(input[0]) || (input[0] == '_'))
    {
        does_not_begin_numeric_caracter = true;
    }

    is_greater_than_one = i > 0 ? true : false;

    if (contains_only_alfanumeric_caracters_and_underline && does_not_begin_numeric_caracter && is_greater_than_one)
    {
        return 1;
    }
    return 0;
}

/*
    A főprogram:
    A felhasználótól kért azonosítokról ('*' végjelig) eldönti,
    hogy azok érvényes azonosítók-e a C nyelvben.
*/
int main()
{
    char *szo;
    char s[SIZE];
    puts("Adj meg sztringeket '*' végjelig!");
    while (1)
    {
        printf("Input: ");
        fgets(s, SIZE, stdin);
        szo = s;
        szo[strlen(szo) - 1] = '\0';
        if (strcmp(szo, "*") == 0)
        {
            break; // vagy: return 0;
        }
        if (is_valid_c_identifier(szo) == 1)
        {
            puts("YES\n");
        }
        else
        {
            puts("NO\n");
        }
    }

    return 0;
}
