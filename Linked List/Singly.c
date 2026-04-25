#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node* start=NULL;
int display(){
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
    scanf("%d",&ch);
    return ch;
}
node* getNode(){
    node *newNode=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}
void createNode(int n){
    for (int i = 0; i < n; i++)
    {
        if (start==NULL)
        {
            start=getNode();
        }else{
            node *temp=start;
            while(temp->next!=NULL)
                temp=temp->next;
            
            temp->next=getNode();
        } 
    }  
    printf("\nnode created successfully");
}
int countNode(){
    int count=0;
    node* temp=start;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void insertAtBeg(){
    node* newNode=getNode();
    newNode->next=start;
    start=newNode;
}
void insertAtEnd(){
    if(start==NULL)
        start=getNode();
    else{
        node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=getNode();
    }
}
void insertAtMid(){
    int pos,count=1;
    node* newNode=getNode();
    printf("\nenter position");
    scanf("%d",&pos);
    if(pos>1 && pos<countNode()){
        node* temp=start;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    else
        printf("invalid position");
}
void delFromBeg(){
    if(start==NULL) printf("\nlist is empty");
    else{
        node *temp = start;
        start = start->next;
        free(temp);
    }
}
void delFromEnd(){
    if (start == NULL)
        printf("\nlist is empty");
    else{
        node *temp = start;
        node *prv = start;
        while (temp->next != NULL)
        {
            prv = temp;
            temp = temp->next;
        }
        prv->next = NULL;
        free(temp);
    }  
}
void delFromMid(){
    node* temp=start;
    node* prv=temp;
    int n,count=1;
    printf("enter position: ");
    scanf("%d",&n);
    if(n>1&&n<countNode()){
        while (count<n)
        {
            prv = temp;
            temp = temp->next;
            count++;
        }
        prv->next=temp->next;
        free(temp);
    }
    else printf("invalid position");
}
void traverse(){
    if(start==NULL) printf("\nList is empty");
    else{
        node *temp = start;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("X");
        free(temp);
    }
}
void traverseReverse(node* temp){
    if(start==NULL)
        return;
    if(temp==NULL)
        return;
    traverseReverse(temp->next);
    printf(" -> %d",temp->data);
}
int main()
{
    int ch;

    while(1){
        ch=display();
        switch (ch)
        {
        case 1:
            if(start==NULL){
                printf("\nenter number of node: ");
                int n;
                scanf("%d", &n);
                createNode(n);
            }
            else{
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