
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* link;
};
typedef struct node* node_pointer;

node_pointer graph[MAX_VERTICES];
int n = MAX_VERTICES;
short int visited[MAX_VERTICES];

void dfs(int v) {
    node_pointer w;
    visited[v] = TRUE;
   // printf("%-3d", v);

    for (w = graph[v]; w; w = w->link)
    {
        printf("graph[%d] : ", v);
        printf("if(!visited[%d])\n", w->vertex);

        if (!visited[w->vertex])
        {
            printf("dfs(%d)\n", w->vertex);
            dfs(w->vertex);

        }

        printf("------------------------------\n");
    }
  


}

void add_edge(int u, int v) {
    node_pointer temp;
    temp = (node*)malloc(sizeof(node));
    temp->vertex = v;
    temp->link = graph[u];
    graph[u] = temp;
}


int main() {
    int i;

    for (i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    add_edge(0, 2);
    add_edge(0, 1);

    add_edge(1, 4);
    add_edge(1, 3);
    add_edge(1, 0);


    add_edge(2, 6);
    add_edge(2, 5);
    add_edge(2, 0);

    add_edge(3, 7);
    add_edge(3, 1);

    add_edge(4, 7);
    add_edge(4, 1);

    add_edge(5, 7);
    add_edge(5, 2);

    add_edge(6, 7);
    add_edge(6, 2);

    add_edge(7, 6);
    add_edge(7, 5);
    add_edge(7, 4);
    add_edge(7, 3);



   printf("DFS traversal starting from vertex 0\n\n");

   dfs(0);
   printf("\n\n");

   return 0;
}

