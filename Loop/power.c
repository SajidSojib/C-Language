#include <stdio.h>
int main()
{

    int x, y, z=1;
  

    printf("enter a number: ");
    scanf("%d", &x);
    printf("enter a power: ");
    scanf("%d", &y);
    for (int i = 1; i <= y; i++)
    {
        z=x*z;
    }
    printf("X to the power of Y is: %d",z);
    return 0;
}