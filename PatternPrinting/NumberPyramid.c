#include <stdio.h>
int main()
{

    int n, nst = 1;

    printf("number of row: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int x = 1;
        for (int k = 1; k <= n - i; k++)
        {

            printf("  ");
        }
        for (int j = 1; j <= nst; j++)
        {

            printf("%d ", x++);
        }

        nst = nst + 2;
        printf("\n");
    }

    return 0;
}