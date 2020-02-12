#include <stdio.h>

int main()
{
  int a, b;
  printf("Add meg a teglalap egyik oldalat: ");
  scanf("%d", &a);
  
  printf("Add meg a teglalap masik oldalat: ");
  scanf("%d", &b);
  
  printf("A teglalap kerulete: %d\n", 2 * (a + b));
  printf("A teglalap terulete: %d\n", a * b);
  
  return 0;
}