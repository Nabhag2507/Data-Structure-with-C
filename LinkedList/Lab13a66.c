//reverse a linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* createNode(int info){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
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

void sortLinkedList(struct node** head){
    struct node* temp = *head;
    if(*head == NULL){
        printf("Linked List not found");
    }
    else{
        struct node* c = *head;
        while(c != NULL){
            struct node* c2 = c->link;
            while(c2 != NULL){
                if(c->info > c2->info){
                    int temp = c2->info;
                    c2->info = c->info;
                    c->info = temp;
                }
                c2 = c2->link;
            }
            c = c->link;
        }
    }
}

void displayList(struct node* head) {
    while (head != NULL) {
        printf("%d , ", head->info);
        head = head->link;
    }
}

void main () {
    struct node* head = NULL;
    insertAtEnd(&head,5);
    insertAtEnd(&head,1);
    insertAtEnd(&head,3);
    insertAtEnd(&head,2);
    insertAtEnd(&head,4);

    sortLinkedList(&head);
    displayList(head);
}