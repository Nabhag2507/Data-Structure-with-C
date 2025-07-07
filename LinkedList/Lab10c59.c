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
    } else {
        struct node* temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void removeDuplicate(struct node* head) {
    struct node* temp = head;
    struct node* duplicate;

    while (temp != NULL && temp->link != NULL) {
        if (temp->info == temp->link->info) {
            duplicate = temp->link;
            temp->link = temp->link->link;
            free(duplicate);
        } else {
            temp = temp->link;
        }
    }
}

void displayList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main() {
    struct node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Original List:\n");
    displayList(head);

    removeDuplicate(head);

    printf("After Removing Duplicates:\n");
    displayList(head);
}
