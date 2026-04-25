#include<stdio.h>
#include<limits.h>
int main(){
    int n=6;
    int arr[6]={3,6,1,2,9,5};
    int k=3;
    for (int i = 0; i < k; i++)
    {
       int min=INT_MAX;
       int minidx=-1;
       for (int j = i; j < n; j++)
       {
         if (arr[j]<min)
         {
             min=arr[j];
             minidx=j;
         }
       }
       int temp= arr[i];
       arr[i]=arr[minidx];
       arr[minidx]=temp;
    }
    
    printf("\n%dth smallest element: %d\n",k,arr[k-1]);
    
    return 0;
}