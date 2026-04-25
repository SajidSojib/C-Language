#include <stdio.h>
int main()
{

    int  n, x=1;

    printf("number of row: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        
        for (int j = 1; j <= i; j++)
        {
            printf("%d ",x);
            x++;
        }
        printf("\n");
    }
    return 0;
}