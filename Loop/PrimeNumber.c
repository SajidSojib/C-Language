#include <stdio.h>
int main()
{
    int n;
    printf("enter a number: ");
    scanf("%d", &n);
    int a = 0,b=0;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            a = 1;
            break;
        }
        b++;
    }
    if (a == 1)
        printf("composite number %d",b);
    else
        printf("prime number %d",b);
    
    return 0;
}