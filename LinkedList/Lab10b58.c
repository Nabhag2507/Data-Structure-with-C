//  WAP to check whether 2 singly linked lists are same or not.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->info = info;
    return newNode;
}

void insertAtEnd(struct node** head,int info){
    struct node* newNode = createNode(info);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct node* temp = *head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void checkLinkedList(struct node* head1,struct node* head2) {
    int counter = 0;
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    while(temp1->link != NULL && temp2->link != NULL){
        if(temp1->info != temp2->info){
            counter++;\
        }
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    if(counter != 0){
        printf("Linked Lists are not same");
    }
    else{
        printf("Linked Lists are same");
    }
}

void main () {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    insertAtEnd(&head1, 10);
    insertAtEnd(&head1, 20);

    insertAtEnd(&head2, 10);
    insertAtEnd(&head2, 20);
    insertAtEnd(&head2, 20);

    checkLinkedList(head1,head2);
}