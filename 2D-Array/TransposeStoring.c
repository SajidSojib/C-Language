#include<stdio.h>
int main(){
    int r,c;
    printf("number of row: ");
    scanf("%d",&r);
    printf("number of collum: ");
    scanf("%d",&c);

    int arr[r][c];
    int brr[c][r];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("(%d,%d) element: ",i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ",arr[i][j]);
            brr[j][i]=arr[i][j];
        }
        printf("\n");
    }
     printf("\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ",brr[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}