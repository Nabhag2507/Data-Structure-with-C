#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};
struct node* first = NULL;

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

void insertAtFirst(int x){
    struct node* newNode = createNode(x);
    if(first == NULL){
        first = newNode;
    }
    else{
        newNode->link = first;
        first = newNode;
    }
}

void deleteAtFirst(){
    if(first == NULL){
        printf("Linked list not found");
    }
    else if(first->link == NULL){
        free(first);
        first = NULL;
    }
    else{
        struct node* temp = first;
        first = first->link;
        temp->link = NULL;
        free(temp);
    }
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

void deleteAtLast(){
    if(first == NULL){
        printf("Linked list not found");
    }
    else if(first->link == NULL){
        free(first);
        first = NULL;
    }
    else{
        struct node* pred = NULL;
        struct node* curr = first;       

        while(curr->link != NULL){
            pred = curr;
            curr = curr->link;
        }
        pred->link = NULL;
        free (curr);
    }
}

void deleteFromPosition(int x) {
    if (first == NULL) {
        printf("Linked list is empty.\n");
    }
    
    else if (first->info == x) {
        free(first);
    }
    struct node* prev = NULL;
    struct node* curr = first;


    while (curr != NULL && curr->info != x) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        printf("Node with value %d not found.\n", x);
    }

    prev->link = curr->link;
    free(curr);
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
    while (1){
        printf("Enter your choice :\n");
        printf("Enter 1 for insert at first position :\n");
        printf("Enter 2 for delete at first position :\n");
        printf("Enter 3 for insert at last position :\n");
        printf("Enter 4 for delete at last position :\n");
        printf("Enter 5 for display :\n");
        printf("Enter 6 for exit the loop :\n");

        int c;
        scanf("\n%d",&c);
        switch(c){
            case 1:{
                int num;
                printf("Enter number you want to insert :");
                scanf("%d",&num);
                insertAtFirst(num);
                display();
                break;
            }
            case 2:
                deleteAtFirst();
                display();
                break;
            case 3:{
                int num;
                printf("Enter number you want to insert :");
                scanf("%d",&num);
                insertAtLast(num);
                display();
                break;
            }
            case 4:
                deleteAtLast();
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
        }
        if (c == 6) {
            break;
        }
    }
}