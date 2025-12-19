#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int inorderKth(TreeNode* node, int k, int* counter) {
    if (!node) return -1;

    int left = inorderKth(node->left, k, counter);
    if (left != -1) return left;

    (*counter)++;
    if (*counter == k) return node->val;

    return inorderKth(node->right, k, counter);
}

int kthSmallest(TreeNode* root, int k) {
    int counter = 0;
    return inorderKth(root, k, &counter);
}

int main() {
    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);

    printf("3rd smallest: %d\n", kthSmallest(root, 3));
    printf("1st smallest: %d\n", kthSmallest(root, 1));

    return 0;
}
