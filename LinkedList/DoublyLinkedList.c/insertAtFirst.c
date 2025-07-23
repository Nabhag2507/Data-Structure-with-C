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

void insertAtFirst(struct node** head,int info){
    struct node* newNode = createNode(info);
    if(*head == NULL){
        *head = newNode;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
    }
    else{
        (*head)->lptr = newNode;
        newNode->rptr = *head;
        newNode->lptr = NULL;
        *head = newNode;
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

    insertAtFirst(&head,10);
    insertAtFirst(&head,20);
    insertAtFirst(&head,30);
    insertAtFirst(&head,40);
    insertAtFirst(&head,50);

    display(head);
}