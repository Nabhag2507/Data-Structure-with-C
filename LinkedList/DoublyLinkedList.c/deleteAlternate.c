#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    newNode->info = info;
    return newNode;
}

void insertAtLast(struct node** head,int info){
    struct node* newNode = createNode(info);
    if(*head == NULL){
        *head = newNode;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
    }
    else{
        struct node* temp = *head;
        while (temp->rptr != NULL){
            temp = temp->rptr;
        }
        temp->rptr = newNode;
        newNode->lptr = temp;
        newNode->rptr = NULL;
    }
}

void deleteAlternate(struct node** head , int index){
    if(*head == NULL){
        printf("Linked list not found");
    }
    else if((*head)->rptr == NULL){
        printf("Cannot delete anything");
        return;
    }
    else{
        struct node* tempL = *head;
        int length = 0;
        while(tempL != NULL){
            tempL = tempL->rptr;
            length++;
        }

        struct node* prev = NULL;
        struct node* curr = *head;
        struct node* temp = *head;
        int counter = length;

        while(length % 2 == 0){
            
        }
    }
}

void display(struct node* head){
    struct node* temp = head;
    while (temp != NULL){
        printf("%d , ",temp->info);
        temp = temp->rptr;
    }
}

void main () {
    struct node* head = NULL;

    insertAtLast(&head,10);
    insertAtLast(&head,20);
    insertAtLast(&head,30);
    insertAtLast(&head,40);
    insertAtLast(&head,50);
    insertAtLast(&head,60);
    insertAtLast(&head,70);
    insertAtLast(&head,80);

    callDelete(&head);

    display(head);
}