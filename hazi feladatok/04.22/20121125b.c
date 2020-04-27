#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
#define BUFFER 500

typedef struct
{
    char keresztnev[50];
    int eletkor;
    char szak[50];
} HALLGATO;

/*
    Hallgatói adatok feltöltése.
*/
int hallgatok_feltoltese(HALLGATO h[], const char *file, const char *separator)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba a %s fájl megnyitásakor!\n", file);
        exit(1);
    }

    char sor[BUFFER];
    char *p = sor;
    int i = 0;

    while (fgets(sor, BUFFER, fp) != NULL)
    {
        p = strtok(sor, separator);
        strcpy(h[i].keresztnev, p);
        p = strtok(NULL, separator);
        h[i].eletkor = atoi(p);
        p = strtok(NULL, separator);
        strcpy(h[i].szak, p);
        h[i].szak[strlen(h[i].szak) - 1] = '\0';
        ++i;
    }

    fclose(fp);

    return i;
}

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

/*
    Gyorsrendezés algoritmusa
*/
void quicksort(char *a[], int bal, int jobb)
{
    char *x, *temp;
    int i, j;

    i = bal;
    j = jobb;
    x = strdup(a[(bal + jobb) / 2]);
    while (i <= j)
    {
        while (strcmpi(a[i], x) < 0)
            ++i;
        while (strcmpi(a[j], x) > 0)
            --j;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            /* */
            ++i;
            --j;
        }
    }

    if (bal < j)
        quicksort(a, bal, j);
    if (i < jobb)
        quicksort(a, i, jobb);
}

/*
    Hallgató nevét valamely adat alapján kiír.
*/
void hallgatot_kiir(const int meret, HALLGATO h[], const char *szak)
{
    int index = 0;
    char *t[SIZE];
    for (int i = 0; i < meret; ++i)
    {
        if (strcmpi(szak, h[i].szak) == 0)
        {
            t[index] = h[i].keresztnev;
            t[index][0] = toupper(t[index][0]);
            ++index;
        }
    }

    quicksort(t, 0, index - 1);

    for (int i = 0; i < index; ++i)
    {
        printf("%s%s", t[i], (i + 1) < index ? ", " : "\n");
    }
}

/*
    A főprogram:
    Beolvas egy CSV fájlt, majd kiírja az stdout-ra a
    PTI-s hallgatók nevét ábécésorrendben, nagy kezdőbetűkkel ellátva.
*/
int main(void)
{
    char *fajl = "nevek.csv";
    HALLGATO hallgatok[SIZE];
    char *elvalasztojel = ",";

    int hossz = hallgatok_feltoltese(hallgatok, fajl, elvalasztojel);

    hallgatot_kiir(hossz, hallgatok, "pti");

    return 0;
}
