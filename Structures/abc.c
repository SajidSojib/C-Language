#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *start=NULL;

int menu(){
    int ch;
    printf("\n1. Create a list");
    printf("\n----------------------------");
    printf("\n2. Insert a Node at Beginning");
    printf("\n3. Insert a Node at end");
    printf("\n4. Insert a Node at middle");
    printf("\n------------------------------");
    printf("\n5. Delete a Node from Beginning");
    printf("\n6. Delete a Node from end");
    printf("\n7. Delete a Node from middle");
    printf("\n------------------------------");
    printf("\n8. Traverse the List Left to Right");
    printf("\n9. Traverse the List Right to Left");
    printf("\n------------------------------");
    printf("\n10. Count Node");
    printf("\n11. exit code");

    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}
node *getNode(){
    node *newNode=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}
void createList(int n){
    node *newNode,*temp;
    for (int i = 0; i < n; i++)
    {
        newNode=getNode();
        if (start==NULL){
            start=newNode;
        }
        else{
            node *temp=start;
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newNode;
        }
    }  
}
int countNode(){
    int count=0;
    node *temp=start;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void traverse(){
    node *temp=start;
    for (int i = 0; i < countNode(); i++)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }  
}
void traverseReverse(node *temp){
    if(temp==NULL) return;
    traverseReverse(temp->next);
    printf("%d -> ",temp->data);
}
void insertAtBeg(){
    node *newNode=getNode();
    if(start==NULL){
        start=newNode;
    }
    else{
    newNode->next=start;
    start=newNode;
    } 
}
void insertAtEnd(){
    node *newNode=getNode();
    if(start==NULL){
        start=newNode;
    }
    else{
        node *temp=start;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;   
    }
}
void insertAtMid(){
    node *prv,*newNode,*temp;
    int pos,nodeCounter,count=1;
    newNode=getNode();
    nodeCounter=countNode();
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(pos>1 && pos<nodeCounter){
        prv=temp=start;
        while(count<pos){
            prv = temp;
            temp = temp->next;
            count++;
        }
        prv->next=newNode;
        newNode->next=temp;
    }
    else printf("\ntheres no node in the middle");
}
void deleteAtBeg(){
    if(start==NULL) printf("\nNo nodes are exist");
    else{
        start=start->next;
    }
}
void deleteAtEnd(){
    if(start==NULL) printf("\nNo nodes are exist");
    else{
        node *temp=start,*prv=start;
        while(temp->next!=NULL){
            prv=temp;
            temp=temp->next;
        }
        prv->next=NULL;
    }
}
void deleteAtMid(){
    node *temp,*prv;
    temp=prv=start;
    int pos,count=1,nodeCounter;
    nodeCounter=countNode();
    printf("\nEnter position: ");
    scanf("%d",&pos);
    if(start==NULL){
        printf("\nlist is empty");
        return;
    }
    if(pos>1 && pos<nodeCounter){
        while(count<pos){
            prv=temp;
            temp=temp->next;
            count++;
        }
        prv->next=temp->next;
        free(temp);
        printf("\nNode deleted");
    }
    else printf("\nInvalid position");
}
int main()
{
    int ch;
    while (1)
    {
        ch=menu();
        switch (ch)
        {
        case 1:
            if(start==NULL){
                int n;
                printf("Number of node you want to create: ");
                scanf("%d",&n);
                createList(n);
                printf("\nList created successfully\n");
            }else printf("List Already Exist");
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
            deleteAtBeg();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteAtMid();
            break;
        case 8:
            traverse();
            break;
        case 9:
            printf("Content of list right to left:\n");
            traverseReverse(start);
            printf(" X ");
            break;
        case 10:
            printf("No of Nodes: %d",countNode());
            break;
        case 11:
            exit(0);
            break;
        }
    }
    


    return 0;
}