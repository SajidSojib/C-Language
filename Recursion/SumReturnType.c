#include<stdio.h>

int sum(int n){
    if (n==1 || n==0) return n;
    return n+sum(n-1);
}

int main(){
    int n;
    printf("enter number: ");
    scanf("%d",&n);
    int total=sum(n);
printf("the sum of first %d number is %d",n,total);

    return 0;
}