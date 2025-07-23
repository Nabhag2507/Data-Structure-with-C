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
    } else {
        struct node* temp = *head;
        while (temp->link != *head) {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = *head;
    }
}

void deleteFromPosition(struct node** head, int index){
    struct node* temp = *head;
    struct node* prev = NULL;
    struct node* curr = *head;

    if(*head == NULL){
        printf("Linked list not found");
    }
    else if(temp->link == temp){
        free(temp);
    }

    else if(index == 0){
        struct node* last = *head;
        while (last->link != *head) {
            last = last->link;
        }

        curr = *head;
        last->link = curr->link;
        *head = curr->link;
        free(curr);
    }
    else{
        int counter = 0;
        do{
            // printf("%d ",curr->info);
            prev = curr;
            curr = curr->link;
            counter++;
        }while(curr != temp && counter != index);

        if (curr == NULL) {
            printf("Node not found.\n");
        }

        prev->link = curr->link;
        free(curr);
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
    insertAtEnd(&head, 7);
    int index;
    printf("At which index you want to delete number :");
    scanf("%d",&index);

    deleteFromPosition(&head,index);
    displayList(head);
}