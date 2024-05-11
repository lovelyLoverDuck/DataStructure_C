#include <stdio.h> 
#define MAX_SIZE 6

void swap(int *x,  int *y){
	int temp = *y;
	*y = *x;
	*x = temp;
}

void print_list(int* numList){
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d  ", numList[i]);
	printf("\n");
}

void bubble_sort(int list[], int n) {
	int i, j;
	int flag = 1;

	for (i = n - 1; flag > 0; i--) 
	{
		//printf("i = %d\n", i);
		flag = 0;

		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1])
			{
				//printf("j = %d\n", j);
				//printf("swap(%d, %d)\n", list[j], list[j + 1]);
				swap(&list[j], &list[j + 1]);
				flag = 1;
				print_list(list);
			}
	}
}


int main() {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE] = { 20, 23,8,2,7,4 };


	bubble_sort(list, n);
	printf("\n-------------------\n");
	print_list(list);

	//for (i = 0; i < n; i++) 
	//	printf("%d  ", list[i]);
	
}
