#include<stdio.h>
void reverse(int arr[],int x,int n){
    
    for (int i=x, j=n; i < j; i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return;
}
int main(){
    int n,swape;
    printf("reverse time: ");
    scanf("%d", &swape);
    printf("array size: ");
    scanf("%d", &n);
    int arr[n];
    swape=swape%n;
    
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
    }

    reverse(arr,0,n-1);
    reverse(arr,0,swape-1);
    reverse(arr,swape,n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}