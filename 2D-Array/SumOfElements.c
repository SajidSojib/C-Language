#include<stdio.h>
int main(){
    int r,c;
    printf("number of row: ");
    scanf("%d",&r);
    printf("number of collum: ");
    scanf("%d",&c);

    int arr[r][c];
    int sum=0;

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
        }
        printf("\n");
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum=sum+arr[i][j];
        }
        printf("\n");
    }
    printf("sum of all the elements: %d",sum);
    
    return 0;
}