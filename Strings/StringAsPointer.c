#include<stdio.h>
int main(){
    // char str[]="hello world";
    // char* ptr=str;  //prt points to str[0]  

    // for (int i = 0; *ptr != '\0'; i++,ptr++)
    // {
    //     printf("%c",*ptr);
    // }

    char* ptr="hello world";
    ptr++;
    printf("\n");
    printf("%c",*ptr);
    printf("\n");
    printf("%s",ptr);

    return 0;
}