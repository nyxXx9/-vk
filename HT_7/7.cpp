void dfsComponent(int graph[MAX][MAX], int v, int visited[], int component[], int* size, int n) {
    visited[v] = 1;
    component[(*size)++] = v;
    for (int i = 1; i <= n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfsComponent(graph, i, visited, component, size, n);
        }
    }
}

void findConnectedComponents(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int component[MAX];
    int size = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            size = 0;
            dfsComponent(graph, i, visited, component, &size, n);

            printf("Component: ");
            for (int j = 0; j < size; j++)
                printf("%d ", component[j]);
            printf("\n");
        }
    }
}
