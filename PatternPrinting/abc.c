#include <stdio.h>
#include <math.h>
int main()
{
    int n=4,m=6;
    int mid=n/2+1;
    int nsp=1;
    int nst=7;

    for (int i = 1; i <= nst; i++)
    {
        for (int j = 1; j <= nst; j++)
        {
            int a=(i>j)?j:i;
            if(a>n) a=nst-a;
            printf("%d ",a);
        }
        
        printf("\n");
    }
    
    
    return 0;
}