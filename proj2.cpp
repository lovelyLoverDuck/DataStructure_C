/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct enroll_s {
    int data;
    int id_num;
    int course_num;
    struct enroll_s* right;
    struct enroll_s* left;
} *enroll_sp;

int invalid = 0;

void push(enroll_s** head, int data, int data2) {
    enroll_s* current = *head;
    enroll_s* newNode = (enroll_s*)malloc(sizeof(enroll_s));

    while (current != NULL)
    {
        if (current->id_num == data) {
            return;
        }
        current = current->right;
    }
    newNode->id_num = data;
    newNode->course_num = data2;
    newNode->right = *head;
    *head = newNode;
}
void push2(enroll_s** head, int data) {
    enroll_s* current = *head;
    enroll_s* newNode = (enroll_s*)malloc(sizeof(enroll_s));

    while (current != NULL)
    {
        if (current->course_num == data) {
            return;
        }
        current = current->right;
    }
    newNode->course_num = data;
    newNode->right = *head;
    *head = newNode;
}


struct enroll_s* sortedMerge(struct enroll_s* a, struct enroll_s* b)
{

    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }
    struct enroll_s* result = NULL;
    if (a->id_num <= b->id_num)
    {
        result = a;
        result->right = sortedMerge(a->right, b);
    }
    else {
        result = b;
        result->right = sortedMerge(a, b->right);
    }
    return result;
}
struct enroll_s* sortedMerge2(struct enroll_s* a, struct enroll_s* b)
{
    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }

    struct enroll_s* result = NULL;

    if (a->course_num <= b->course_num)
    {
        result = a;
        result->right = sortedMerge2(a->right, b);
    }
    else {
        result = b;
        result->right = sortedMerge2(a, b->right);
    }

    return result;
}

void frontBackSplit( enroll_s* source,  enroll_s** frontRef, enroll_s** backRef)
{
    if (source == NULL || source->right == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
    enroll_s* slow = source;
    enroll_s* fast = source->right;
    while (fast != NULL)
    {
        fast = fast->right;
        if (fast != NULL)
        {
            slow = slow->right;
            fast = fast->right;
        }
    }

    *frontRef = source;
    *backRef = slow->right;
    slow->right = NULL;
}


void mergesort(struct enroll_s** head)
{

    if (*head == NULL || (*head)->right == NULL) {
        return;
    }
    struct enroll_s* a;
    struct enroll_s* b;
    frontBackSplit(*head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    *head = sortedMerge(a, b);
}

void mergesort2(struct enroll_s** head)
{

    if (*head == NULL || (*head)->right == NULL) {
        return;
    }
    struct enroll_s* a;
    struct enroll_s* b;
    frontBackSplit(*head, &a, &b);
    mergesort2(&a);
    mergesort2(&b);
    *head = sortedMerge2(a, b);
}
int atoiSub(char* str) {

    int tmp = 0;
    while (*str)
    {
        tmp = tmp * 10 + (int)(*str - 48);
        str++;
    }
    return tmp;
}

int length(enroll_s* ptr) { 
    int count = 0;
    while (ptr) {
        count++;
        ptr = ptr->right;
    }
    return count;
}

enroll_s* newNode(int data, enroll_s* next) 
{
    enroll_s* node = (enroll_s*)malloc(sizeof(enroll_s));
    node->data = 0;
    node->course_num = data;
    node->right = next;
    return node;
}
void make_linked(int numLists ,int listLength, enroll_s* cou, enroll_s** lists)
{
    enroll_s* cu = cou;
    enroll_s** under = lists;
    for (int i = 0; i < numLists; i++)
    {
        enroll_s* head = newNode(cu->course_num , NULL);
        under[i] = head;

        for (int j = 1; j < listLength; j++)
        {
            head->right = newNode(cu->course_num, NULL);
            head = head->right;
        }
        cu = cu->right;
    }
}
void dob_link(enroll_s* up, enroll_s* side, enroll_s** list)
{
    enroll_s* id = up;
    enroll_s* cu = side;
    enroll_s** under = list;
    int i = 0;
    while (id)
    {
        id->left = under[i];
        id = id->right;
        i += 1;
    }
    i = 0;
    while (cu)
    {
        cu->left = under[i];
        cu = cu->right;
        i += 1;
    }
}
int checkdataZE(enroll_s* side)
{
    enroll_s* cu = side;
    int cntcu = 0;
    cu = cu->left;
    while (cu)
    {
        if (cu->data == 1)
            cntcu = 10;
        cu = cu->right;
    }

    if (cntcu == 10)
        return 1;
}

void printfIN(enroll_s* side , FILE* file)
{
    enroll_s* cu = side;
    if (checkdataZE(cu))
    {
        fprintf(file, "%d : ", cu->course_num);
        cu = cu->left;

        while (cu)
        {
            if (cu->data == 1)
                fprintf(file, "%d  ", cu->id_num);
            cu = cu->right;

        }
        fprintf(file, "\n");
    }
}

void input(enroll_s* up, enroll_s** under, int listLength, int numLists)
{
    enroll_s* Q = up;
    enroll_s** QQ = under;

    int A[500];
    for (int k = 0; k < listLength; k++)
    {
        A[k] = Q->id_num;
        Q = Q->right;
    }

    for (int k = 0; k <numLists; k++)
    {
        for (int j = 0; j < listLength; j++)
        {
            QQ[k]->id_num = A[j];
            QQ[k] = QQ[k]->right;
        }
    }
}
int delcnt = 0;
void indata(int idNUM, int cuNUM, enroll_s* up2, enroll_s* side2, FILE* file, char* word)
{
    enroll_s* culist2 = side2;
    for (int i = 1; i < cuNUM; i++)
        culist2 = culist2->right;

    culist2 = culist2->left;

    for (int i = 1; i < idNUM; i++)
        culist2 = culist2->right;

    if (strcmp(word, "D") == 0)
    {
        if (culist2->data == 1)
            culist2->data = 0;
        else 
            fprintf(file, "%d %d %s **Not Enrolled**\n\n", culist2->id_num, culist2->course_num, word);

        delcnt += 1;
    }
        
        
    else if (strcmp(word, "A") == 0){
        if (culist2->data == 1)
        {
            fprintf(file, "%d %d %s **Duplicate Enrollment**\n\n", culist2->id_num, culist2->course_num, word);
            invalid += 1;
        }
        else
            culist2->data = 1;
    }

}

void checkdata(int id, int cu, char* word, enroll_s* up, enroll_s* side, FILE* file)
{
    enroll_s* idlist = up;
    enroll_s* culist = side;
    int idwhere = 1; 
    int cuwhere = 1;
    while (idlist)
    {
        if (idlist->id_num == id)
            break;
        idlist = idlist->right;
        idwhere += 1;
    }

    while (culist)
    {
        if (culist->course_num == cu)
            break;
        culist = culist->right;
        cuwhere += 1;
    }
    indata(idwhere, cuwhere, up, side, file, word);
}

int main(void)
{
    enroll_s* id_list = NULL;
    enroll_s* cu_list = NULL;

    FILE* fp;
    FILE* fp2;
    FILE* fp3;
    FILE* www;
    char id_inf[50], cu_inf[50], word3[50];
    int cnt = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }
  
    fp2 = fopen("output.txt", "w");
    if (fp2 == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }
    www = fopen("input.txt", "r");
    if (www == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }
    printf("File opened\n");
    while (fscanf(fp, "%s %s %s\n", id_inf, cu_inf, word3) == 3){

        if (atoi(id_inf) < 2000 || atoi(id_inf) > 2499)        {
            fprintf(fp2, "%s  %s  %s  **invalid student ID**\n\n", id_inf, cu_inf, word3);
            invalid += 1;
        }


        else if (atoi(cu_inf) < 100 || atoi(cu_inf) > 134){
            fprintf(fp2, "%s  %s  %s  **Invalid Course ID**\n\n", id_inf, cu_inf, word3);
            invalid += 1;
        }

        else if (strcmp(word3, "A") == 0)
        {
            push(&id_list, atoi(id_inf), atoi(cu_inf));
            push2(&cu_list, atoi(cu_inf));
        }
        else if (strcmp(word3, "D") == 0);
        else
        {
            fprintf(fp2, "%s  %s  %s  ** not 'A' or 'D'**\n\n", id_inf, cu_inf, word3);
            invalid += 1;
        }
        cnt += 1;
    }

    mergesort(&id_list);
    mergesort2(&cu_list);

    int numLists = length(cu_list);
    int listLength =  length(id_list);

    enroll_s** lists = (enroll_s**)malloc(numLists * sizeof(enroll_s*));
    make_linked(numLists, listLength, cu_list, lists);
    dob_link(id_list, cu_list, lists);
    input(id_list, lists, listLength, numLists);

    while (fscanf(www, "%s %s %s\n", id_inf, cu_inf, word3) == 3)
    {
        int id = atoi(id_inf);
        int cu = atoi(cu_inf);

        if ((atoi(id_inf) > 2000 && atoi(id_inf) < 2499 && atoi(cu_inf) > 100 || atoi(cu_inf) < 134))
        {
            if (strcmp(word3, "A") == 0 || (strcmp(word3, "D") == 0))
                checkdata(id, cu, word3, id_list, cu_list, fp2);
        }

    }

    while (cu_list)
    {
        printfIN(cu_list, fp2);
        cu_list = cu_list->right;
    }
    if(cnt == cnt-invalid)
        fprintf(fp2, "no errors\n\n", cnt, cnt - invalid, delcnt);
    else
        fprintf(fp2 ,"\n\n[input report] number of lines read : % d   valid registration : %d    valid cancellation : %d\n\n", cnt, cnt-invalid, delcnt);
    fclose(fp);
    fclose(fp2);
    fclose(www);
    return 0;

}

*/