#include <stdio.h>
int main()
{
    int  x, y, z;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d",&y);
    printf("Enter third number: ");
    scanf("%d", &z);
    if (x>y)
    {
        if (x>z)
        {
            printf ("%d is the greatest",x);
        }
        else{
          printf ("%d is the greatest",z);   
        }
         
    }
    else{ if (y>z)
    {
        printf ("%d is the greatest",y);
        }
        else{
          printf ("%d is the greatest",z);    
    }
    }
    return 0;
}