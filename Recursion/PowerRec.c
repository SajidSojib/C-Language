#include<stdio.h>

int power(int m,int n){
    if (n==0)
    {
        return 1;
    }
    
    return m*power(m,n-1);;
}

int main(){
    int a,b;
    printf("enter base: ");
    scanf("%d",&a);
    printf("enter power: ");
    scanf("%d",&b);

    int x=power(a,b);

    printf("%d to the power %d is %d",a,b,x);


    return 0;
}