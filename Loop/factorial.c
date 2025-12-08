#include <stdio.h>
int main()
{

     int n, factorial=1,i=1;
  
    printf("enter a number: ");
    scanf("%d", &n);

    while (i<=n)
        { 
        factorial=factorial*i;
        i++;
    }
    printf("factorial of the number is: %d",factorial);
    return 0;
}