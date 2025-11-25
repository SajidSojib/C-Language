#include <stdio.h>
int main()
{
    int n, x, y, z;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d"), &y;
    printf("Enter third number: ");
    scanf("%d", &z);
    printf("Enter forth number: ");
    scanf("%d", &n);
    if (x > y && x < z && x > n)
    {
        printf("the greatest number is:%d", x);
    }
    if (y > x && y > z && y > n)
    {
        printf("the greatest number is:%d", y);
    }
    if (z > y && z > x && z > n)
    {
        printf("the greatest number is:%d", z);
    }
    // if (n>x && n>y && n>z)
    else
    {
        printf("the greatest number is: %d", n);
    }

    return 0;
}