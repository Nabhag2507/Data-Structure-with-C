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

int isSame(struct node* tree1,struct node* tree2){
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
    struct node* tree1 = createNode(1);
    tree1->lptr = createNode(2);
    tree1->rptr = createNode(3);
    tree1->lptr->lptr = createNode(4);
    tree1->lptr->rptr = createNode(5);

    struct node* tree2 = createNode(1);
    tree2->lptr = createNode(2);
    tree2->rptr = createNode(3);
    tree2->lptr->lptr = createNode(4);
    tree2->lptr->rptr = createNode(5);

    printf("%d",isSame(tree1,tree2));
}
