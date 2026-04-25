#include<stdio.h>
int main(){
    char s[]="hello world";
    char* s1=s;
    s[0]='M';
    
    printf("s: %s\n", s);
    printf("s1: %s\n\n", s1);

    char* s2;
    s2=s1;
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    return 0;
}