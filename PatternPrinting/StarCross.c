#include <stdio.h>
int main()
{

    int n;
    printf("number of row and collum: ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        for (int i = 1; i <= n; i++)
    {
        
        for (int j = 1; j <= n; j++)
        {
            if(i==j || j==n+1-i) printf("* ");
            else printf("  ");
        }      

        printf("\n");
    }
    }
    else
        printf("not possible");

    return 0;
}