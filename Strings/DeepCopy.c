#include<stdio.h>
#include<string.h>
int main(){
    char str[]="my name Is soJiB";
    int size=0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    printf("%d\n",size);
    
    char str2[size];
    for (int i = 0; i<=size ; i++)
    {
        str2[i]=str[i];
    }
    printf("\n%s\n",str2);


    return 0;
}