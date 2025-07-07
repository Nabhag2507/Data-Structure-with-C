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

void insertAtEnd(struct node** head, int info) {
    struct node* newNode = createNode(info);
    if (*head == NULL) {
        *head = newNode;
        newNode->link = newNode;  // circular link
    }
    else {
        struct node* temp = *head;
        while (temp->link != *head) {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = *head;
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
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);

    displayList(head);
}