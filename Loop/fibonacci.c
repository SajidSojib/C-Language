// 1 1 2 3 5 8 13 21...

#include <stdio.h>
int main()
{

    int n, y = 1, x = 1, sum=1;

    printf("enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= (n - 2); i++)
    {
        sum = x + y;
        x = y;
        y = sum;
    }
    printf("the %dth fibonacci is %d",n, sum);
    return 0;
}