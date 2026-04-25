#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int *ptr=arr,sum=0;
    for (int i = 0; i<n; i++)
    {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("%d",sum);

    return 0;
}