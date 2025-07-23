// WAP to swap Kth node from beginning with Kth node from end in a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *createNode(int info)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

void insertAtLast(struct node **head, int info)
{
    struct node *newNode = createNode(info);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void displayList(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list not found");
    }
    else
    {
        struct node *temp = head;

        while (temp != NULL)
        {
            printf("%d ,", temp->info);
            temp = temp->link;
        }
    }
}

void swapNodes(struct node **head, int index)
{
    if (*head == NULL)
    {
        printf("Linked list not found");
    }

    if (index == 0)
    {
        printf("Swapping head with itself is not needed.\n");
    }

    else
    {
        int counter = 0;
        struct node *prev = NULL;
        struct node *curr = *head;
        while (curr != NULL && counter != index-1)
        {
            prev = curr;
            curr = curr->link;
            counter++;
        }

        if (curr == NULL)
        {
            printf("Index out of bounds.\n");
        }
        
        struct node* temp = *head;
        *head = curr;
        prev->link = temp;
        struct node* tempcu = curr->link;
        curr->link = temp->link;
        temp->link = tempcu;
    }
}

void main()
{
    struct node *head = NULL;
    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);
    insertAtLast(&head, 50);

    int index;
    printf("Enter index you want to swap :");
    scanf("%d", &index);

    swapNodes(&head, index);
    displayList(head);
}