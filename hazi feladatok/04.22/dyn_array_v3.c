#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 2
#define MULTIPLIER 1.5

typedef struct
{
    int *elems;   // a dinamikusan lefoglalt tömbre mutat
    int length;   // a betett elemek száma
    int capacity; // a tömb fizikai kapacitása
                  // capacity >= length
} DynArray;

void mem_error_exit()
{
    fprintf(stderr, "Error: cannot allocate memory\n");
    exit(1);
}

DynArray *da_create()
{
    DynArray *result = malloc(sizeof(DynArray));
    if (result == NULL)
    {
        mem_error_exit();
    }

    result->elems = malloc(INITIAL_CAPACITY * sizeof(int));
    if (result->elems == NULL)
    {
        mem_error_exit();
    }
    result->length = 0;
    result->capacity = INITIAL_CAPACITY;

    return result;
}

void da_append(DynArray *self, int data)
{
    if (self->length == self->capacity)
    {
        int new_capacity = (int)(MULTIPLIER * self->capacity);
        self->elems = realloc(self->elems, new_capacity * sizeof(int));
        puts("# újraallokálás történt");
        if (self->elems == NULL)
        {
            mem_error_exit();
        }
        self->capacity = new_capacity;
    }
    //
    self->elems[self->length] = data;
    self->length += 1;
}

void *da_destroy(DynArray *self)
{
    free(self->elems);
    free(self);
    //
    return NULL;
}

/*
    Új függvény, amely kitörli a dinamikus tömbben tárolt összes elemet.
*/
void da_clear(DynArray *li)
{
    li->elems = realloc(li->elems, INITIAL_CAPACITY * sizeof(int));
    li->length = 0;
    li->capacity = INITIAL_CAPACITY;
}

void get_da(DynArray *self)
{
    for (int i = 0; i < self->length; ++i)
    {
        printf("%d ", self->elems[i]);
    }
    puts("");
}

int main()
{
    DynArray *li = da_create();

    // li.append(1);
    da_append(li, 1);
    da_append(li, 2);
    da_append(li, 3);
    for (int i = 4; i <= 20; ++i)
    {
        da_append(li, i);
    }

    /*-----------------*/ //
    get_da(li);           //
                          //
    da_clear(li);         //
                          //
    da_append(li, 1);     //    Saját kódrész
    da_append(li, 2);     //
    da_append(li, 3);     //
                          //
    get_da(li);           //
    /*-----------------*/ //

    li = da_destroy(li);

    printf("%p\n", li);

    return 0;
}
