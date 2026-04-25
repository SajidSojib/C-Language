#include<stdio.h>

int powerlog(int m,int n){
    if (n==0)  return 1;

    int x=powerlog(m,n/2);
    
    if(n%2!=0) return x*x*m;
    else return x*x;  
}

int main(){
    int a,b;
    printf("enter base: ");
    scanf("%d",&a);
    printf("enter power: ");
    scanf("%d",&b);

    int x=powerlog(a,b);

    printf("%d to the power %d is %d",a,b,x);


    return 0;
}