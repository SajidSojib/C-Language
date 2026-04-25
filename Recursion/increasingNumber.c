#include <stdio.h>

void increasing(int n,int x)
{   
    if (x > n)
        return;
    printf("%d\n", x);
    return increasing(n,x+1);   
}

int main()
{
    int n;
    printf("enter number: ");
    scanf("%d", &n);

    increasing(n,1);

    return 0;
}