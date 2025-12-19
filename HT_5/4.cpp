#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    int balanceFactor;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->balanceFactor = 0;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) { return a > b ? a : b; }

int calculateHeights(TreeNode* node) {
    if (!node) return 0;

    int leftHeight = calculateHeights(node->left);
    int rightHeight = calculateHeights(node->right);

    node->balanceFactor = leftHeight - rightHeight;

    return 1 + max(leftHeight, rightHeight);
}

void printTree(TreeNode* root) {
    if (!root) return;
    printf("Node %d: balance = %d\n", root->val, root->balanceFactor);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    calculateHeights(root);
    printTree(root);

    return 0;
}
