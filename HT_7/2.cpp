int hasCycleDFS(int graph[MAX][MAX], int v, int parent, int visited[], int n) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (hasCycleDFS(graph, i, v, visited, n))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(graph, i, -1, visited, n))
                return 1;
        }
    }
    return 0;
}
