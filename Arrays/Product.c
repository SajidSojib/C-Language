#include<stdio.h>
int main(){
    int n,product=1;
    printf("array size: ");
    scanf("%d",&n);
    int mark[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter marks of %dth student\n",i+1);
        scanf("%d",&mark[i]);
        product=product*mark[i];
    }
    printf("sum of the elements: %d",product);
    
    return 0;
}