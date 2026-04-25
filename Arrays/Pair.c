#include<stdio.h>
int main(){
    int n,sum;

    printf("enter total: ");
    scanf("%d",&sum);   
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
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==sum)
                printf("(%d,%d) ",arr[i],arr[j]);   
        }
        
    }
    
    return 0;
}