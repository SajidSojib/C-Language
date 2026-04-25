#include<stdio.h>
#include<limits.h>

int binarySearch(int arr[], int n, int target){
    int left = 0, right =n-1;
    while(left<=right){
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
    
}

void merge(int arr[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;

    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left+i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = arr[mid+1+i];
    }

    int i=0,j=0,k=left;
    while (i<n1 && j<n2)
    {
        if (l[i]<r[j]) arr[k++]=l[i++];
        else arr[k++]=r[j++];
    }
    while (i<n1)
    {
        arr[k++]=l[i++];
    }
    while (j<n2)
    {
        arr[k++]=r[j++];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = (left + right) / 2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int maxSubarraySum(int arr[], int n){
    int msum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            if(msum<sum) msum=sum;
        }   
    }

    return msum;
}

int main(){
    int n=7, target=22;
    // int arr[]={1,3,5,13,18,22,33};
    // printf("%d is found at %d index", target, binarySearch(arr, n, target));

    // int arr[7] = {5, 4, 3, 2, 1, 6, 7};
    // mergeSort(arr,0,n-1);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    int arr[9] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int m = 9;
    printf("%d", maxSubarraySum(arr, m));

    return 0;
}