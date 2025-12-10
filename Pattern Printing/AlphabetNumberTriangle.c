#include <stdio.h>
int main()
{

    int  n;

    printf("number of row and collum: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
       int x=1; 
        for (int j = 1; j <= i; j++)
        {
            if(i%2==0) printf("%c ",x+64);
            else printf ("%d ",x);
            x=x+1;
        }
        printf("\n");
    }
    return 0;
}