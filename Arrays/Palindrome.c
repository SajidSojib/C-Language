#include<stdio.h>

int main(){
    int n,a=0;
    printf("array size: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&arr[i]);
    }

    for (int i = 0, j=n-1; i < j; i++, j--)
    {
        if (arr[i]!=arr[j])
        {
           a=1;
           break; 
        }     
    }

    if(a==0) printf("palindrome");
    else printf("not palindrome"); 

    return 0;
}