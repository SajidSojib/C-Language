#include<stdio.h>
int main(){
    // char a[]={'H','a','l','l','o'};
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%c",a[i]);
    // }
    

    // char b[]="hello world\0";
    // for (int i = 0; b[i] != '\0'; i++)
    // {
    //      printf("%c",i[b]);
    // }

    // char str[]="hello world";
    // for (int i = 0; str[i] != '\0'; i++)
    // {
    //      printf("%c",*(str+i));
    // }

    char str[]="hello";
    int s=0;
    for (int i = 0; i<500; i++)
    {
        if (str[i]=='\0')
        {
            s++;
            break;
        }     
         printf("%c",str[i]);
        s++;   
    }
     printf("\n");
      printf("%d",s);
      


    return 0;
}