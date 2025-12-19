void dfs(TreeNode* root, int* arr, int* idx) {
    if (!root) {
        arr[(*idx)++] = INT_MIN;
        return;
    }
    arr[(*idx)++] = root->val;
    dfs(root->left, arr, idx);
    dfs(root->right, arr, idx);
}

bool isSymmetricDFS(TreeNode* root) {
    if (!root) return true;

    int* arr = malloc(1000 * sizeof(int));
    int idx = 0;
    dfs(root, arr, &idx);

    int j = idx - 1;
    for (int i = 0; i < idx/2; i++) {
        if (arr[i] != arr[j]) {
            free(arr);
            return false;
        }
        j--;
    }
    free(arr);
    return true;
}
