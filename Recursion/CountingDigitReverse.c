#include <stdio.h>
void count(int x,int y)
{
   
    if (x==0){

       printf("%d",y); 
       return;  

    }
    

    count(x/10,y*10+x%10);
    return;
}

int main()
{
    int m,n;
    printf("enter number: ");
    scanf("%d", &m);
    int a=0;
 
    count(m,0);
    
    return 0;
}