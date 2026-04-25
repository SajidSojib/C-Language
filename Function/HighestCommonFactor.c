#include<stdio.h>

int min(int p,int q){
    int r;
    if (p>q) return q;
    else return p;
}
int gcd(int x,int y){// GREATEST COMMON DIVISOR
    int hcf;
    for (int i = min(x,y); i >= 1; i--)
    {
        if (x%i==0 && y%i==0)
        {
            hcf=i;
            break;
        }
            
    }
    
    return hcf;  
}
int main(){
    int a,b;
    printf("first number: ");
    scanf("%d",&a);
    printf("second number: ");
    scanf("%d",&b);
    
    int hcf=gcd(a,b);
    printf("the HCF/GCD of %d and %d is: %d",a,b,hcf);
    return 0;
}