#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash_function(key);
    int i = 0;
    bool inserted = false;

    while (!inserted) {
        int position = (index + i * i) % TABLE_SIZE;

        if (hash_table[position] == 0) {  // 해당 위치가 비어있으면
            hash_table[position] = key;  // 값을 저장
            inserted = true;
        }
        else {
            i++;
        }
    }
}

void print_hash_table() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, hash_table[i]);
    }
}

int main() {

    for (int i = 0; i < TABLE_SIZE; i++) 
        hash_table[i] = 0;
    


    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(7);


    print_hash_table();

    return 0;
}
