#include <stdio.h>
int main()
{
    int n;
    printf("line number: ");
    scanf("%d", &n);
    int nst = n - 1,
        nsp = 1;
    int x = 65;
    char s = (int)x;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        printf("%c", s++);
    }
    printf("\n");
    for (int i = 1; i <= n - 1; i++)
    {
        int x = 65;
        char ch = (int)x;
        for (int j = 1; j <= nst; j++)
        {
            printf("%c", ch++);
        }
        for (int k = 1; k <= nsp; k++)
        {
            printf(" ");
            ch++;
        }
        for (int j = 1; j <= nst; j++)
        {
            printf("%c", ch++);
        }
        nst--;
        nsp += 2;
        printf("\n");
    }

    return 0;
}