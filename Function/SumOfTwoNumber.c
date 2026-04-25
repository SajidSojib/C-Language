#include <stdio.h>
int add(int x, int y)
{
    return x + y;
}

int main()
{
    int a, b;
    printf("first number: ");
    scanf("%d", &a);
    printf("second number: ");
    scanf("%d", &b);

    int sum = add(a, b);
    printf("the sum is %d", sum);

    return 0;
}