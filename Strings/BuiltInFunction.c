#include<stdio.h>
#include<string.h>
int main (){
//size of string without \0;
    // char s1[]="hello world";
    char* str="hello world";
    int x=strlen(str);
    printf("size is %d\n\n",x);

//deep-copy string
    char s1[12]="hello world";
    char s2[12];
    strcpy(s2,s1);
    s2[0]='M';
    printf("%s\n\n",s2);

//connect/concat two strings
    char a1[12]="Sajid";//size(a1)+null+size(a2)
    char a2[]=" Ahmed";
    strcat(a1,a2);
    printf("%s",a1);

    return 0;
}