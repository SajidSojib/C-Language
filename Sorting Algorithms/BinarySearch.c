#include <stdio.h>

int binarySearch(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (r + l) / 2; 

        if (arr[mid] == x)
            return mid; 
        else if (arr[mid] > x)
            r = mid - 1; 
        else
            l = mid + 1; 
    }

    return -1; 
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, n, x);

    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);

    return 0;
}
