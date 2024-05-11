#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10
#define STRING_LENGTH 20

typedef struct {
    char key[STRING_LENGTH];
    int value;
} HashNode;

HashNode hash_table[TABLE_SIZE];

// 해시 함수: 문자열을 해시값으로 변환하는 함수
int hash_function(const char* key) {
    int hash = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        hash += key[i];
    }

    return hash % TABLE_SIZE;
}

// quadratic probing을 사용하여 충돌 해결
void insert(const char* key, int value) {
    int index = hash_function(key);
    printf("%c : %d\n",key,index);
    int i = 0;
    bool inserted = false;

    while (!inserted) {
        int position = (index + i * i) % TABLE_SIZE;

        if (hash_table[position].value == 0) {  // 해당 위치가 비어있으면
            strcpy(hash_table[position].key, key);
            hash_table[position].value = value;
            inserted = true;
        }
        else {
            i++;
        }
    }
}

// 해시 테이블에서 키를 검색하고 값 반환
int search(const char* key) {
    int index = hash_function(key);
    int i = 0;

    while (hash_table[(index + i * i) % TABLE_SIZE].value != 0) {
        if (strcmp(hash_table[(index + i * i) % TABLE_SIZE].key, key) == 0) {
            return hash_table[(index + i * i) % TABLE_SIZE].value;
        }

        i++;
    }

    return -1;  // 키를 찾지 못한 경우
}

// 테스트를 위한 해시 테이블 출력 함수
void print_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) 
        printf("Key: %d, Value: %d\n", i, hash_table[i].value);
}


int main() {
    // 초기화
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(hash_table[i].key, "");
        hash_table[i].value = 0;
    }

    // 값 삽입
    insert("apple", 5);
    insert("banana", 10);
    insert("orange", 15);
    insert("grape", 20);

    // 검색
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'cherry': %d\n", search("cherry"));

    // 해시 테이블 출력
    print_hash_table();

    return 0;
}
