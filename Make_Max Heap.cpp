#include <stdio.h>

#define MAX_ELEMENTS 11

typedef struct {
    int key;
} element;

element heap[MAX_ELEMENTS] = {12,34,3,19,2,7,4,11,87,81,27};

void adjust(element list[], int root, int n) {
    int child, rootkey;

    element temp;

    temp = list[root - 1];

    rootkey = list[root - 1].key;

    child = 2 * root;

    while (child <= n) 
    {
        if ((child < n) && (list[child - 1].key < list[child].key))
            child++;

        if (rootkey > list[child - 1].key)
            break;

        else 
        {
            list[child / 2 - 1] = list[child - 1];
            child *= 2;
        }

    }

    list[child / 2 - 1] = temp;

}

void heapsort(element list[], int n) {
    int i, j;
    element temp;
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n);
}

void print_arr(){
    for (int i = 0; i < MAX_ELEMENTS; i++) 
        printf("[%2d] ", heap[i].key);
    
    printf("\n");
}

int main() {
    printf("Original : ");
    print_arr();

    heapsort(heap, MAX_ELEMENTS);

    printf("Max Heap : ");
    print_arr();


    return 0;
}
