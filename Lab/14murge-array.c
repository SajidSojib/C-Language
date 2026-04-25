#include <stdio.h>
int main()
{
    int arr[]={1,3,5,7,9},brr[]={2,4,6,8,10,12};
    int size1=sizeof(arr)/4;
    int size2 = sizeof(brr) / 4;
    int crr[size1+size2];

    int i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(arr[i]<brr[j]){
            crr[k]=arr[i];
            k++;
            i++;
        }else{
            crr[k] = brr[j];
            k++;
            j++;
        }
    }
    while (i<size1)
    {
        crr[k]=arr[i];
        k++;
        i++;
    }
    while (j < size2)
    {
        crr[k] = brr[j];
        k++;
        j++;
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ",crr[i]);
    }
    
    return 0;
}