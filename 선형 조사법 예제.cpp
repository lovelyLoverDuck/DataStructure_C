#include <stdio.h>

#define TABLE_SIZE 10

// �ؽ� ���̺� ����ü ����
typedef struct {
    int key;
    int value;
} HashTable;

// �ؽ� ���̺� �ʱ�ȭ
void initHashTable(HashTable table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1; // ��� �ִ� ���¸� ��Ÿ���� ���� -1�� �ʱ�ȭ
        table[i].value = -1;
    }
}

// �ؽ� �Լ�
int hashFunction(int key) {
    return key % TABLE_SIZE; // �����ϰ� Ű�� ���̺� ũ��� ���� �������� ��ȯ
}

// ���� ��������� ������ ����
void insert(HashTable table[], int key, int value) {
    int hashIndex = hashFunction(key);
    int currentIndex = hashIndex;

    while (table[currentIndex].key != -1) { // ���� ��ġ�� ��� ���� ������ �ݺ�
        currentIndex = (currentIndex + 1) % TABLE_SIZE; // ���� ��ġ�� �̵�
        if (currentIndex == hashIndex) { // ���̺��� ���� �� ��� ����
            printf("HashTable is full. Unable to insert.\n");
            return;
        }
    }

    table[currentIndex].key = key; // ������ ����
    table[currentIndex].value = value;
}

// ���� ��������� ������ �˻�
int search(HashTable table[], int key) {
    int hashIndex = hashFunction(key);
    int currentIndex = hashIndex;

    while (table[currentIndex].key != -1) { // ��� �ִ� ��ġ�� ã�ų� Ű�� ��ġ�� ������ �ݺ�
        if (table[currentIndex].key == key) {
            return table[currentIndex].value; // Ű�� �ش��ϴ� ���� ��ȯ
        }
        currentIndex = (currentIndex + 1) % TABLE_SIZE; // ���� ��ġ�� �̵�
        if (currentIndex == hashIndex) { // ��ü ���̺��� Ȯ���� ��� ����
            break;
        }
    }

    return -1; // Ű�� ã�� ���� ��� -1 ��ȯ
}

// �ؽ� ���̺� ���
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

    // ������ ����
    insert(table, 3, 123);
    insert(table, 12, 321);
    insert(table, 1, 456);
    insert(table, 8, 654);

    // ������ �˻�
    int value = search(table, 15);

    if (value != -1) 
        printf("Value: %d\n", value);
    
    else 
        printf("Key not found.\n");
    

    // �ؽ� ���̺� ���
    printHashTable(table);

    return 0;
}