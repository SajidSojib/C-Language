#include<stdio.h>
int main(){
    char c;
    int x,y;
    scanf("%d %c %d",&x,&c,&y);

    switch (c)
    {
    case '+':
        printf("%d",x+y);
        break;
    case '-':
        printf("%d",x-y);
        break;
    case '*':
        printf("%d",x*y);
        break;
    case '/':
        if (y != 0)
            printf("%f", (float)x / y);
        else printf("invalid number");
            break;
    default:
    printf("Invalid Operator");
        break;
    }



    return 0;
}