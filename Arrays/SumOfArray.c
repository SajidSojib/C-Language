#include<stdio.h>
int main(){
    int mark[3]={3,5,4};
    int a=0;
    for (int i = 0; i < 3; i++)
    {
     a=a+mark[i];   
    }
    printf("%d",a);

    return 0;
}