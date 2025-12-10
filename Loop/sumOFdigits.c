#include <stdio.h>
int main()
{

    int n,sum=0;
    printf("enter a number: ");
    scanf("%d", &n);

   for (int LT ; n != 0; n=n/10)
   {
    LT=n%10;
    sum=sum+LT;
   }
   
printf("sum of the digits: %d",sum);
    return 0;
}