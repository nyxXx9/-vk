#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

bool isSymmetricBFS(TreeNode* root) {
    if (!root) return true;

    TreeNode** queue = malloc(1000 * sizeof(TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* left = queue[front + i];
            TreeNode* right = queue[front + levelSize - 1 - i];

            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
        }

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = queue[front++];
            if (node) {
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
    }
    free(queue);
    return true;
}
