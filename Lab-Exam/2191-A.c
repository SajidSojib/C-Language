#include <stdio.h>

int main()
{
    int m, n;
    printf("Size of array1: ");
    scanf("%d", &m);
    printf("Size of array2: ");
    scanf("%d", &n);
    
    int array1[m];
    int array2[n];

    printf("Enter %d elements of array1:\n",m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&array1[i]);
    }

    printf("Enter %d elements of array2:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array2[i]);
    }

    int result[m+n];
    for (int i = 0; i < m+n; i++)
    {
        if (i < m) result[i] = array1[i];
        else result[i]=array2[i-m];
    }

    //sort
    int rsize=m+n;

    for (int i = 0; i < rsize; i++)
    {
        int check = 1;
        for (int j = 0; j < rsize-1-i; j++)
        {
            if (result[j] > result[j+1])
            {
                int temp = result[j];
                result[j] = result[j+1];
                result[j+1] = temp;
                check = 0;
            }
        }
        m++;
        if (check==1) break;
    }

    printf("Expected output: \n");
    for (int i = 0; i < rsize; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}