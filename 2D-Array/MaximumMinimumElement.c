#include<stdio.h>
#include<limits.h>
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
    int max=INT_MIN;
    int min=INT_MAX;
    int MaxR,MaxC,MinR,MinC;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (max<arr[i][j]) {
                max=arr[i][j];
                MaxR=i;    //only for first maximum num
                MaxC=j;}
    
            if (min>arr[i][j]) {
                min=arr[i][j];
                MinR=i;    //only for first minimum num
                MinC=j;}       
        }
    }
    printf("maximum element: %d\n",max); 
    printf("index of maximum element (%d %d)\n\n",MaxR,MaxC);  
    
    printf("minimum element: %d\n",min);
    printf("index of minimum element (%d %d)\n",MinR,MinC);          
    
    return 0;
}