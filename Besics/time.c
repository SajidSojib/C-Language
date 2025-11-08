#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int highest=6,lowest=1;

    srand(time(0));
    int number=rand()%(highest-lowest+1)+lowest;

    printf("%d",number);

    
    return 0;
}