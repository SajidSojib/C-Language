#include<stdio.h>
#include<stdbool.h>
int number(int x[],int n){
    if (n==0)
    {
        return x[0];
    }
    return (number(x,n-1)*10)+x[n];
}

int main(){
    int arr[7]={4,5,5,1,5,3,5};
    int n=7;
    for (int i = 0; i < n-1; i++)
    {
        bool flag=true;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=false;
            }
        }
        if (flag==true) break;
    }
    
    int smallest1=number(arr,n-1);

    if (arr[n-1]!=arr[n-2])
    {
        int temp=arr[n-1];
        arr[n-1]=arr[n-2];
        arr[n-2]=temp;
    }
    else
    {
        for (int i = n-2; i >= 0; i--)
        {
            if (arr[i]!=arr[i-1])
            {
                int temp=arr[i-1];
                arr[i-1]=arr[n-2];
                arr[n-2]=temp;
                break;
            }
            
        }
        
    }
    int smallest2=number(arr,n-1);
    
    printf("1st smallest: %d\n2nd smallest: %d",smallest1,smallest2);


    return 0;
}