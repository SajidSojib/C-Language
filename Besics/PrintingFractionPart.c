#include<stdio.h>
int main(){
     float x;
    printf ("Enter a desimal number: ");
   
    scanf ("%f",&x);
    int y=x;
  float  z=x-y;
    printf ("Fraction part of this number is: %f",z);

    return 0;
}