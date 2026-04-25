//roll phy che math
#include<stdio.h>
int main(){
    int r,s,x;
    printf("number of students: ");
    scanf("%d",&r);
    printf("number of subjects: ");
    scanf("%d",&s);

    int arr[r][s+1];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s+1; j++)
        {
            if(j==0){
            printf("number roll: ");
            scanf("%d",&arr[i][j]);
            }
            else{
             printf("number marks: ");
            scanf("%d",&arr[i][j]);   
            }   
        }
    }
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s+1; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}