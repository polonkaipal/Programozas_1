#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 600
#define MAX 1000

void inicializal(const int m, int *t)
{
    for (int i = 0; i < N; ++i)
    {
        t[i] = 1;
    }
}

void szokes(const int m, int *t)
{
    for (int i = 2; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
        {
            t[j] = !t[j];
        }
    }
}

void keres(const int m, int *t)
{

    for (int i = 1; i < m; i++)
    {
        if (t[i] == 1)
        {
            printf("%d", i);
        }
    }
}

/*
    A főprogram:
    Szökés Alcatrazból
    Az alcatrazi börtön igazgatója a jövő héten ünnepli a 60. születésnapját.
    Eme különleges esemény alkalmából úgy döntött, hogy szabadon ereszt néhány elítéltet.
    Ehhez a következő játékot találta ki. A börtönben 600 cella van, ezek 1-től 600-ig vannak sorszámozva.
    Kezdetben minden cella zárva van. Az őr odamegy az első cellához, s minden egyes zárat kinyit.
    Ezután odamegy a 2. cellához, s minden második cella zárján fordít egyet (a nyitottat bezárja, a zártat kinyitja).
    Ezután veszi a 3. cellát, s minden harmadik cella zárján fordít egyet. Ezt megismétli az összes cellával.
    Akiknek a végén az ajtajuk nyitva marad, azok szabadon távozhatnak.

    Megoldás: Amelyik börtöncella négyzetszámú, annak lakója szabad.
*/
int main()
{
    int borton[N + 1] = {0};
    inicializal(N, borton);

    szokes(N, borton);

    keres(N, borton);
    puts("");
    return 0;
}
