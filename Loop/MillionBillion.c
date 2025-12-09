#include <stdio.h>
int main()
{
    long n, temp = 0;
    scanf("%ld", &n);
    int count = 0;

    // reverse
    for (int i; n != 0; n = n / 10)
    {
        i = n % 10;
        temp = temp * 10 + i;
        count++;
    }
    n = temp;

    // add comma
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%ld", n % 10);
        n = n / 10;
        if (i != 0 && i % 3 == 0)
            printf(",");
    }

    return 0;
}