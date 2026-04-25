#include<stdio.h>
int main(){
    int r,c;
    printf("enter row: ");
    scanf("%d",&r);
    printf("enter collum: ");
    scanf("%d",&c);

    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("(%d,%d) element: ",i,j);
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
    

    return 0;
}