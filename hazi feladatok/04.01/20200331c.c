#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

#define FALSE 0
#define TRUE 1

int legalabb_8_karakter(string szo)
{
    return strlen(szo) >= 8 ? TRUE : FALSE;
}

int tartalmaz_kisbetut(string szo)
{
    int i = 0;
    while (szo[i] != '\0')
    {
        if (islower(szo[i]) == 0)
        {
            return TRUE;
        }
        ++i;
    }
    return FALSE;
}

int tartalmaz_nagybetut(string szo)
{
    int i = 0;
    while (szo[i] != '\0')
    {
        if (isupper(szo[i]) == 0)
        {
            return TRUE;
        }
        ++i;
    }
    return FALSE;
}

int tartalmaz_szamjegyet(string szo)
{
    int i = 0;
    while (szo[i] != '\0')
    {
        if (isdigit(szo[i]) == 0)
        {
            return TRUE;
        }
        ++i;
    }
    return FALSE;
}

int eros_jelszo(string szo)
{
    if ((legalabb_8_karakter(szo) == 1) && (tartalmaz_kisbetut(szo) == 1)
        && (tartalmaz_nagybetut(szo) == 1) && (tartalmaz_szamjegyet(szo) == 1))
    {
        return TRUE;
    }
    return FALSE;
}

int main()
{
    printf("Adj meg jelszavakat '*' végjelig!\n\n");

    string szo = get_string("jelszó: ");
    do
    {
        printf("%s jelszó\n\n", eros_jelszo(szo) ? "erős" : "gyenge");
        szo = get_string("jelszó: ");
    }
    while (strcmp(szo, "*") != 0);


    return 0;
}
