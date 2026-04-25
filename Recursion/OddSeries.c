#include <stdio.h>
void count(int x,int y)
{
    if (x == 0) return;

    printf("%d ",y);
    count(x-1,y+2);
    
    return;
}

int main()
{
    int m;
    printf("enter number: ");
    scanf("%d", &m);

     count(m,1);

    return 0;
}