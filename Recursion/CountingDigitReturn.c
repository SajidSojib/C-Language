#include <stdio.h>
int count(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return 1 + count(x / 10);
}

int main()
{
    int m;
    printf("enter number: ");
    scanf("%d", &m);

    printf("%d", count(m));
    return 0;
}