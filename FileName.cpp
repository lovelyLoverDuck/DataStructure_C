#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 5

typedef struct node {
    int vertex;
    struct node* link;
} Node;

typedef Node* node_pointer;

// Global variables
bool visited[MAX_VERTICES];
node_pointer graph[MAX_VERTICES];

// Function to initialize the graph
void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        graph[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(int v, int w) {
    node_pointer newNode = (node_pointer)malloc(sizeof(Node));
    newNode->vertex = w;
    newNode->link = graph[v];
    graph[v] = newNode;
}

// Depth-First Search function
void dfs(int v) {
    node_pointer w;
    visited[v] = true;
    printf("%5d", v);

    for (w = graph[v]; w != NULL; w = w->link) {
        if (!visited[w->vertex]) {
            dfs(w->vertex);
        }
    }
}

int main() {
    initializeGraph();

    // Adding edges
    addEdge(0, 4);
    addEdge(0, 2);
    addEdge(0, 1);

    addEdge(1, 3);
    addEdge(1, 2);
    addEdge(1, 0);

    addEdge(2, 4);
    addEdge(2, 1);
    addEdge(2, 0);

    addEdge(3, 4);
    addEdge(3, 1);

    addEdge(4, 3);
    addEdge(4, 2);
    addEdge(4, 0);

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS traversal: ");
    dfs(startVertex);
    printf("\n");

    return 0;
}

