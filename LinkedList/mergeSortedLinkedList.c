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

void merge(struct node** head1,struct node** head2){
    struct node* temp1 = *head1;
    struct node* temp2 = *head2;

    while(temp1 != NULL){
        while(temp2 != NULL){
            struct node* temp;
            if(temp1->info > temp2->info){
                temp = temp1->link;
                temp1->link = temp2;
                temp2->link = temp;
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
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
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    insertAtEnd(&head1, 5);
    insertAtEnd(&head1, 15);
    insertAtEnd(&head1, 25);
    insertAtEnd(&head1, 35);

    insertAtEnd(&head2, 10);
    insertAtEnd(&head2, 20);
    insertAtEnd(&head2, 30);
    insertAtEnd(&head2, 40);

    merge(&head1 , &head2);

    displayList(head1);
}
