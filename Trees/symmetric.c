#include <stdio.h>
#include <stdlib.h>

struct node {
    int info ;
    struct node* lptr;
    struct node* rptr;
};

struct node* createNode(int info ) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info  = info ;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

int isSymmetric(struct node* root){
    struct node* tree1 = root->lptr;
    struct node* tree2 = root->rptr;

    if(tree1 == NULL && tree2 == NULL){
        return 1;
    }
    else if(tree1 == NULL || tree2 == NULL){
        return 0;
    }
    return ((tree1->info == tree2->info) && 
            (isSame(tree1->lptr,tree2->lptr)) && 
            (isSame(tree1->rptr,tree2->rptr)));
}

void main() {
    struct node* root = createNode(8);
    
    root->lptr = createNode(5);
    root->rptr = createNode(5);
    root->lptr->lptr = createNode(3);
    root->lptr->rptr = createNode(6);
    root->rptr->lptr = createNode(6);
    root->rptr->rptr = createNode(3);

    printf("%d",isSymmetric(root));
}
