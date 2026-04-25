#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *start=NULL;
int menu(){
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

    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    return ch;
}
node *getNode(){
    node *newNode=(node*)malloc(sizeof (node));
    printf("\nenter data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;
}
void createNode(int n){
    for (int i = 0; i < n; i++)
    {
        node *newNode=getNode();
        node *temp=start;
        if(start==NULL){
            start=newNode;
        }
        else{
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}
int countNode(){
    int count=0;
    node *temp=start;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
void traverse(){
    if(start==NULL) printf("\nlist is empty");
    else{
        node *temp=start;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
}
void traverseRev(node *temp){
    if (start == NULL)
        printf("\nlist is empty");
    if(temp==NULL) return;
    traverseRev(temp->next); 
    printf("%d -> ", temp->data);
}
void insertBeg(){
    node *newNode=getNode();
    if(start==NULL){
        start=newNode;
        return;
    }
    newNode->next=start;
    start=newNode;
}

int main(){
    int ch;
    while(1){
        ch=menu();
        switch (ch)
        {
        case 1:
            if(start==NULL){
                int n;
                printf("Number of node you want to create: ");
                scanf("%d",&n);
                createNode(n);
            }
            else printf("list already exist");
            break;
        case 2:
            insertBeg();
            break;
        case 8:
            traverse();
            break;
        case 9:
            traverseRev(start);
            printf("X");
            break;
        case 10:
            printf("\nNo of nodes:%d",countNode());
            break;

        default:
            break;
        }
    }
}