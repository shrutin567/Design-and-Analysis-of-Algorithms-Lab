#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int** graph, int src, int V) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    clock_t start = clock();
    dijkstra(graph, 0, V);
    clock_t end = clock();
    
    printf("Time Complexity: %2f", (double)(end-start));

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}


