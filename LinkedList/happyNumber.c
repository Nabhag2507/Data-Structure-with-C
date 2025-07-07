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

void displayList(struct node* head) {
    while (head != NULL) {
        printf("%d , ", head->info);
        head = head->link;
    }
}

void checkHappyNumber(struct node** head, int n) {
    int tempN = n;

    while (1) {
        int counter = 0;
        while (tempN > 0) {
            int digit = tempN % 10;
            counter += digit * digit;
            tempN /= 10;
        }

        struct node* temp = *head;
        if (*head != NULL) {
            do {
                if (temp->info == counter) {
                    printf("%d is NOT a Happy Number\n", n);
                    return;
                }
                temp = temp->link;
            } while (temp != *head);
        }

        struct node* newNode = createNode(counter);
        if (*head == NULL) {
            *head = newNode;
            newNode->link = newNode;
        } else {
            temp = *head;
            while (temp->link != *head) {
                temp = temp->link;
            }
            temp->link = newNode;
            newNode->link = *head;
        }

        if (counter == 1) {
            printf("%d is a Happy Number\n", n);
            return;
        }

        tempN = counter;
    }
}


void main () {
    struct node* head = NULL;
    int n;
    printf("Enter any number :");
    scanf("%d",&n);

    checkHappyNumber(&head,n);
}