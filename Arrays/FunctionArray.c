#include <stdio.h>
void fun1(int m[]){
   m[0]=100; 

    return;
}
void fun2(int n){
    n=200;

    return;
}

int main()
{
    int arr[2]={2,9};
    int x=5;

    printf("%d %d\n",arr[0],arr[1]);
    printf("%d\n\n",x);

    fun1(arr);
    fun2(x);

    printf("%d %d\n",arr[0],arr[1]);
    printf("%d ",x);

   
    return 0;
}