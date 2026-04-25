//REVIISE REVISE REVISE

#include<stdio.h>
void reverse(int arr[],int n){
    
    for (int i=0, j=n-1; i < j; i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    

    return;
}
int main(){
    int n;
    printf("array size: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
    }
    reverse(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}