#include<stdio.h>
int main(){
    int arr[5];

    char crr[5]={'a','T','$','g','+'};
    printf("%c\n",crr[2]);
    for (int i = 0; i <= 4; i++)
    {
        printf("enter eliment no %d\n",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i = 4; i >= 0; i--)
    {
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}