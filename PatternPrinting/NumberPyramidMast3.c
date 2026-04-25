// REVISE REVISE REVISE REVISE



#include <stdio.h>
int main()
{
    int n,min;
    printf("line number: ");
    scanf("%d", &n);
    int nst = 2 * n - 1;
   
        for (int i = 1; i <= nst; i++)
        {
            for (int j = 1; j <= nst; j++)
            {
               int a=i,b=j;
                if(a>n) a=nst+1-a;
                if(b>n) b=nst+1-b;

               if(a<b) min=a;
               else min=b;

               printf("%d ",n+1-min);                
            }

             printf("\n");
        }
   
    return 0;
}



