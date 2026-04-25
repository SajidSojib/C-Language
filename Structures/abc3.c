#include<stdio.h>
#include<stdlib.h>
#define max 6
int stack[max];
int top=0;
void display(){
    if(top==0) printf("stack is empty");
    else{
        for (int i = 0; i < top; i++)
        {
            printf("%d ",stack[i]);
        }
    }
}
void push(){
    if(top==max){
        printf("stack is full");
    }else{
        int data;
        printf("enter data: ");
        scanf("%d", &data);
        stack[top] = data;
        top++;
    }
}
void pop(){
    if(top==0){
        printf("stack underflowed");
    }else top--;  
}
int main(){
    int ch;
    while(1){
        printf("\n\nenter your choice");
        scanf("%d", &ch);
        switch ((ch))
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        
        default:
            return 0;
        }
    }
}