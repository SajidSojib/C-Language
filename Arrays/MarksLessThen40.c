#include<stdio.h>
int main(){
    int mark[10];
    for (int i = 0; i <= 9; i++)
    {
        printf("enter marks of %dth student\n",i+1);
        scanf("%d",&mark[i]);
    }
    for (int i = 0; i <= 9; i++)
    {
        if (mark[i]<40)
        {
            printf("%d ",i);
        }
        
    }
    
    return 0;
}
