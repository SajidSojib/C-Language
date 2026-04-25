#include<stdio.h>
int factorial(int x){
    int fact=1;
    for (int i = 1; i <= x; i++)
    {
        fact=fact*i;
    }
    return fact;
    
}
int main(){
    int n,r;
    printf("enter n: ");
    scanf("%d",&n);
     printf("enter r: ");
    scanf("%d",&r);
    int nfact =factorial(n),
    rfact=factorial(r),
    nrfact=factorial(n-r);

    int ncr=nfact/(rfact*nrfact);

    printf("%d",ncr);

    return 0;
}