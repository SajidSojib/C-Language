#include<stdio.h>
int main (){
    int n;
    printf ("Marks: ");
    scanf ("%d",&n);

    if (90<=n&&n<=100){
        printf ("Excellent");
    } 
    else if (80<=n)
    {
        printf ("very good");
    }
    else if (70<=n)
    {
        printf ("good");
    }
      else if (60<=n)
    {
        printf ("can do better");
    }
      else if (50<=n)
    {
        printf ("average");
    }
      else if (40<=n)
    {
        printf ("bellow average");
    }
      else
    {
        printf ("fail");
    }

    return 0;

}