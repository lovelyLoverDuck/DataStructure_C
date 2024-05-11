#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 24


int Temp[MAX_ELEMENTS];
int cnt = 0;

typedef struct element {
	int key;
} element;

typedef struct node* treePointer;
typedef struct node {
	element data;
	treePointer leftchild, rightchild;
};

treePointer root;
void insert(treePointer*, int);
treePointer modifiedSearch(treePointer p, int x);
element* search(treePointer tree, int);
void open();
void inorder(treePointer tree);
void postorder(treePointer tree);
void preorder(treePointer tree);

int main()
{
	element* status;
	open();
	printf("Preorder :  ");
	preorder(root);
	printf("\n");
	printf("Inorder :   ");
	inorder(root);
	printf("\n");
	printf("Postorder : ");
	postorder(root);
	printf("\n");
	printf("Search :    ");
	for (int i = 0; i < cnt; i++)
	{
		status = search(root, Temp[i]);
		if (status == NULL) printf("0 "); //NULL���̸� ã�� ���� �����Ƿ� '0'
		else printf("1 "); //�����Ͱ��� ��ȯ�Ǹ� '1'
	}
	printf("\n");
	return 0;
}

void open()
{
	int temp;

	FILE* fp1 = fopen("input111.txt", "r");
	if (fp1 != NULL)
	{
		while ((fscanf(fp1, "%d", &temp) != EOF)) {

			insert(&root, temp);
		}
	}

	FILE* fp2 = fopen("input222.txt", "r");
	if (fp2 != NULL)
	{
		while ((fscanf(fp2, "%d", &Temp[cnt])) != EOF)
			cnt++;
	}

}

void insert(treePointer* node, int k)
{
	treePointer ptr, temp = modifiedSearch(*node, k);
	if (temp || !(*node)) {
		ptr = (treePointer)malloc(sizeof(*ptr));
		ptr->data.key = k;
		ptr->leftchild = NULL; ptr->rightchild = NULL;
		if (*node)
			if (k < temp->data.key) temp->leftchild = ptr;
		// ���⼭ temp�� �θ��̹Ƿ� ptr�� ���������� ��������
			else temp->rightchild = ptr; //ptr ū ���̸� ����������
		else *node = ptr;
	}
}
treePointer modifiedSearch(treePointer root, int k) //������ �������� Ž���Ͽ� ���ɿ��θ� ��ȯ
{
	treePointer temp = root;
	while (root)
	{
		temp = root;
		if (k < root->data.key) //���԰��� ������
			root = root->leftchild; //�������� ���� �ٽ� �˻�
		else if (k > root->data.key) //���԰��� ũ��
			root = root->rightchild; // ���������� ���� �ٽ� �˻�
		else
			return NULL;
	}
	return temp; // parent ��ġ ��ȯ
}
void inorder(treePointer tree)
{
	if (tree)
	{
		inorder(tree->leftchild);
		printf("%d ", tree->data.key);
		inorder(tree->rightchild);
	}
}
void preorder(treePointer tree)
{
	if (tree) {
		printf("%d ", tree->data.key);
		preorder(tree->leftchild);
		preorder(tree->rightchild);
	}
}
void postorder(treePointer tree)
{
	if (tree) {
		postorder(tree->leftchild);
		postorder(tree->rightchild);
		printf("%d ", tree->data.key);
	}
}

element* search(treePointer tree, int k)
{
	if (!tree) return NULL; //���� ������ NULL�� ��ȯ
	if (k == tree->data.key)return &(tree->data); //���� ������ ����Ÿ ������ ��ȯ
	if (k < tree->data.key) // ��ȸ
		return search(tree->leftchild, k);  //root���� ã�� ���� ������ ���� �ڽ����� �̵�
	return search(tree->rightchild, k); //ũ�� ���������� �̵�
}