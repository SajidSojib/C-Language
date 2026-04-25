#include <stdio.h>
int count(int x,int y)
{
   
    if (x==0){
        
       return y;  
           
    }

    return count(x/10,(y*10)+x%10);
}

int main()
{
    int m,n;
    printf("enter number: ");
    scanf("%d", &m);
    int a=0;
 
    printf("%d",count(m,0));
    
    return 0;
}