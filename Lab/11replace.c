#include <stdio.h>
#include <string.h>
int main()
{
    char str[100],f,r;
    printf("string: ");
    scanf("%[^\n]s",str);
    printf("find: ");
    scanf(" %c",&f);
    printf("replace: ");
    scanf(" %c", &r);

    int i=0;
    while (str[i]!='\0')
    {
        if(str[i]==f) str[i]=r;
        i++;
    }
    puts(str);
    
    return 0;
}