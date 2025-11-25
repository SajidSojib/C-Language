#include<stdio.h>
int main (){
    int x,z,y;
    printf ("Enter 1st number: ");
    scanf ("%d",&x);
    printf ("Enter 2nd number: ");
    scanf ("%d",&y);
     printf ("Enter 3rd number: ");
    scanf ("%d",&z);
    
    if ((x+y)>z && (y+z)>x && (x+z)>y)
    {
        printf ("Valid Triangle");
    
    }
    else{
        printf ("invalid triangle");
    }

    return 0;
}