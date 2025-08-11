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

void postOrderTraversal(struct node* root) {
    if (root == NULL)
        return;

        postOrderTraversal(root->lptr);
        postOrderTraversal(root->rptr);
        printf("%d ", root->data);
}

int main() {
    struct node* root = createNode(1);
    root->lptr = createNode(2);
    root->rptr = createNode(3);
    root->lptr->lptr = createNode(4);
    root->lptr->rptr = createNode(5);

    postOrderTraversal(root);  // no need for &root here
    return 0;
}
