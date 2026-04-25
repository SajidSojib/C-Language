#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *start = NULL;

int main()
{
    int n;
    printf("enter number of node: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));
        printf("enter data: ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        if (start == NULL)
        {
            start = newNode;
        }
        else
        {
            node *temp = start;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }  
    }
    char ch;
    printf("\nenter y for insert at the beginning or n if you dont: ");
    scanf(" %c",&ch);
    if(ch=='y'){
        node *newNode = (node *)malloc(sizeof(node));
        printf("enter data: ");
        scanf("%d", &newNode->data);
        if (start == NULL)
            start = newNode;
        else
        {
            newNode->next = start;
            start = newNode;
        }
    }

    node *temp = start;
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("X");
    return 0;
}