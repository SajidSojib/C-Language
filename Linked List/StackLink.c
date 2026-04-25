#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} node;
node *start = NULL;
node *top = NULL;

int menu()
{
    int ch;
    printf("\n\n******** Linked List Implimentation of Stack ********");
    printf("\n 1. Push");
    printf("\n 2. Pop");
    printf("\n 3. Display");
    printf("\n 4. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node *getNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void push()
{
    node *newNode = getNode();
    node *temp = start;

    if (start == NULL)
    {
        start = newNode;
        top = newNode;
    }
    else
    {
        top->next = newNode;
        top = newNode;
    }
}

void pop()
{
    if (start == NULL)
    {
        printf("\nstack underflow");
    }
    else if (start->next == NULL)
    {
        free(start);  
        start = NULL;
        top = NULL;
    }
    else
    {
        node *temp = start;
        while (temp->next != top)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        free(top);
        top = temp;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        node *temp = start;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;

    do
    {
        ch = menu();

        switch (ch)
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
        case 4:
            return 0;
            break;

        default:
            printf("\nenter valid input");
            break;
        }
    } while (1);

    return 0;
}