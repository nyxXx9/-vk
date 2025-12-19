#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int v, int visited[], int color, int n) {
    visited[v] = color;
    for (int i = 1; i <= n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, i, visited, color, n);
        }
    }
}

void findComponents(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int color = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, color, n);
            color++;
        }
    }
}
