#include<stdio.h>
int main(){
    int x;
    printf("number of row and collum: ");
    scanf("%d",&x);
    int arr[x][x];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("(%d,%d) element: ",i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
     printf("\n");
    //transpose
    for (int i = 0; i < x; i++)
    {
        for (int j = i; j < x; j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
        printf("\n");
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}