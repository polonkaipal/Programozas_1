#include <stdio.h>
#define X 1
#define Y 100

void fizzbuzz(int x, int y)
{
    for (int i = x; i <= y; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("fizzbuzz\n");
        
        else if (i % 3 == 0)
            printf("fizz\n");
        
        else if (i % 5 == 0)
            printf("buzz\n");
        
        else
            printf("%d\n", i);
    }
}

int main()
{
    fizzbuzz(X, Y);

    return 0;
}
