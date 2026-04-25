#include<stdio.h>
#include<string.h>
int main(){
    // char str[]="hello world";
    // printf("%s",str);

    // char str[40];
    // scanf("%s",str);  //only one word as input
    // printf("%s",str);

    // char str[40];
    // scanf("%[^\n]s",str); //take whole sentence
    // printf("%s",str);

    char str[40];
    gets(str);   //gets==scanf
    puts(str);   //puts==printf+\n

    return 0;
}