// CREATING TREE FROM PREORDER AND POSTORDER TRAVERSAL

#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to construct the tree
struct TreeNode* buildTree(int* pre, int* post,
                           int preStart, int preEnd,
                           int postStart, int postEnd) {
    if (preStart > preEnd) return NULL;

    // First node in preorder is root
    struct TreeNode* root = newNode(pre[preStart]);
    if (preStart == preEnd) return root; // leaf node

    // Next element in preorder is the left child
    int leftRootVal = pre[preStart + 1];

    // Find left root in postorder
    int i = postStart;
    while (i <= postEnd && post[i] != leftRootVal) i++;
    int leftSize = i - postStart + 1;

    // Build left and right subtrees
    root->left = buildTree(pre, post, preStart + 1, preStart + leftSize,postStart, i);
    root->right = buildTree(pre, post, preStart + leftSize + 1, preEnd,i + 1, postEnd - 1);

    return root;
}

// Wrapper function
struct TreeNode* constructFromPrePost(int* pre, int* post, int size) {
    return buildTree(pre, post, 0, size - 1, 0, size - 1);
}

// Utility: print inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Example usage
void main() {
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    struct TreeNode* root = constructFromPrePost(pre, post, size);

    printf("Inorder Traversal of constructed tree: ");
    inorder(root);
    printf("\n");
}
