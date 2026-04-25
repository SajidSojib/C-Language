#include <stdio.h>
void prime(int i)
{
    int a = 0;
    for (int j = 2; j < i ; j++)
    {
        if (i % j == 0)
        {
            a = 1;
            break;
        }
    }
    if (a == 0)
        printf("%d ", i);
    return;
}

void factor(int n)
{

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            prime(i);
    }

    return;
}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    printf("prime factors are: ");
    factor(n);
    return 0;
}