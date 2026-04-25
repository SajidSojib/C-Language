#include<stdio.h>
#include<limits.h>
#include<string.h>
int main(){

    char str[500];
    puts("enter a string: ");
    scanf("%[^\n]s",str);
    int size=0;
    printf("%lu\n", sizeof(str));
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    for (int i=0, j = size-1; i<j; i++, j--)
    {
        int temp =str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    puts("the reverse is: ");
    puts(str);



    return 0;
}