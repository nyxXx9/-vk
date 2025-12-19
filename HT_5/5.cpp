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

bool isMaxHeap(TreeNode* root) {
    if (!root) return true;

    TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool shouldBeLeaf = false;

    while (front < rear) {
        TreeNode* current = queue[front++];

        if (current->left) {
            if (shouldBeLeaf || current->left->val > current->val) return false;
            queue[rear++] = current->left;
        } else {
            shouldBeLeaf = true;
        }

        if (current->right) {
            if (shouldBeLeaf || current->right->val > current->val) return false;
            queue[rear++] = current->right;
        } else {
            shouldBeLeaf = true;
        }
    }
    return true;
}

int main() {
    TreeNode* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(9);
    root->left->left = newNode(5);
    root->left->right = newNode(6);

    printf(isMaxHeap(root) ? "Is Max Heap\n" : "Not a Max Heap\n");

    TreeNode* root2 = newNode(10);
    root2->left = newNode(12);
    root2->right = newNode(9);

    printf(isMaxHeap(root2) ? "Is Max Heap\n" : "Not a Max Heap\n");

    return 0;
}
