#include <stdio.h>
int main()
{

    int n, nst = 1;

    printf("number of row: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int x = 65;
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (int j = 1; j <= nst; j++)
        {
            printf("%c ", x++);
        }

        nst = nst + 2;
        printf("\n");
    }

    return 0;
}