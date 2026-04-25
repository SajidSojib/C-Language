//single double triple jump

#include<stdio.h>
int way(int n){
    if(n==1) return 1;
     if(n==2) return 2;
     if (n==3) return 4;
    return way(n-1)+way(n-2)+way(n-3);
}

int main(){
    int a;
    printf("enter base: ");
    scanf("%d",&a);

    printf("number of ways to reach: %d",way(a));
    return 0;
}