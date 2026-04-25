#include <stdio.h>
#include<limits.h>
int main()
{
    int n = 7;
    int arr[7] = {7,4,5,2,1,9,8};

    for (int i = 0; i < n-1; i++)
    {
        int min=INT_MAX;
        int minidx = -1;
        for (int j = i; j < n; j++)
        {
            if (min>arr[j])
            {
                min=arr[j];
                minidx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minidx];
        arr[minidx]=temp;
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }    

    return 0;
} 