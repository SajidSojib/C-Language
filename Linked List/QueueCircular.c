#include <stdio.h>

#define max 6
int q[max];
int front=0;
int rear=0;
int count=0;

char menu()
{
    char ch;
    printf("\n\n \t..Queue operations using Linked List");
    printf("\n\t -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf(" %c", &ch);
    return ch;
}

void insertQ(){
    if(count==max){
        printf("\nqueue is full");
    }
    else{
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        q[rear]=data;
        rear= (rear+1)%max;
        count++;
    }
}

void deleteQ(){
    if(count==0){
        printf("\nempty queue");
    }
    else{
        front=(front+1)%max;
        count--;
    }
}

void displayQ(){
    int j=0;
    for (int i = front; j < count; j++)
    {
        printf("%d < ",q[i]);
        i=(i+1)%max;
    }
    
}

int main(){

    char ch;
    do
    {
        ch = menu();
        switch (ch)
        {
        case '1':
            insertQ();
            break;
        case '2':
            deleteQ();
            break;
        case '3':
            displayQ();
            break;
        case '4':
            return 0;
        }
    } while (1);

    return 0;
}