#include<stdio.h>
int main(){
    int n,sum=0;
    printf("array size: ");
    scanf("%d",&n);
    int mark[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter marks of %dth student\n",i+1);
        scanf("%d",&mark[i]);
        sum=sum+mark[i];
    }
    printf("sum of the elements: %d",sum);
    
    return 0;
}