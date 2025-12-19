#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isCompleteTree(TreeNode* root) {
    if (!root) return true;

    TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool shouldBeLeaf = false;

    while (front < rear) {
        TreeNode* node = queue[front++];

        if (!node) {
            shouldBeLeaf = true;
        } else {
            if (shouldBeLeaf) return false;
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    return true;
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf(isCompleteTree(root) ? "true\n" : "false\n");
    return 0;
}
