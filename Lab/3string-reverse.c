#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    scanf("%[^\n]s",str);
    int size=0,i=0;
    while (str[size]!='\0')
    {
        size++;
    }
    for (int i = 0,j=size-1; i < j; i++,j--)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    puts(str);
    
    return 0;
}