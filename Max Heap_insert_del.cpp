#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
} element;


element heap[MAX_ELEMENTS];

int n = 0;

void insert_max_heap(element item, int* n) {

	int i;

	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full. \n");
		exit(1);
	}

	i = ++(*n);

	while ((i != 1) && (item.key > heap[i / 2].key)) 
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}


element delete_max_heap(int* n) {
	element item, temp;

	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty\n");
		exit(1);
	}

	item = heap[1]; 
	temp = heap[(*n)--];

	int parent = 1;
	int child = 2;

	while (child <= *n) 
	{
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;

		if (temp.key >= heap[child].key)
			break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;
	return item;
}

void print_heap()
{
	for (int i = 1; i <= n; i++)
		printf("[%d | %d] ", i, heap[i].key);
	
	printf("END\n");
}

int main() {
	int choice;
	element item;
	/*
	while (1) {
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Quit\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the element to insert: ");
			scanf_s("%d", &item.key);
			insert_max_heap(item, &n);
			printf("Element inserted.\n");
			break;

		case 2:
			if (HEAP_EMPTY(n)) {
				printf("The heap is empty.\n");
			}
			else {
				item = delete_max_heap(&n);
				printf("Deleted element: %d\n", item.key);
			}
			break;

		case 3:
			printf("Exiting the program.\n");
			printf("------------\n");
			print_heap();
			exit(0);

		default:
			printf("Invalid choice. Please try again.\n");
		}
	}
	*/

	int list[6] = {6,7,8,10,12,14 };
	for (int k = 0; k < 6; k++)
	{
		item.key = list[k];
		insert_max_heap(item, &n);
	}

	print_heap();

	delete_max_heap(&n);
	print_heap();

	return 0;
}
