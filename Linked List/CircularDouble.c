#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *left;
} node;
node *start = NULL;
int nodectr=0;
int display()
{
    int ch;
    printf("\n\n1. Create List");
    printf("\n------------------------------");
    printf("\n2. Insert at the beginning");
    printf("\n3. Insert at the end");
    printf("\n4. Insert at the middle");
    printf("\n------------------------------");
    printf("\n5. Delete from the beginning");
    printf("\n6. Delete from the end");
    printf("\n7. Delete from the middle");
    printf("\n------------------------------");
    printf("\n8. Traverse");
    printf("\n9. Traverse Reverse");
    printf("\n------------------------------");
    printf("\n10. Count Node");
    printf("\n11. exit");

    printf("\n\nenter your choice: ");
    scanf("%d", &ch);
    return ch;
}
node *getNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->next = NULL;
    return newNode;
}
void createNode(int n)
{
    nodectr=n;
    for (int i = 0; i < n; i++)
    {
        node *newNode = getNode();
        if (start == NULL)
        {
            start = newNode;
            newNode->left=start;
            newNode->next=start;
        }
        else
        {
            node *temp = start;
            while (temp->next != start)
                temp = temp->next;

            temp->next = newNode;
            newNode->left = temp;
            newNode->next=start;
        }
    }
    printf("\nnode created successfully");
}
void insertAtBeg()
{
    nodectr++;
    node *newNode = getNode();
    newNode->next = start;
    newNode->left=start->left;
    start->left = newNode;
    start = newNode;
}
void insertAtEnd()
{
    nodectr++;
    node *newNode = getNode();
    if (start == NULL){
        start = newNode;
        newNode->left=start;
        newNode->next=start;
    }
    else
    {
        newNode->left=start->left;
        start->left->next=newNode;
        newNode->next=start;
        start->left=newNode;
    }
}
void insertAtMid()
{
    nodectr++;
    int pos, count = 1;
    node *newNode = getNode();
    printf("\nenter position");
    scanf("%d", &pos);
    if (pos > 1 && pos < nodectr)
    {
        node *temp = start;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next->left = newNode;
        temp->next = newNode;
        newNode->left = temp;
    }
    else
        printf("invalid position");
}
void delFromBeg()
{
    nodectr--;
    if (start == NULL)
        printf("\nlist is empty");
    else
    {
        node *temp = start;
        start = start->next;
        start->left = temp->left;
        temp->left->next=start;
        free(temp);
    }
}
void delFromEnd()
{
    nodectr--;
    if (start == NULL)
        printf("\nlist is empty");
    else
    {
        node *temp = start->left;
        start->left=temp->left;
        temp->left->next=start;

        free(temp);
    }
}
void delFromMid()
{
    nodectr--;
    node *temp = start;
    int n, count = 1;
    printf("enter position: ");
    scanf("%d", &n);
    if (n > 1 && n < nodectr)
    {
        while (count < n)
        {
            temp = temp->next;
            count++;
        }
        temp->left->next = temp->next;
        temp->next->left = temp->left;
        free(temp);
    }
    else
        printf("invalid position");
}
void traverse()
{
    if (nodectr == 0)
        printf("\nList is empty");
    else
    {
        node *temp = start;
        printf("%d -> ",temp->data);
        temp=temp->next;
        while (temp != start)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("X");
    }
}
void traverseReverse(node *temp)
{
    if (start == NULL)
        return;
    if (temp == NULL)
        return;
    traverseReverse(temp->next);
    printf(" -> %d", temp->data);
}
int main()
{
    int ch;

    while (1)
    {
        ch = display();
        switch (ch)
        {
        case 1:
            if (start == NULL)
            {
                printf("\nenter number of node: ");
                int n;
                scanf("%d", &n);
                createNode(n);
            }
            else
            {
                printf("\nlist already exists");
            }
            break;
        case 2:
            insertAtBeg();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtMid();
            break;
        case 5:
            delFromBeg();
            break;
        case 6:
            delFromEnd();
            break;
        case 7:
            delFromMid();
            break;
        case 8:
            traverse();
            break;
        case 9:
            printf("X");
            traverseReverse(start);
            break;

        default:
            break;
        }
    }

    return 0;
}