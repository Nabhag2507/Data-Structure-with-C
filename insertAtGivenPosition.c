#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* first = NULL;

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->info = info;
    return newNode;
}

void insertAtLast(int x){
    struct node* newNode = createNode(x);
    if(first == NULL){
        first = newNode;
    }
    else{
        struct node* temp = first;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
        // newNode->link = NULL;
    }
}

void insertAtMiddle(int x,int index){
    int counter = 0;
    struct node* newNode = createNode(x);
    struct node* temp = first;
    while(counter != index){
        temp = temp->link;
        counter++;
    }
    struct node* t = temp->link;
    temp->link = newNode;
    newNode->link = t;
}

void insertIntoSortedLinkedList(int x) {
    struct node* newNode = createNode(x);

    if (first == NULL || x < first->info) {
        newNode->link = first;
        first = newNode;
        return;
    }

    struct node* temp = first;

    while (temp->link != NULL && temp->link->info < x) {
        temp = temp->link;
    }

    // Insert in the middle or end
    newNode->link = temp->link;
    temp->link = newNode;
}


void display() {
    struct node* temp = first;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d , ", temp->info);
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
    insertAtLast(60);
    int x,index;

    // printf("At which position do you want to enter element :");
    // scanf("%d",&index);

    printf("Enter the Number :");
    scanf("%d",&x);
    insertIntoSortedLinkedList(x);
    // insertAtMiddle(x,index);
    display();
}