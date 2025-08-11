#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lptr;
    struct node* rptr;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

void preOrderTraversal(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->lptr);
    preOrderTraversal(root->rptr);
}

int main() {
    struct node* root = createNode(1);
    root->lptr = createNode(2);
    root->rptr = createNode(3);
    root->lptr->lptr = createNode(4);
    root->lptr->rptr = createNode(5);

    preOrderTraversal(root);  // no need for &root here
    return 0;
}
