
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 30
#define TABLE_SIZE 13
#define IS_FULL(ptr) (!(ptr))

typedef struct {
	char key[MAX_CHAR];
} element;

typedef struct list* list_ptr;

typedef struct list {
	element item;
	list_ptr link;
};

list_ptr hash_table[TABLE_SIZE];

void init_table(list_ptr ht[]) {
	int i;

	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i] = (list_ptr)malloc(sizeof(struct list));
		if (ht[i] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(1);
		}
		ht[i]->item.key[0] = '\0';
		ht[i]->link = NULL;
	}
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
void chain_insert(element item, list_ptr ht[]) {
	int hash_value = hash(item.key);
	printf("%s : %d\n", item.key, hash_value);
	list_ptr ptr, trail = NULL;
	list_ptr lead = ht[hash_value];

	for (; lead; trail = lead, lead = lead->link)
		if (!strcmp(lead->item.key, item.key)) 
		{
			fprintf(stderr, "the key is in the table\n");
			exit(1);
		}


	ptr = (list_ptr)malloc(sizeof(list));

	if (IS_FULL(ptr)) {
		fprintf(stderr, "the memory is full\n");
		exit(1);
	}

	ptr->item = item;
	ptr->link = NULL;
	if (trail) trail->link = ptr;
	else ht[hash_value] = ptr;
}

void print_table(list_ptr ht[]) {
	printf("\nHash Table\n");
	printf("-----------\n");

	for (int i = 0; i < TABLE_SIZE; i++) {
		list_ptr ptr = ht[i];
		if (ptr != NULL) {
			printf("[%2d] : ", i);
			while (ptr != NULL) {
				printf("%s ", ptr->item.key);
				ptr = ptr->link;
			}
			printf("\n");
		}
	}
}


int main() {
	init_table(hash_table);

	element item;
	//const char* list[11] = { "acos","atoi", "char", "define","exp", "ceil", "cos","float", "atol", "floor","ctime" };
	const char* list[13] = { "map", "big", "hot", "hat", "tap", "ball", "cell", "pay", "mug", "joy", "pad", "run", "web" };

	for (int t = 0; t < 13; t++) {
		strcpy(item.key, list[t]);
		chain_insert(item, hash_table);
	}

	print_table(hash_table);

	return 0;
}


