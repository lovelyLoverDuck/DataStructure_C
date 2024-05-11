
#include <stdio.h> 
#define MAX_SIZE 10
#define SWAP(x, y, tmp){tmp = x; x=y; y = tmp;}

struct element {
	int key;
};

void quicksort(element list[], int left, int right) {
	int pivot, i, j;
	element temp;
	for (i = 0; i < 10; i++)
		printf("%d ", list[i].key);
	printf("\n------------------------------------\n");

	if (left < right) {
		i = left; j = right + 1;
		pivot = list[left].key;
		do {

			do i++;
			while (list[i].key < pivot);
			do j--;
			while (list[j].key > pivot);
			if (i < j)
				SWAP(list[i], list[j], temp);

		} while (i < j);
		for (i = 0; i < 10; i++)
			printf("<%d> ", list[i].key);
		printf("\n------------------------------------\n");
		SWAP(list[left], list[j], temp);
		for (i = 0; i < 10; i++)
			printf("[%d] ", list[i].key);
		printf("\n------------------------------------\n");
		quicksort(list, left, j - 1);
		quicksort(list, j + 1, right);



	}
}

int main() {
	int i;

	int n = MAX_SIZE;

	element list[MAX_SIZE] = {26, 5,37,1,61,11,59,15,48,19 };
	quicksort(list, 0, 9);

	for (i = 0; i < n; i++)
		printf("%d  ", list[i].key);
}
