#include <stdio.h>

#define MAX_ELEMENTS 10
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct {
    int key;
} element;

element heap[MAX_ELEMENTS] = { 26,5,77,1,61,11,59,15,48,19 };

void adjust(element list[], int root, int n) {
    int child, rootkey;
    element temp;
    temp = list[root - 1];  // Adjusted indexing
    rootkey = list[root - 1].key;
    child = 2 * root; /* left child */
    while (child <= n) {
        if ((child < n) && (list[child - 1].key < list[child].key))  // Adjusted indexing
            child++;
        if (rootkey > list[child - 1].key)  // Adjusted indexing
            break;
        else {
            list[child / 2 - 1] = list[child - 1];  // Adjusted indexing
            child *= 2;
        }
    }
    list[child / 2 - 1] = temp;  // Adjusted indexing
}

void heapsort(element list[], int n) {
    /* perform a heapsort on the array */
    int i, j;
    element temp;
    for (i = n / 2; i > 0; i--) /* initial heap construction */
        adjust(list, i, n);

    printf("Max Heap: ");
    for (i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", list[i].key);
    }
    printf("\n");

    for (i = n; i > 0; i--) { /* heap adjust */  // Adjusted indexing
        SWAP(list[0], list[i - 1], temp);
        adjust(list, 1, i - 1);  // Adjusted indexing
    }
}

int main() {

    int i;
    printf("Original Array: ");
    for (i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");

    heapsort(heap, MAX_ELEMENTS);

    printf("Sorted Array: ");
    for (i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");

    return 0;
}
