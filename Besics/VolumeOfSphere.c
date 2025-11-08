#include<stdio.h>
int main(){
    
    int r;
    printf ("Redious: ");
    scanf ("%d",&r);
 
    float volume = 4*3.1416*r*r*r/3;
    
    printf("The volume is: %f",volume);

 return 0;
}       