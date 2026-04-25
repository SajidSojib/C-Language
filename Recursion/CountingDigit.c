#include<stdio.h>
void count(int x,int y){
   if(x==0){
    printf ("%d",y);
    return;
   } 
    count(x/10,y+1);
    return;

}

int main(){
     int m;
    printf("enter number: ");
    scanf ("%d",&m);

    count(m,0);

    return 0;
}