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

void addGCD(struct node** head){
    if(*head == NULL){
        printf("Linked List not found");
    }
    else{
        struct node* temp = *head;
        while (temp != NULL && temp->link != NULL){
            int min = (temp->info < temp->link->info)?(temp->info):(temp->link->info);

            struct node* newNode;
            for (int i=min;i>=1;i--){
                if((temp->info % i == 0) && (temp->link->info % i == 0)){
                    newNode = createNode(i);
                    break;
                }
            }

            struct node* a = temp->link;
            temp->link = newNode;
            newNode->link = a;
            temp = a;
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
    insertAtEnd(&head,18);
    insertAtEnd(&head,6);
    insertAtEnd(&head,10);
    insertAtEnd(&head,3);

    addGCD(&head);
    displayList(head);
}