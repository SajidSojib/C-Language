#include <stdio.h>
int main()
{
    int n;
    printf("line number: ");
    scanf("%d", &n);
    int nst = n - 1,
        nsp = 1,
        y=1;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        printf("%d", y);
        if (i<n) y++;
        else y--;
        
    }
    printf("\n");
    for (int i = 1; i <= n - 1; i++)
    {
        int x = 1;
        for (int j = 1; j <= nst; j++)
        {
        printf("%d",x++);     
        }
        for (int k = 1; k <= nsp; k++)
        {
            printf(" ");
        }
        for (int k = 1; k <= nst; k++)
        {
        printf("%d",--x);
        }
        nst--;
        nsp += 2;
        printf("\n");
    }
    return 0;
}