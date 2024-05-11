#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 60

typedef struct node{
    int comp_num;
    char name[MAX_NAME_LENGTH + 1];
    int stock;
    int reorder;
    node* left;
    node* right;
}Node;

Node* insert(Node* root, int comp_num, char name[], int stock, int reorder) {
    if (root == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->comp_num = comp_num;
        strncpy(new_node->name, name, MAX_NAME_LENGTH);
        new_node->stock = stock;
        new_node->reorder = reorder;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (comp_num < root->comp_num) 
        root->left = insert(root->left, comp_num, name, stock, reorder);
    
    else if (comp_num > root->comp_num) 
        root->right = insert(root->right, comp_num, name, stock, reorder);
    
    else 
        printf("Duplicate component number - Comp # %d\n", comp_num);
    
    return root;
}

Node* delete_com(Node* root, int comp_num) {
    if (root == NULL) {
        printf("No such component - Comp # %d\n", comp_num);
        return root;
    }
    if (comp_num < root->comp_num) {
        root->left = delete_com(root->left, comp_num);
    }
    else if (comp_num > root->comp_num) {
        root->right = delete_com(root->right, comp_num);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->comp_num = temp->comp_num;
        strncpy(root->name, temp->name, MAX_NAME_LENGTH);
        root->stock = temp->stock;
        root->reorder = temp->reorder;
        root->right = delete_com(root->right, temp->comp_num);
    }
    return root;
}

Node* search(Node* root, int comp_num) 
{
    if (!root) return NULL;
    if (root->comp_num == comp_num) return root;
    if (comp_num < root->comp_num) 
        return search(root->left, comp_num);
    return search(root->right, comp_num);
}

void add_stock(Node* root, int comp_num, int quantity) {
    Node* node = search(root, comp_num);

    if (node == NULL) {
        printf("No such component - Comp # %d\n", comp_num);
        return;
    }
    node->stock += quantity;
}

void remove_stock(Node* root, int comp_num, int quantity) {
    Node* node = search(root, comp_num);
    if (node == NULL) {
        printf("No such component - Comp # %d\n", comp_num);
        return;
    }
    if (node->stock < quantity) {
        printf("Insufficient stock - Comp # %d\n", comp_num);
        return;
    }
    node->stock -= quantity;
}

void print_inventory_find(Node* root) {
    if (root == NULL) {
        return;
    }
    print_inventory_find(root->left);

    printf("%-8d %-15s %-20d %-5d", root->comp_num, root->name, root->stock, root->reorder);

    if (root->stock < root->reorder) 
    {
        printf(" *reorder required* ");
    }
    printf("\n");
    print_inventory_find(root->right);
}

void print_inventory(Node* root)
{
    printf("\n%-8s %-15s %-20s %-5s\n", "Comp #", "Name", "Current Stock", "Reorder level");
    print_inventory_find(root);
}

int main() {
    Node* root = NULL;
    FILE* fp;
    char filename[] = "input1.txt";
    char command;
    int comp_num, stock, reorder, quantity;
    char name[MAX_NAME_LENGTH + 1];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return 1;
    }

    while (fscanf(fp, "%c", &command) == 1) {
        switch (command) {
        case 'N':
            (fscanf(fp, "%d %13[^\n] %d %d\n", &comp_num, name, &stock, &reorder) == 4);
            root = insert(root, comp_num, name, stock, reorder);

            break;
        case 'D':
            fscanf(fp, "%d\n", &comp_num);
            root = delete_com(root, comp_num);
            break;
        case 'A':
            fscanf(fp, "%d %d\n", &comp_num, &quantity);
            add_stock(root, comp_num, quantity);
            break;
        case 'R':
            fscanf(fp, "%d %d\n", &comp_num, &quantity);
            remove_stock(root, comp_num, quantity);
            break;
        case 'P':
            print_inventory(root);
            break;
        case 'X':
            break;
        }
    }

    fclose(fp);
    return 0;
}
