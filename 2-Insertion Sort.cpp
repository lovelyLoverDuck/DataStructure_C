#include <stdio.h> 
#define MAX_SIZE 5

struct element{
	int key;
};

void insertion_sort(element list[], int n) {
	int i, j;
	element next;
	for (i = 1; i < n; i++) {
		next = list[i];
		for (j = i - 1; j >= 0 && next.key < list[j].key; j--)
			list[j + 1] = list[j];
		list[j + 1] = next;

		for (int s = 0; s < 5; s++)
			printf("%d\t",list[s]);
		printf("\n");
	}
	printf("\n=============================================\n");
}

int main() {
	int i;
	int n = MAX_SIZE;

	element list[MAX_SIZE] = {4,7,2,6,1};
	insertion_sort(list, n);


	for (i = 0; i < n; i++)
		printf("%d  ", list[i].key);

}
