#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* first = NULL;
struct node* copy = NULL;

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

void copyLinkedList(){
    struct node* temp = first;
    struct node* temp2 = NULL;
    if(first == NULL){
        printf("Linked List not found");
    }
    else{
        copy = createNode(first->info);
        temp=first->link;
        temp2 = copy;
        while (temp != NULL) {
            temp2->link = createNode(temp->info);
            temp = temp->link; 
            temp2 = temp2->link; 
        }
    }
}

void display(){
    struct node* temp = first;
    while(temp != NULL){
        printf("%d , ",temp->info);
        temp = temp->link;
    }
    printf("\n");

    temp = copy;
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

    copyLinkedList();
    display();
}