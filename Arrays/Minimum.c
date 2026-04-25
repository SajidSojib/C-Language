#include <stdio.h>
#include<limits.h>
int main()
{
    int n, min = INT_MAX;//smallest number
    printf("array size: ");
    scanf("%d", &n);
    int mark[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n", i + 1);
        scanf("%d", &mark[i]);
        if (min > mark[i])
            min = mark[i];
    }

    printf("the minimum elements: %d", min);

    return 0;
}