#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *start=NULL;
int menu(){
    printf("\n\nLinked list\n");
    printf("\n1. create list");
    printf("\n2. traverse");
    printf("\n3. insert at beginning");
    printf("\n4. insert at end");
    printf("\n5. insert at middle");
    printf("\n6. delete at beginning");
    printf("\n7. delete at end");
    printf("\n8. delete at middle");
    printf("\n11. exit");
    int ch;
    printf("\n\nenter your choice: ");
    scanf("%d",&ch);
    return ch;
}
node *getNode(){
    node *newNode=(node*)malloc(sizeof (node));
    printf("enter data: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}
void createNode(int n){
    for (int i = 0; i < n; i++)
    {
        node *newNode=getNode();
        if(start==NULL){
            start=newNode;
        }else{
            node *temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        } 
    }  
}
int countNode(){
    int n=1;
    node *temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
        n++;
    }
    return n;
}
void insert_at_beg(){
    node *newNode=getNode();
    newNode->next=start;
    start=newNode;
}
void insert_at_end(){
    node *temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    node* newNode=getNode();
    temp->next=newNode;
}
void insert_at_mid()
{
    node *temp=start;
    node *prv=start;
    int n;
    printf("\nenter position: ");
    scanf("%d",&n);
    if(n>0 && n<countNode()){
        for (int i = 1; i < n; i++)
        {
            prv = temp;
            temp = temp->next;
        }
        node *newNode=getNode();
        newNode->next=temp;
        prv->next=newNode;
    }
}
void delete_at_beg()
{
    start=start->next;
}
void delete_at_end()
{
    node *temp=start,*prv=start;
    while(temp->next!=NULL){
        prv=temp;
        temp=temp->next;
    }
    prv->next=NULL;
}
void delete_at_mid()
{
    node *temp;
    node *prv;
    temp=prv=start;
    int n;
    printf("\nenter position: ");
    scanf("%d", &n);
    if(n>0 && n<countNode()){
        for (int i = 1; i < n; i++)
        {
            prv=temp;
            temp=temp->next;
        }
        prv->next=temp->next;
    }
}
void traverse(node *temp){
    if(temp==NULL) return;
    printf("%d -> ",temp->data);
    traverse(temp->next);
}
int main(){
    int ch;
    while(1){
        ch=menu();
        switch(ch){
            case 1:
                if(start==NULL){
                    int n;
                    printf("enter list number: ");
                    scanf("%d",&n);
                    createNode(n);
                }
                else printf("\nnode already exist");
                break;
            case 2:
                traverse(start);
                break;
            case 3:
                insert_at_beg();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_mid();
                break;
            case 6:
                delete_at_beg();
                break;
            case 7:
                delete_at_end();
                break;
            case 8:
                delete_at_mid();
                break;
            case 9:
                printf("number of nodes: %d",countNode());
                break;
            case 11:
                exit(0);
        }
    }

    return 0;
}