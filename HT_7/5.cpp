bool isTree(int graph[MAX][MAX], int start, int n) {
    int visited[MAX] = {0};
    int parent[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 1; v <= n; v++) {
            if (graph[u][v]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    parent[v] = u;
                    queue[rear++] = v;
                } else if (parent[u] != v) {
                    return false;
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) count += visited[i];
    return count == n;
}
