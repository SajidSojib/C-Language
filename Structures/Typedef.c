// typedef OldName NewName 

#include<stdio.h>
#include<string.h>

typedef float RealNumber;
typedef int integer;
typedef int* pointer;

int main(){
    RealNumber x=5.678;
    integer y=15;

    printf("%f\n",x);
    printf("%d",y);

    // int* a=&m,b=&n;  // int* a and int b
    int m=5,n=7;
    pointer a=&m,b=&n;
    printf("\n%p\n",a);
    printf("%p\n",b);

    return 0;
}

