#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* createNode(int info) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

void insertAtfirst(struct node** head, int info) {
    struct node* newNode = createNode(info);
    if(*head == NULL){
        *head = newNode;
        newNode->link = newNode;
    }
    else{
        struct node* temp = *head;
        while (temp->link != *head) {
            temp = temp->link;
        }
        temp->link = newNode;       // Last node points to newNode
        newNode->link = *head;      // newNode points to old head
        *head = newNode;
    }
}

void displayList(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d, ", temp->info);
        temp = temp->link;
    } while (temp != head);
    printf("\n");
}

void main() {
    struct node* head = NULL;
    insertAtfirst(&head, 5);
    insertAtfirst(&head, 1);
    insertAtfirst(&head, 3);
    insertAtfirst(&head, 2);
    insertAtfirst(&head, 4);

    displayList(head);
}