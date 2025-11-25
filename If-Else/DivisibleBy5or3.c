#include<stdio.h>
int main (){
    int n;
    printf ("Enter a number: ");
    scanf ("%d",&n);
    if ((n%3==0 || n%5==0) && n%15!=0)
    {
        printf ("the number is divisible by 5 or 3 but not 15");
    
    }
    else{
        printf ("the number is not matching the requirment");
    }

    return 0;
}