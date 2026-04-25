// //revise revise revise 1:50

// #include <stdio.h>
// int factorial(int x)
// {
//     int fact = 1;
//     for (int i = 2; i <= x; i++)
//     {
//         fact = fact * i;
//     }
//     return fact; 
// }
// int combination(int n, int r)
// {
//     int nfact = factorial(n),
//         rfact = factorial(r),
//         nrfact = factorial(n - r);

//     int ncr = nfact / (rfact * nrfact);
//     return ncr;
// }

// int main()
// {
//     int N;
//     printf("enter N: ");
//     scanf("%d", &N);
//     int n = 0;
//     for (int i = 0; i <= N-1; i++)
//     {
//         for (int j = 1; j <= N - i; j++)
//         {
//             printf(" ");
//         }
//         for (int k = 0; k <= i; k++)
//         {
//             int ick=combination(i,k);
//             printf("%d ",ick );          
//         }   
//         printf("\n");
//     }

//     return 0;
// }

#include<stdio.h>
int main()
{
    int N;
    printf("enter N: ");
    scanf("%d", &N);
    int n = 0;
    for (int i = 0; i <= N-1; i++)
    {
        int first=1;
        for (int j = 1; j <= N-1-i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("%d ",first);
            first = first* (i-k)/(k+1);
        }
        printf("\n");
    }
    return 0;
}