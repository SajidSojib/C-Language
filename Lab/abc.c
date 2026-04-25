#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    struct a
    {
        int x;
        char y;
    } s;
    union b
    {
        int p;
        char q;
    }u;
    printf("%lu %lu",sizeof(s),sizeof(u));
    

    return 0;
}