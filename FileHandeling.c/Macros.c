#include<stdio.h>
#define pi 3.14159265359
// float area(float r){
//     return pi*r*r;
// }

#define area(r) (pi*r*r)
int main(){

    printf("%f",area(10));

    return 0;
}