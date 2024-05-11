#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 4
#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int vertex;
	struct queue* link;
};
typedef struct queue* queuePointer;

queuePointer front[MAX_VERTICES];
queuePointer rear[MAX_VERTICES];

queuePointer graph[MAX_VERTICES];
int n = MAX_VERTICES;
short int visited[MAX_VERTICES];


void addq(queuePointer*, queuePointer*, int);
int deleteq(queuePointer*);

short int degree[MAX_VERTICES];
//for (i=0; i<MAX_VERTICES; i++) degree[i] = 0;


void bfs(int v) {
	queuePointer w;
	queuePointer front = NULL, rear = NULL;
	printf("%d ", v);
	visited[v] = TRUE;
	addq(&front, &rear, v);

	while (front) {
		v = deleteq(&front);
		for (w = graph[v]; w; w = w->link)
			if (!visited[w->vertex]){
				printf("%d ", w->vertex);
				visited[w->vertex] = TRUE;
				addq(&front, &rear, w->vertex);
			}
	}
}

int IS_FULL(queuePointer t) {
	int result = (t == NULL);
	return result;
}

int IS_EMPTY(){
	return (front == rear);
}

void addq(queuePointer* pfront, queuePointer* prear, int item) {
	queuePointer temp = (queuePointer)malloc(sizeof(queue));
	
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->vertex= item;
	temp->link = NULL;
	if (*pfront)
		(*prear)->link = temp;
	else
		*pfront = temp; 
	*prear = temp;
}



int deleteq(queuePointer* pfront)
{
	queuePointer temp = *pfront;
	int item;

	if (front == rear) {
		printf("The queue is empty\n");
		exit(1);
	}
	
	item = temp->vertex;
	*pfront = temp->link;
	free(temp);
	return item;
}

void add_edge(int u, int v) {
	queuePointer temp = (queuePointer)malloc(sizeof(queue));
	temp->vertex = v;
	temp->link = graph[u];
	graph[u] = temp;
}

int main() {
	int i;

	for (i = 0; i < MAX_VERTICES; i++) 
		graph[i] = NULL;
	

	add_edge(0, 2);
	add_edge(0, 1);
	add_edge(1, 3);
	add_edge(1, 0);
	add_edge(2, 0);
	add_edge(3, 1);
		
		
	//printf("BFS traversal starting from vertex 0 : ");

	bfs(0);


	return 0;
}
