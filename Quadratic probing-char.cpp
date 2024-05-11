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

// �ؽ� �Լ�: ���ڿ��� �ؽð����� ��ȯ�ϴ� �Լ�
int hash_function(const char* key) {
    int hash = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        hash += key[i];
    }

    return hash % TABLE_SIZE;
}

// quadratic probing�� ����Ͽ� �浹 �ذ�
void insert(const char* key, int value) {
    int index = hash_function(key);
    printf("%c : %d\n",key,index);
    int i = 0;
    bool inserted = false;

    while (!inserted) {
        int position = (index + i * i) % TABLE_SIZE;

        if (hash_table[position].value == 0) {  // �ش� ��ġ�� ���������
            strcpy(hash_table[position].key, key);
            hash_table[position].value = value;
            inserted = true;
        }
        else {
            i++;
        }
    }
}

// �ؽ� ���̺��� Ű�� �˻��ϰ� �� ��ȯ
int search(const char* key) {
    int index = hash_function(key);
    int i = 0;

    while (hash_table[(index + i * i) % TABLE_SIZE].value != 0) {
        if (strcmp(hash_table[(index + i * i) % TABLE_SIZE].key, key) == 0) {
            return hash_table[(index + i * i) % TABLE_SIZE].value;
        }

        i++;
    }

    return -1;  // Ű�� ã�� ���� ���
}

// �׽�Ʈ�� ���� �ؽ� ���̺� ��� �Լ�
void print_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) 
        printf("Key: %d, Value: %d\n", i, hash_table[i].value);
}


int main() {
    // �ʱ�ȭ
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(hash_table[i].key, "");
        hash_table[i].value = 0;
    }

    // �� ����
    insert("apple", 5);
    insert("banana", 10);
    insert("orange", 15);
    insert("grape", 20);

    // �˻�
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'cherry': %d\n", search("cherry"));

    // �ؽ� ���̺� ���
    print_hash_table();

    return 0;
}
