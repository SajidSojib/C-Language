#include <stdio.h>
int main()
{
    int x, y;
    printf("number of row: ");
    scanf("%d", &x);
    printf("number of colum: ");
    scanf("%d", &y);
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (i==1 || j==1 || i==x || j==y)
            {
                printf("* ");
            }
            else printf("  ");
        }

        printf("\n");
    }

    return 0;
}