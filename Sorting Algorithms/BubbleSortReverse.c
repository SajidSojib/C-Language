#include<stdio.h>
#include<stdbool.h>
int main(){
    int n=6;
    int arr[6]={1,2,3,4,5,6};

    for (int i = 0; i < n-1; i++)
    {
        bool flag=true;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=false;
            }            
        }
        if(flag==true) break;
        
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
} 