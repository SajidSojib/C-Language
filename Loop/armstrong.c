
#include <stdio.h>
int main()
{

    int sum, ld;

    for (int n = 1; n <= 500; n++)
    {
        sum=0;
        for (int i = n; i != 0; i=i/10)
        {
            ld=i%10;
            sum=sum+ld*ld*ld;
        }
        if (sum==n)
        {
            printf("%d\n",n);
        }
        

    }
    return 0;
}