#include <stdio.h>

void PreInPost(int x)
{
    if(x==0) return;
    printf("pre %d\n",x);

    PreInPost(x-1);
     printf("in %d\n",x);
 
    PreInPost(x-1);
     printf("post %d\n",x);

    return;
}

int main()
{
    int n;
    printf("enter number: ");
    scanf("%d", &n);

    PreInPost(n);

    return 0;
}