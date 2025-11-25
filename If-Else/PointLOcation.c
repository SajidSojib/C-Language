#include <stdio.h>
int main()
{
    int x,y;
    printf("Enter point: ");
    scanf("%d%d", &x,&y);

    if (x==0 && y==0)
    {
        printf ("the point is origin");
    }
    else if (y==0)
    {
        printf("Lies on X-axis");
    
    }
    else if (x==0)
    {
        printf ("Lis on Y-axix");
    
    }
    else
    {
        printf("Does not lies on X or Y axis");
    }
    return 0;
}