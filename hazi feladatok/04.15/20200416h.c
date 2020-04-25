#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
#define SIZE 1000

// két elem cseréje egy tömbben
// arr: a tömb
// i: az egyik elem indexe
// j: a másik elem indexe
void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// vezérelem kiválasztás tömbrészből
// a kiválasztáson túl rendez is az elemeken
// arr: a feldolgozandó tömb
// low: a tömbrész alsó határa
// high: a tömbrész felső határa
int findpivot(int arr[], int low, int high)
{
    int pivot_index; // a vezérelem indexe
    int pivot;       // a vezérelem értéke
    int i;
    // a vezérelem elmozgatása a tömb végére
    swap(arr, (low + high) / 2, high);
    pivot = arr[high];
    // a vezérelemnél kisebbek mozgatása a tömb elejére
    pivot_index = low;
    for (i = low; i < high; ++i)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, pivot_index);
            ++pivot_index;
        }
    }
    // a vezérelem mozgatása a helyére
    swap(arr, high, pivot_index);
    return pivot_index;
}

/*
    Gyors rendezés algoritmusa
*/
// tömbrész rendezése
// arr: a rendezendő tömb
// low: rendezendő terület alsó határa
// high: a rendezendő terület felső határa
void quicksort(int arr[], int low, int high)
{
    int pivot_index;
    if (low < high)
    {
        // rendezni csak legalább két elem esetén kell
        pivot_index = findpivot(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

/*
    A bementre kapott fájlt rendezve írja ki a konzolra.
*/
void rendez(const char *file)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "A(z) %s szöveges fájlt nem lehet megnyitni!\n", file);
        exit(2);
    }

    char sor[SIZE];
    int *tomb = malloc(N * sizeof(int));
    if (tomb == NULL)
    {
        fprintf(stderr, "Nem sikerült legfoglalni a tárhelyet");
        exit(3);
    }

    int i = 0;
    while ((fgets(sor, SIZE, fp)) != NULL)
    {
        sor[strlen(sor) - 1] = '\0';
        tomb[i] = atoi(sor);
        ++i;
    }
    fclose(fp);

    quicksort(tomb, 0, N - 1);

    for (int i = 0; i < N; ++i)
    {
        printf("%d\n", tomb[i]);
    }

    free(tomb);
}

/*
    Parancssori argumentumként megkapja egy szöveges állomány nevét.
    A fájl soronként egy egész számot tartalmaz. A program olvassa be a számokat, rendezze őket,
    majd rendezett formában kiírja a számokat a képernyőre.
*/
int main(const int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Hiba! Nem adtál meg argumentumként egy szöveges fájlt!\n");
        exit(1);
    }

    char *file = argv[1];
    rendez(file);

    return 0;
}
