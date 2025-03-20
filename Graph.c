#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct {
    int vertices;                       // Number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Initialize adjacency matrix with 0 (no edges)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjacencyMatrix[dest][src] = 1; // For undirected graph, add edge from dest to src
}

// Function for DFS traversal
void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;              // Mark the current vertex as visited
    printf("%d ", vertex);               // Print the vertex

    // Visit all adjacent vertices
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);      // Recursively perform DFS
        }
    }
}

// Function for BFS traversal
void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Array to keep track of visited vertices
    int queue[MAX_VERTICES];              // Queue for BFS
    int front = 0, rear = 0;

    visited[startVertex] = true;          // Mark the start vertex as visited
    queue[rear++] = startVertex;          // Enqueue the start vertex

    while (front < rear) {
        int vertex = queue[front++];     // Dequeue a vertex
        printf("%d ", vertex);           // Print the vertex

        // Visit all adjacent vertices
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;       // Mark as visited
                queue[rear++] = i;       // Enqueue the vertex
            }
        }
    }
}

// Main function
int main() {
    int vertices, edges, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices); // Create a graph

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Add edges to the graph
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS and BFS: ");
    scanf("%d", &startVertex);

    // Perform DFS traversal
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal: ");
    DFS(graph, startVertex, visited);
    printf("\n");

    // Perform BFS traversal
    printf("BFS Traversal: ");
    BFS(graph, startVertex);
    printf("\n");

    free(graph); // Free the graph memory
    return 0;
}