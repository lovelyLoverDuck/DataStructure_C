#include <time.h>
#include <stdio.h>

int main(void)
{
	int  i;
	double start, end;


	start = (double)clock() / CLOCKS_PER_SEC;

	end = (((double)clock()) / CLOCKS_PER_SEC);

	printf("���α׷� ���� �ð� :%lf\n", (end - start));
}