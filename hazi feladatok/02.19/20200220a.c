#include <stdio.h>

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    for (int i = 4; i < n + 1; i += 4)
    {
        printf("%d\n", i);
    }
    
    return 0;
}