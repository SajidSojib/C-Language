#include<stdio.h>
#include<string.h>
int main(){
    struct person
    {
        char name[50];
        float age;
        int salary;
    } a,b;

    strcpy(a.name,"Sajid Ahmed");
    a.age=19.6;
    a.salary=42000;
    
    strcpy(b.name,"Tanvr AAhmed");
    b.age=23.4;
    b.salary=244000;

    printf("\n%s\n",a.name);
    printf("Age: %.1f\n",a.age);
    printf("Salary: %d\n\n",a.salary);

    printf("%s\n",b.name);
    printf("Age: %.1f\n",b.age);
    printf("Salary: %d\n\n",b.salary);




    return 0;
}