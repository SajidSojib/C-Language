#include<stdio.h>
int main(){
    int n,sumEVEN=0,sumODD=0;
    
    printf("enter size: ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
        if (i%2==0) sumEVEN=sumEVEN+arr[i];
        else sumODD=sumODD+arr[i];    
    }
    printf("difference of even and odd elements is %d",sumEVEN-sumODD);

    return 0;
}