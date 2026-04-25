#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100];
    printf("string: ");
    scanf("%[^\n]s", str);
    char *ptr=str;
    int length=0;

    while(*ptr!='\0'){
        length++;
        ptr++;
    }
    printf("length: %d",length);

    return 0;
}