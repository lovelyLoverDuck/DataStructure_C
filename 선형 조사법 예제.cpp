#include <stdio.h>

#define TABLE_SIZE 10

// 해시 테이블 구조체 정의
typedef struct {
    int key;
    int value;
} HashTable;

// 해시 테이블 초기화
void initHashTable(HashTable table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1; // 비어 있는 상태를 나타내기 위해 -1로 초기화
        table[i].value = -1;
    }
}

// 해시 함수
int hashFunction(int key) {
    return key % TABLE_SIZE; // 간단하게 키를 테이블 크기로 나눈 나머지를 반환
}

// 선형 조사법으로 데이터 저장
void insert(HashTable table[], int key, int value) {
    int hashIndex = hashFunction(key);
    int currentIndex = hashIndex;

    while (table[currentIndex].key != -1) { // 다음 위치가 비어 있을 때까지 반복
        currentIndex = (currentIndex + 1) % TABLE_SIZE; // 다음 위치로 이동
        if (currentIndex == hashIndex) { // 테이블이 가득 찬 경우 종료
            printf("HashTable is full. Unable to insert.\n");
            return;
        }
    }

    table[currentIndex].key = key; // 데이터 저장
    table[currentIndex].value = value;
}

// 선형 조사법으로 데이터 검색
int search(HashTable table[], int key) {
    int hashIndex = hashFunction(key);
    int currentIndex = hashIndex;

    while (table[currentIndex].key != -1) { // 비어 있는 위치를 찾거나 키가 일치할 때까지 반복
        if (table[currentIndex].key == key) {
            return table[currentIndex].value; // 키에 해당하는 값을 반환
        }
        currentIndex = (currentIndex + 1) % TABLE_SIZE; // 다음 위치로 이동
        if (currentIndex == hashIndex) { // 전체 테이블을 확인한 경우 종료
            break;
        }
    }

    return -1; // 키를 찾지 못한 경우 -1 반환
}

// 해시 테이블 출력
void printHashTable(HashTable table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("Key: %d, Value: %d\n", table[i].key, table[i].value);
        //if (table[i].key != -1) {
          //  printf("Key: %d, Value: %d\n", table[i].key, table[i].value);
        //}


    }
}

int main() {
    HashTable table[TABLE_SIZE];
    initHashTable(table);

    // 데이터 삽입
    insert(table, 3, 123);
    insert(table, 12, 321);
    insert(table, 1, 456);
    insert(table, 8, 654);

    // 데이터 검색
    int value = search(table, 15);

    if (value != -1) 
        printf("Value: %d\n", value);
    
    else 
        printf("Key not found.\n");
    

    // 해시 테이블 출력
    printHashTable(table);

    return 0;
}