#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int sum=0,max=arr[0],min=arr[0];
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
    }
    
    printf("Maximum element: %d\n",max);
    printf("Minimum element: %d\n",min);
    printf("Average: %f", (float)sum/n);

    return 0;
}
