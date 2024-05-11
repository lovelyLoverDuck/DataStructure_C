
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* graph[MAX_VERTICES];  
int n = MAX_VERTICES;
int visited[MAX_VERTICES];

void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = graph[u];
    graph[u] = new_node;
}

void dfs(int v) {
    Node* w;
    visited[v] = TRUE;
    printf("%-3d", v);

    for (w = graph[v]; w; w = w->next)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

int main() {

    for (int i = 0; i < n; i++) 
        graph[i] = NULL;
    

    add_edge(0, 4);
    add_edge(0, 2);
    add_edge(0, 1);

    add_edge(1, 3);
    add_edge(1, 2);
    add_edge(1, 0);
    
    add_edge(2, 4);
    add_edge(2, 1);
    add_edge(2, 0);

    add_edge(3, 4);
    add_edge(3, 1);

    add_edge(4, 3);
    add_edge(4, 2);
    add_edge(4, 0);

    dfs(0);

    return 0;
}
