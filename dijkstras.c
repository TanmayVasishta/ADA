#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10
#define INF INT_MAX

int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int start) {
    int dist[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", i);
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 10, 0, 0, 0, 0},
        {10, 0, 5, 0, 0, 0},
        {0, 5, 0, 20, 0, 0},
        {0, 0, 20, 0, 10, 0},
        {0, 0, 0, 10, 0, 5},
        {0, 0, 0, 0, 5, 0}
    };
    int n = 6;
    int start = 0;

    printf("Dijkstra's Algorithm:\n");
    dijkstra(graph, n, start);

    return 0;
}
