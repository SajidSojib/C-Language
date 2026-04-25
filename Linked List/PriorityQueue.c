#include <stdio.h>
#include <stdlib.h>

// Sajid Ahmed Sojib
// ID:41240202191

struct queue
{
    int data;
    int priority;
    struct queue *next;
};
typedef struct queue node;

node *front = NULL;

char menu()
{
    char ch;
    printf("\n\n\t..Priority Queue using Linked List");
    printf("\n\t-----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete (Highest Priority)");
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
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    printf("Enter priority (higher number = higher priority): ");
    scanf("%d", &temp->priority);
    temp->next = NULL;
    return temp;
}

void insertQ()
{
    node *newnode = getnode();

    if (front == NULL || newnode->priority > front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        node *temp = front;
        while (temp->next != NULL && temp->next->priority >= newnode->priority)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("\n\nData Inserted into the Priority Queue..");
}

void deleteQ()
{
    if (front == NULL)
    {
        printf("\n\nEmpty Queue..");
        return;
    }

    node *temp = front;
    front = front->next;
    printf("\n\nDeleted element with highest priority is %d (Priority: %d)", temp->data, temp->priority);
    free(temp);
}

void displayQ()
{
    if (front == NULL)
    {
        printf("\n\nEmpty Queue");
        return;
    }

    node *temp = front;
    printf("\n\nElements in the Priority Queue:\n");
    printf("Data\tPriority\n");
    printf("----\t--------\n");
    while (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
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
        default:
            printf("\nInvalid choice. Try again.");
        }
    } while (1);

    return 0;
}