#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* lptr;
    struct node* rptr;
};

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = info;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

struct node* insertNode(int info,struct node* root){
    if(root == NULL){
        root = createNode(info);
        return root;
    }
    else if(info < root->info){
        root->lptr = insertNode(info,root->lptr);
    }
    else if(info > root->info){
        root->rptr = insertNode(info,root->rptr);
    }
    return root;
}

int exist(int fnd,struct node* root){
    if(root == NULL){
        return 0;
    }
    else if(root->info == fnd){
        return 1;
    }
    else if(fnd < root->info){
        return exist(fnd,root->lptr);
    }
    else if(fnd > root->info){
        return exist(fnd,root->rptr);
    }
    return 0;
}

void preOrderTraversal(struct node* root) {
    if (root == NULL){
        return;
    }
    printf("%d ", root->info);
    preOrderTraversal(root->lptr);
    preOrderTraversal(root->rptr);
}

void main () {
    struct node* root = NULL;
    root=insertNode(30,root);
    root=insertNode(15,root);
    root=insertNode(10,root);
    root=insertNode(5,root);
    root=insertNode(45,root);
    root=insertNode(35,root);

    preOrderTraversal(root);
    printf("\n%d",exist(99,root));
}