#include <stdio.h>
#include <string.h>
void palindrome(char str[],int start,int end){
    if(start>end){
        printf("palindrome");
        return;
    }
    if(str[start]!=str[end]){
        printf("not palindrome");
        return;
    }

    palindrome(str,start+1,end-1);
}
int main()
{
    char str[100];
    int check=0;
    scanf("%[^\n]s", str);
    int size=strlen(str);
    // for (int i = 0,j=strlen(str)-1; i < j; i++,j--)
    // {
    //     if (str[i]!=str[j])
    //     {
    //         check=1;
    //         break;
    //     }
    // }
    // if (check==0) puts("palindrome");
    // else puts("not palindrome");

    palindrome(str,0,size-1);

    return 0;
}