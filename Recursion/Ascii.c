#include<stdio.h>
void ascii(int x,int y){
    if (x==y)
    {
        printf("%d->%c\n",y,y);
        return;
    }
    
    ascii(x,y-1);
    printf("%d->%c\n",y,y);

    return;

}

int main(){
     int n,m;
    printf("enter 1st number: ");
    scanf ("%d",&m);
     printf("enter 2nd number: ");
    scanf ("%d",&n);
    
    ascii(m,n);
     


    return 0;
}