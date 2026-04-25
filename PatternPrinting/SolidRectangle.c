#include <stdio.h>
int main()
{

    int y, x;

    printf("number of row: ");
    scanf("%d", &x);
    printf("number of ccollum: ");
    scanf("%d", &y);
    for (int i = 1; i <= x; i++)
    {
        for (int i = 1; i <= y; i++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}