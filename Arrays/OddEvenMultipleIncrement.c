#include<stdio.h>
int main(){
    int n;
    printf("enter size: ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
        
    }
    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        {
            printf("%d ",arr[i]+10);
        }
        else printf("%d ",arr[i]*2);
    }
    
    
    return 0;
}