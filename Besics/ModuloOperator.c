#include<stdio.h>
int main (){
    int x,y,z,r;
    printf ("First number: ");
    scanf("%d",&x);
    printf ("Second Number: ");
    scanf("%d",&y);
    r=x%y;
    printf ("Reminder: %d",r);
    return 0;}