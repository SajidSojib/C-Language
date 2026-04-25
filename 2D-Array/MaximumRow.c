#include<stdio.h>
int main(){
    int r,c;
    printf("number of row: ");
    scanf("%d",&r);
    printf("number of collum: ");
    scanf("%d",&c);

    int arr[r][c];

    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++)
        {
            printf("(%d,%d) element: ",i,j);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
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

    int sum1=0;
    int MaxIdx;
    for (int i = 0; i < r; i++)
    {
        int sum2=0; 
        for (int j = 0; j < c; j++)
        {
         sum2+=arr[i][j];
        }
        if(sum1<sum2){
            MaxIdx=i;
            sum1=sum2;
        }
    }
    printf("sum of the maxium row: %d\n\n",sum1);
    printf("maximum row number %d\n",MaxIdx+1);
    return 0;
}