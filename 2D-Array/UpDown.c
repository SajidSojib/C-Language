//revise not done (only done for n*n)

#include<stdio.h>
int main(){
    int r,c;
    printf("row: ");
    scanf("%d",&r);
    printf("collum: ");
    scanf("%d",&c);
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
          printf("%d,%d element:\n",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
     for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
          printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //just for printing
    // for (int j = 0; j < c; j++)
    // {
    //     for (int i = 0; i < r; i++)
    //     {
    //         if(j%2==0){
    //             printf("%d ",arr[r-1-i][j]);
    //         }
    //         else printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < c; i++)
    {
        for (int j = i; j < r; j++)
        {
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r/2; j++)
        {
            if (i%2==0)
            {
                int temp=arr[i][j];
                arr[i][j]=arr[i][r-1-j];
                arr[i][r-1-j]=temp;
            }  
        }      
    }
    
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}