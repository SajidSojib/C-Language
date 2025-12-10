// 1 - 2 + 3 - 4 + 5 - 6....n

#include <stdio.h>
int main()
{

    int n, sum = 0;
    printf("enter a number: ");
    scanf("%d", &n);

    // for (int i = 0; i <= n; i++)
    // {
    //     if (i % 2 != 0)
    //         sum = sum + i;
    //     else
    //         sum = sum - i;
    // }

    if (n%2!=0)
    {
        sum=-n/2+n;
    }
    else sum=-n/2;

    printf("sum of the series: %d", sum);
    return 0;
}