#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;
};
struct node* first = NULL;
struct node* first1 = NULL;
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}
void insertAtLast(int data){
    struct node* newNode = createNode(data);
    struct node * temp = first;
    
    if(first==NULL){
        first=newNode;
    }
    else{
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newNode;
    }
}   
void insertAtfirst(int data){
    struct node* newNode = createNode(data);
    struct node * temp1 = first1;
    
    if(first1==NULL){
        first1=newNode;
    }
    else{
       newNode->link=first1;
       first1=newNode;
    }
}   


void printList(){
    printf("Linked List :\n");
    struct node * temp = first;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void printList1(){
    printf("Reverse Linked List: \n");
    struct node * temp = first1;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void reverseLinkedList()
{
    struct node* temp = first;
    while(temp!=NULL){
        insertAtfirst(temp->data);
        temp=temp->link;
    }
}
int main()
{
    printf("Enter size of Linked List");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("%d th node value ",i+1);
        scanf("%d",&data);
        insertAtLast(data);
    }
    reverseLinkedList();
    printList();
    printList1();
}
