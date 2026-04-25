#include <stdio.h>
#include<stdbool.h>
int main()
{
    int n = 6;
    int arr[6] = {6,5,4,5,2,1};

    for (int i = 1; i < n; i++)
    {
        int j=i;
        while (arr[j-1]>arr[j])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
        
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d ",arr[i]);
    }    

    return 0;
} 