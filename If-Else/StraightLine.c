#include <stdio.h>
int main()
{
    int x1, x2,x3,y1,y2,y3;
    printf("Enter first point: ");
    scanf("%d%d", &x1,&y1);
    printf("Enter second point: ");
    scanf("%d%d"), &x2,&y2;
    printf("Enter third point: ");
    scanf("%d%d", &x3,&x3);

    double m1,m2;
    m1=(y2-y1)/(x2-x1);
    m2=(y3-y2)/(y3-x2);

    if (m1==m2)
    {
        printf ("These thre points are a straight line");
    }
    else
    {
        printf ("not a straight line");
    }
    

    return 0;
}