#include <stdio.h>
int main()
{
    int n;
    printf("enter a number: ");
    scanf("%d", &n);
   // a+(n-1)d
    for (int i = 1; i <=2*n-1 ; i=i+2)
        {
            printf ("%d ",i);
        }    
    
    // for (int i = 4; i <= 3 * n + 1; i = i + 3)
    // {
    //     printf("%d ", i);
    // }

    return 0;
}