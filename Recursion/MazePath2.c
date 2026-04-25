#include <stdio.h>
int way(int x, int y)
{
    int rway = 0;
    int dway = 0;

    if (x == 1 && y == 1) return 1;
       
    if (x > 1 && y > 1)
    {
        rway += way(x,y-1);
        dway += way(x-1,y);
    }
    if (x == 1)  rway += way(x,y-1);
    if (y == 1)  dway += way(x-1,y);

    int totalway = rway + dway;
    return totalway;
}
int main()
{
    int m, n;
    printf("enter row: ");
    scanf("%d", &m);
    printf("enter collum: ");
    scanf("%d", &n);

    printf("no of ways to reach is %d", way( m, n));

    return 0;
}