//revise revise revise
#include<stdio.h>
int main(){
    int x,y,z;
    printf("1st matrix row: ");
    scanf("%d",&x);
    printf("1st mat col and 2nd mat row: ");
    scanf("%d",&y);
    printf("2nd matrix collum: ");
    scanf("%d",&z);
    int a[x][y];
    int b[y][z];

    //getting matrix
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("(%d,%d) element: ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");

     for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < z; j++)
        {
            printf("(%d,%d) element: ",i,j);
            scanf("%d", &b[i][j]);
        }
    }
    printf("\n");

    //printing matrix
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
     printf("\n");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < z; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
     printf("\n");

     //muliplication
     int res[x][z];
     for (int i = 0; i < x; i++)
     {
        for (int j = 0; j < z; j++)
        {
            res[i][j]=0;
            for (int k = 0; k < y; k++)
            {
                res[i][j]+=a[i][k]*b[k][j];
            }           
        }    
     }
      
     //printing result
     for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < z; j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }



     return 0;
}