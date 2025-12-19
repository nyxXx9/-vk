#include <limits.h>

#define INF INT_MAX

void dijkstra(int graph[MAX][MAX], int start, int n, int dist[]) {
    int visited[MAX] = {0};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[start] = 0;

    for (int count = 0; count < n-1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}
