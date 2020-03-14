#include "prog1.h"
#include <stdio.h>
#include <string.h>

/*

Bemenet: sztringeket tartalmazó tömb. Számoljuk meg, hogy a bemenetben
hány olyan sztring van, melynek a hossza legalább 2 s az
első karaktere egyezik az utolsó karakterével. A visszatérési
érték ezen feltételeket kielégítő sztringek száma legyen.

Példák (Python kóddal, majd át kell írni C-be):

match_ends(["aba", "xyz", "aa", "x", "bbb"])    ->  3
match_ends(["", "x", "xy", "xyx", "xx"])        ->  2
match_ends(["aaa", "be", "abc", "hello"])       ->  1

*/

int match_ends(int n, string words[])
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int l = strlen(words[i]);
        if (l >= 2 && words[i][0] == words[i][l - 1])
            ++count;
    }
    return count;
}

void print_array(int l, const string array[])
{
    for (int i = 0; i < l; ++i)
        puts(array[i]);
    puts("");
}

int main()
{
    string szavak1[] = { "aba", "xyz", "aa", "x", "bbb" };
    int szavak1_meret = 5;
    string szavak2[] = { "", "x", "xy", "xyx", "xx" };
    int szavak2_meret = 5;
    string szavak3[] = { "aaa", "be", "abc", "hello" };
    int szavak3_meret = 4;

    // match_ends() meghívása itt...
    printf("%d\n", match_ends(szavak1_meret, szavak1));
    print_array(szavak1_meret, szavak1);

    printf("%d\n", match_ends(szavak2_meret, szavak2));
    print_array(szavak2_meret, szavak2);

    printf("%d\n", match_ends(szavak3_meret, szavak3));
    print_array(szavak3_meret, szavak3);

    return 0;
}
