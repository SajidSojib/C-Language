#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ascii(int n,char s,char h,char d)
{
    if(n==0) return;
    ascii(n-1,s,d,h);
    printf("%c -> %c\n",s,d);
    ascii(n-1,h,s,d);
}

int fun(int x,int y,int a, int b)
{
    if(x==0 && y==0) return 1;
    if(x<0 || y<0) return 0;

    return fun(x-1,y,a+1,b)+fun(x,y-1,a,b+1);
    
}
int main() 
{
    int n=3,m=3;
    ascii(n,'A','B','C');
    // printf("%d",fun(n,m,0,0));
    return 0;
}
