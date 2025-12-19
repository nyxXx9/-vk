#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* buildTree(int* arr, int size, int i) {
    if (i >= size || arr[i] == -1) {
        return NULL;
    }

    TreeNode* root = createNode(arr[i]);
    root->left = buildTree(arr, size, 2 * i + 1);
    root->right = buildTree(arr, size, 2 * i + 2);

    return root;
}

void printTree(TreeNode* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

int main() {
    int arr[] = {8, 9, 11, 7, 16, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = buildTree(arr, size, 0);

    printf("In-order traversal: ");
    printTree(root);
    printf("\n");

    return 0;
}
