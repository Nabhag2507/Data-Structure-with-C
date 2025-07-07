#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* first = NULL;
struct node* first1 = NULL;

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
        while (temp->link != NULL){  // Fix here
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void insertAtLast1(int info){
    struct node* newNode = createNode(info);
    if(first1 == NULL){
        first1 = newNode;
    }
    else{
        struct node* temp = first;
        while (temp->link != NULL){  // Fix here
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void copyLinkedList(){
    struct node* temp = first;
    while(temp != NULL){
        
    }
}

void display(){
    if(first == NULL){
        printf("Linked List not found\n");
    }
    else{
        struct node* temp = first;
        while (temp != NULL){
            printf("%d ,", temp->info);  // Fix here
            temp = temp->link;
        }
        printf("\n");
    }
}

void main () {
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(40);
    insertAtLast(50);
    display();
}
