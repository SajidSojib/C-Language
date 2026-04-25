#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    struct date
    {
        int day;
        int month;
        int year;
    } a,b;
    a.day=14;
    a.month=8;
    a.year=2064;

    b.day=14;
    b.month=8;
    b.year=2064;

    // not possile
    // if (a==b) printf("The dates are equal");
    // else printf("The dates are unequal");
    
    bool flag=false;
    if(a.day==b.day && a.month==b.month && a.year==b.year)
        flag=true;

    if(flag==true) printf("The dates are equal");
    else printf("The dates are unequal");

    return 0;
}