#include<stdio.h>
int main (){
    int x,y,z,r;
    printf ("First number: ");
    scanf("%d",&x);
    printf ("Second Number: ");
    scanf("%d",&y);

   z = x / y;
r=x-(y*z);
    printf ("reminder: %d",r);

    return 0;
} 