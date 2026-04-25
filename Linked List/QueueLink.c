// Sajid Ahmed Sojib
// ID:41240202191

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *front = NULL;
node *rear = NULL;

char menu()
{
    char ch;
    printf("\n \t..Queue operations using Linked List");
    printf("\n\t -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf(" %c", &ch);
    return ch;
}
node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter data ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}
void insertQ()
{
    node *newnode;
    newnode = getnode();
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {

        rear->next = newnode;
        rear = newnode;
    }
    printf("\n\nData Inserted into the Queue..");
}
void deleteQ()
{
    node *temp;
    if (front == NULL)
    {
        printf("\n\nEmpty Queue..");
        return;
    }
    temp = front;
    front = front->next;
    printf("\n\nDeleted element from queue is %d ", temp->data);
    free(temp);
}
void displayQ()
{
    node *temp;
    if (front == NULL)
    {
        printf("\n\nEmpty Queue ");
    }
    else
    {
        temp = front;

        printf("\n\n\nElements in the Queue are: ");

        while (temp != NULL)
        {

            printf("%5d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    // Sajid Ahmed Sojib
    // ID:41240202191

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