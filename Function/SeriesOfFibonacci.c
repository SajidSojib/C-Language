#include<stdio.h>
void fibonacci(int n){
    int fib1=1,fib2;
    int sum=1;
    printf("%d ",fib1);
    for (int i = 1; i <= n-1; i++)
    { 
        fib2=fib1;
        fib1=sum;
        printf("%d ",sum);
        sum=fib1+fib2;  
    }
    return;
}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    fibonacci(n);
    return 0;
}
