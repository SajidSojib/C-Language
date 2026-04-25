#include <stdio.h>
int main()
{
    int n,nst=1;
    printf("number of row and collum: ");
    scanf("%D", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n-i; j++)
      {
        printf("  ");
      }
      for (int j = 1; j <= nst; j++)
      {
        printf("* ");
      }
      
       nst=nst+2;
        printf("\n");
    }
    

    return 0;
}