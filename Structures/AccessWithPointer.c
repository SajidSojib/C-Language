#include<stdio.h>
int main(){
    typedef struct person{
        int age;
        float waight;
    } person;

    person p1;

    p1.age=45;
    // p1.waight=60.5;
    printf("\n%d\n",p1.age);

    person* x=&p1;
    (*x).age=15;
    //(*x).waight=60.5;  (*x).something = x->something
    x->waight=60.5;
    
    printf("\n%d\n",(*x).age);
    printf("%.2f\n\n",(*x).waight);

    return 0;
}