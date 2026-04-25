#include<stdio.h>
#include<limits.h>
int main(){
    int r=4,c=4,x=2,sum=0;
    int maxr=r-1,maxc=c-1,minr=0,minc=0;
    int arr[r][c],brr[c][x];
    int maxR,maxC,minR,minC;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
                
    }
    printf("\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c/2; j++)
        {
            if (i%2==0)
            {
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