#include<stdio.h>

int fibonacci(int m){
    if (m==1 || m==2) return 1;  
    return fibonacci(m-1)+fibonacci(m-2);
}

int main(){
    int a;
    printf("enter base: ");
    scanf("%d",&a);
    
    printf("the fibonacci number is %d",fibonacci(a));

    return 0;
}