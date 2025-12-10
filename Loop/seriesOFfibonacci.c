#include <stdio.h>
int main()
{

    int n, y = 1, x = 1, sum=1;

    printf("enter a number: ");
    scanf("%d", &n);
    printf("%d\n%d\n", x,y);
    for (int i = 1; i <= n-2; i++)
    {
        sum = x + y;
        x = y;
        y = sum;
         printf("%d\n",sum);
    }
  
    return 0;
}