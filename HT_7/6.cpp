int isBipartiteDFS(int graph[MAX][MAX], int v, int color[], int c, int n) {
    color[v] = c;
    for (int i = 1; i <= n; i++) {
        if (graph[v][i]) {
            if (!color[i]) {
                if (!isBipartiteDFS(graph, i, color, -c, n))
                    return 0;
            } else if (color[i] == c) {
                return 0;
            }
        }
    }
    return 1;
}

int isBipartite(int graph[MAX][MAX], int n) {
    int color[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!isBipartiteDFS(graph, i, color, 1, n))
                return 0;
        }
    }
    return 1;
}
