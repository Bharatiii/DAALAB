#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF -1

int graph[MAX_NODES][MAX_NODES];
int distances[MAX_NODES];

int queue[MAX_NODES];
int front = 0, rear = -1;

void initializeGraph(int n) {
    for (int i = 1; i <= n; i++) {
        distances[i] = INF;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 2;
    graph[v][u] = 2;
}

void enqueue(int node) {
    queue[++rear] = node;
}

int dequeue() {
    return queue[front++];
}

void bfs(int start, int n) {
    distances[start] = 0;
    enqueue(start);

    while (front <= rear) {
        int current = dequeue();
        for (int i = 1; i <= n; i++) {
            if (graph[current][i] == 2 && distances[i] == INF) {
                distances[i] = distances[current] + 2;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, m; // n: number of nodes, m: number of edges
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    initializeGraph(n);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    bfs(startNode, n);

    printf("Shortest distances from node %d to all other nodes:\n", startNode);
    for (int i = 1; i <= n; i++) {
        if (i != startNode) {
            printf("Node %d: %d\n", i, distances[i]);
        }
    }

    return 0;
}