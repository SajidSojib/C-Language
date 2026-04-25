#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[7]={1,2,5,4,8,21,5};
    int x=21;
    bool flag=false;

    for (int i = 0; i <= 6; i++)
    {
        if(arr[i]==x){
            flag=true;
            break;
        }
    }
    if(flag==false) printf("%d is not present",x);
    else printf("%d is present",x);


//in 1-100 there is one number missing (leatcode)

    return 0;
}