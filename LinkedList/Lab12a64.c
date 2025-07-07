#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* first = NULL;

struct node* createNode(int info){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->info = info;
    return newNode;
}

void insertAtLast(int info){
    struct node* newNode = createNode(info);
    if(first == NULL){
        first = newNode;
    }
    else{
        struct node* temp = first;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void reverseLinkedList(){
    struct node* prev = NULL;
    struct node* curr = first;

    if(first == NULL){
        printf("Linked list not found");
    }
    else{
        while(curr != NULL){
            struct node* nextNode = curr->link;
            curr->link = prev;
            prev = curr;
            curr =nextNode;
        }
        first = prev;
    }
}

void display(){
    struct node* temp = first;
    while(temp != NULL){
        printf("%d , ",temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void main () {
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(40);
    insertAtLast(50);

    display();
    reverseLinkedList();
    display();
}