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

    int maxc=c-1;
    int minc=0;
    int maxr=r-1;
    int minr=0;
    int total=r*c;
    int count =0;
    while (count<total)
    {
        for (int j = minc; j <= maxc; j++,count++)
        {
            printf("%d ",arr[minr][j]);
        }
        minr++;
        if(count>=total) break;

        for (int i = minr; i <= maxr; i++,count++)
        {
             printf("%d ",arr[i][maxc]);
        }
        maxc--;
        if(count>=total) break;

        for (int j = maxc; j >= minc; j--,count++)
        {
             printf("%d ",arr[maxr][j]);
        }
        maxr--;
        if(count>=total) break;

        for (int i = maxr; i >= minr; i--,count++)
        {
             printf("%d ",arr[i][minc]);
        }
        minc++;
        
    }
    
    


    return 0;
}