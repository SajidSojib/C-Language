#include <stdio.h>
int count(int x)
{
    if (x == 0) return -1;
 
    return 2+count(x-1);
}

int main()
{
    int m;
    printf("enter number: ");
    scanf("%d", &m);

     printf("%d",count(m));

    return 0;
}