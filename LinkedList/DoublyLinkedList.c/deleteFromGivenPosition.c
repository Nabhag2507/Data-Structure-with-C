#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    newNode->info = info;
    return newNode;
}

void insertAlLast(struct node** head,int info){
    struct node* newNode = createNode(info);
    if(*head == NULL){
        *head = newNode;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
    }
    else{
        struct node* temp = *head;
        while (temp->rptr != NULL){
            temp = temp->rptr;
        }
        temp->rptr = newNode;
        newNode->lptr = temp;
        newNode->rptr = NULL;
    }
}

void delete(struct node** head , int index){
    if(*head == NULL){
        printf("Linked List not found");
    }
    else{
        if(index == 1){
            struct node* temp = *head;
            (*head) = (*head)->rptr;
            (*head)->lptr = NULL;
            free(temp);
            return;
        }
        struct node* temp = *head;
        int counter = 1;
        while(counter != index && temp != NULL){
            temp = temp->rptr;
            counter++;
        }
        if(temp == NULL){
            printf("incorrect counter");
        }
        if(temp->rptr == NULL){
            temp->lptr->rptr = NULL;
            free(temp);
        }
        if(temp->rptr != NULL){
            temp->lptr->rptr = temp->rptr;
            temp->rptr->lptr = temp->lptr;
        }
        free(temp);
    }
}

void display(struct node* head){
    struct node* temp = head;
    while (temp != NULL){
        printf("%d , ",temp->info);
        temp = temp->rptr;
    }
}

void main () {
    struct node* head = NULL;

    insertAlLast(&head,10);
    insertAlLast(&head,20);
    insertAlLast(&head,30);
    insertAlLast(&head,40);
    insertAlLast(&head,50);

    int index;
    printf("At which index you want to delete node :");
    scanf("%d",&index);

    delete(&head,index);

    display(head);
}