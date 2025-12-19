#include <stdbool.h>

bool isBipartiteBFS(int graph[MAX][MAX], int start, int n) {
    int color[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    color[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (graph[u][v]) {
                if (!color[v]) {
                    color[v] = -color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}
