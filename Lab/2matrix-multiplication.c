#include <stdio.h>
int main()
{
    /*
    1 2
    3 4
    5 6

    7 8 9
    10 11 12

    27 30 33
    61 68 75
    95 106 117
    */
    int m,n,x;
    scanf("%d %d %d",&m,&n,&x);
    int arr[m][n];
    int brr[n][x];
    int res[m][x];  
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }  
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            scanf("%d", &brr[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < x; j++)
        {
            res[i][j]=0;
            for (int k = 0; k < n; k++)
            {
                res[i][j]+=arr[i][k]*brr[k][j];
            }   
        }        
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}