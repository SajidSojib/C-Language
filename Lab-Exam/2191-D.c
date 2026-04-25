#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    //d b a c
    int m,n,x;
    printf("Enter 1st matrix row: ");
    scanf("%d",&m);
    printf("Enter 1st matrix collumn and 2nd matrix row: ");
    scanf("%d", &n);
    printf("Enter 2nd matrix collumn: ");
    scanf("%d", &x);

    int arr[m][n];
    int brr[n][x];
    int result[m][x];

    printf("Enter 1st matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    printf("Enter 2nd matrix: \n");
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
            result[i][j]=0;
            for (int k = 0; k < n; k++)
            {
                result[i][j]+=(arr[i][k]*brr[k][j]);
            }  
        }   
    }

    //printing product
    printf("\n");
    printf("Product Matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
    //transpose
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp=result[i][j];
            result[i][j]=result[j][i];
            result[j][i]=temp;
        }
    }
    printf("\n\n");
    printf("Transpose of product: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}