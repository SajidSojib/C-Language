#include <stdio.h>
#include<limits.h>
int main()
{
    int n, max = INT_MIN;//smallest number
    printf("array size: ");
    scanf("%d", &n);
    int mark[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n", i + 1);
        scanf("%d", &mark[i]);
        if (max < mark[i])
            max = mark[i];
    }

    printf("the maximum elements: %d", max);

    return 0;
}