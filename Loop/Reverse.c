#include <stdio.h>
int main()
{

    int n,sum=0;
    printf("enter a number: ");
    scanf("%d", &n);

    for (int i; n != 0; n=n/10)
    {
     i = n%10;
     sum=sum*10+i;
    
    }
    // int LT;
    // while (n!=0)
    // {
    //     LT=n%10;
    //     sum=(sum*10+LT);
    //     n=n/10;
    // }
    

printf("reverse of the number: %d",sum);
    return 0;
}