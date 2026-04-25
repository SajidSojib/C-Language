#include<stdio.h>
int main(){
    int n,x,y=0;
    printf("enter number: ");
    scanf("%d",&x);
    printf("enter size: ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
        if (x<arr[i]) y++;    
    }
    printf("total %d elements are greater than the number %d",y,x);

    return 0;
}