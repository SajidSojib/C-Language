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

    //just for printing
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         if(i%2==0){
    //             printf("%d ",arr[i][j]);
    //         }
    //         else printf("%d ",arr[i][c-1-j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c/2; j++)
        {
            if(i%2!=0){
                int temp=arr[i][j];
                arr[i][j]=arr[i][c-1-j];
                arr[i][c-1-j]=temp;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}