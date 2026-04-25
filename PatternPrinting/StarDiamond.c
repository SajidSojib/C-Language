#include <stdio.h>
int main()
{

    int n, nst = 1;
   
    printf("number of row: ");
    scanf("%d", &n);
     int ml = n / 2 + 1;
    int nsp = ml - 1;


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= nsp; j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= nst; k++)
        {
            printf("* ");
        }
        if (i < ml)
        {
            nst =nst+ 2;
            nsp--;
        }
        else
        {
            nst =nst- 2;
            nsp++;
        }
        printf("\n");
    }

    return 0;
}