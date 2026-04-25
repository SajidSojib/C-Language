#include<stdio.h>
#include<string.h>
int main(){

    char a[]="Computer Science";
    char b[]="Computer";
    int x=0;
    for (int i = 0; a[i]!='\0' || b[i]!='\0'; i++)
    {
        if(b[i]!=a[i]){
            x=1;
            break;
        }
    }
    if (x==0 && strlen(a)==strlen(b)) printf("equal");
    else printf("not equal");
    
    
    return 0;
}