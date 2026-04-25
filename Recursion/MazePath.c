#include <stdio.h>
int way(int cr, int cc, int er, int ec)
{
    int rway = 0;
    int dway = 0;

    if (cr == er && cc == ec) return 1;
       
    if (cr < er && cc < ec)
    {
        rway += way(cr, cc + 1, er, ec);
        dway += way(cr + 1, cc, er, ec);
    }
    if (cr == er) rway += way(cr, cc + 1, er, ec);   
    if (cc == ec) dway += way(cr + 1, cc, er, ec);   

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

    printf("no of ways to reach is %d", way(1, 1, m, n));

    return 0;
}