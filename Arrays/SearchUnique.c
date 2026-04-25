#include<stdio.h>
#include<stdbool.h>
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
        bool flag=false;
        for (int j = 0; j < n; j++)
        {
            if(arr[i]==arr[j] && i!=j) flag=true;
        }
        if(flag==false) printf("%d ",arr[i]);
    }
    
    return 0;
}