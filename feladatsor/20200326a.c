#include <stdio.h>
#include <stdlib.h>

void tomb_kiir(int meret, const int tomb[])
{
    for (int i = 0; i < meret; ++i)
    {
        printf("%d%s", tomb[i], i + 1 != meret ? ", " : "\n");
    }
}

int main()
{
    puts("Hány db számot szeretnél bevinni?");
    int db, aktulalis;
    scanf("%d", &db);
    int tomb_eredeti[db], tomb_abszolut[db];
    for (int i = 0; i < db; ++i)
    {
        printf("%d. szám: ", i + 1);    // A ciklus 0-tól kezdődik
        scanf("%d", &aktulalis);
        tomb_eredeti[i] = aktulalis;
        // A rövidebb megoldás, de a feladat nem ezt kérte!
        //tomb_abszolut[i] = abs(aktulalis);
    }
    for (int i = 0; i < db; ++i)
    {
        tomb_abszolut[i] = abs(tomb_eredeti[i]);
    }
    
    puts("");
    printf("A bevitt számok abszolútértékei: ");
    tomb_kiir(db, tomb_abszolut);
    printf("A megadott számok: ");
    tomb_kiir(db, tomb_eredeti);

    return 0;
}
