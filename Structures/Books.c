#include<stdio.h>
#include<string.h>
int main(){
    struct book
    {
        char name[50];
        float price;
        int page;
    } a,b;

    strcpy(a.name,"History Of Bangladesh");
    a.price=215.5;
    a.page=420;
    
    strcpy(b.name,"English Grammer");
    b.price=115.5;
    b.page=200;

    printf("\n%s\n",a.name);
    printf("Price: %.2f\n",a.price);
    printf("Page: %d\n\n",a.page);

    printf("%s\n",b.name);
    printf("Price: %.2f\n",b.price);
    printf("Page: %d\n\n",b.page);



    return 0;
}