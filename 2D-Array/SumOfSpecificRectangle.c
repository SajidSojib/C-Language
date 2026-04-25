#include<stdio.h>
int main(){
    int r,c,sr,sc,er,ec;
    printf("number of row: ");
    scanf("%d",&r);
    printf("number of collum: ");
    scanf("%d",&c);

    printf("starting row and collum: ");
    scanf("%d%d",&sr,&sc);
    printf("ending row and collum: ");
    scanf("%d%d",&er,&ec);

    int arr[r][c];
    int sum=0;

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

    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
        {
         sum+=arr[i][j];
                        
        }
    }
    printf("sum of all the elements: %d",sum);
    
    return 0;
}