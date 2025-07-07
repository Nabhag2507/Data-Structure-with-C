//WAP to split a circular linked list into two halves.

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

void splice(struct node** head){
    if(*head == NULL){
        printf("Linked list not found\n");
    }
    else{
        int counter = 0;
        struct node* temp = *head;
        while (temp != NULL){
            counter++;
            temp = temp->link;
        }

        int mid = counter / 2;

        struct node* abc = *head;
        for(int i = 0; i < mid - 1; i++){
            abc = abc->link;
        }

        // Second half starts here
        struct node* first2 = abc->link;

        // Make first half circular
        abc->link = *head;

        // Move temp to end of second half
        temp = first2;
        while(temp->link != NULL){
            temp = temp->link;
        }

        // Make second half circular
        temp->link = first2;

        // Optional: print both parts
        printf("First Half Circular: ");
        temp = *head;
        for(int i = 0; i < mid; i++){
            printf("%d ", temp->info);
            temp = temp->link;
        }

        printf("\nSecond Half Circular: ");
        temp = first2;
        for(int i = mid; i < counter; i++){
            printf("%d ", temp->info);
            temp = temp->link;
        }

        printf("\n");
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
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    splice(&head);
    displayList(head);
}