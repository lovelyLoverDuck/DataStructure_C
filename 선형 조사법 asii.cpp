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

int main()
{

	const char* key = "for";

	int number = 0;


	while (*key)
	{
		printf("----------------------\n");
		printf("%s\n", key);
		printf("B-number = %d\n", number);
		number += *(key++);
		printf("A-number = %d\n", number);
	}



	 
	printf("%d\n", number % TABLE_SIZE);
	

}
