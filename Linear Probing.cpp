#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 10
#define TABLE_SIZE 13

typedef struct {
	char key[MAX_CHAR];
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[]) {
	for (int i = 0; i < TABLE_SIZE; i++) 
		ht[i].key[0] = NULL;
}

int transform(char* key) {
	int number = 0;

	while (*key)
		number += *key++;

	return number;
}

int hash(char* key) {
	return(transform(key) % TABLE_SIZE);
}

void linear_insert(element item, element ht[]) {
	int i, hash_value;
	hash_value = hash(item.key);
	i = hash_value;

	while (strlen(ht[i].key)) {
		if (!strcmp(ht[i].key, item.key)) {
			fprintf(stderr, "duplicate entry\n");
			exit(1);
		}
		 
		i = (i + 1) % TABLE_SIZE;
	
		if (i == hash_value) { 
			fprintf(stderr, "the table is full\n");
			exit(1);
		}
	}

	ht[i] = item;
}

void print_table(element ht[]) {
    printf("\nHash Table\n");
    printf("-----------\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
		printf("[%2d] : %s\n", i, ht[i].key);
    }
}

int main() {
    init_table(hash_table);

    element item;
	//const char* list[11] = { "acos","atoi", "char", "define","exp", "ceil", "cos","float", "atol", "floor","ctime" };
    const char* list[7] = { "for", "do","while" ,"if", "else", "function", "w" };

    for (int t = 0; t < 7; t++) {
        strcpy(item.key, list[t]);
        linear_insert(item, hash_table);
    }

    print_table(hash_table);

    return 0;
}

