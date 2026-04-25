//with extra array
#include<stdio.h>
int main(){
    int n;
    printf("array size: ");
    scanf("%d", &n);
    int arr[n],brr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
        brr[n-1-i]=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",brr[i]);
    }


    return 0;
}
