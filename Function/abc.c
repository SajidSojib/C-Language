#include <stdio.h>
int sorting(int a[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    


    return a[4];
}
int main()
{
    int max, arr[5]={1,2,5,4,3};
    printf("%d",sorting(arr));
    // sorting(arr);
    // printf("%d",arr[4]);
    return 0;
}