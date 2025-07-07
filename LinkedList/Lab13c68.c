// Write a program to swap two consecutive nodes in the linked list. Don’t change the values of nodes, implement by changing the link of the nodes.
// Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
// Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7

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

void swapConsecutiveNodes(struct node** head){
    if(*head == NULL){
        printf("Linked List not found");
    }
    else{
        struct node* curr = *head;

        while(curr != NULL && curr->link != NULL){
            int a = curr->info;
            curr->info = curr->link->info;
            curr->link->info = a;

            curr = curr->link->link;
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
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    insertAtEnd(&head,7);
    insertAtEnd(&head,8);
    insertAtEnd(&head,9);

    swapConsecutiveNodes(&head);
    displayList(head);
}