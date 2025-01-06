#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#ifndef _LIST_H
#define _LIST_H

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List*);   /* ������������� ������ ������ ���������� */
void insertfront(List*, int val);   /* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertback(List*, int val);   /* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertfront_str(List*, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
void insertback_str(List*, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
bool isempty(List*); /* ���������, �������� �� ������ ������*/
int length(List); /* ����������� ����� ������ */
void destroyItem(List*, List node); /* �������� ��������� ���� node �� ������ */
struct listitem* getitem_int(List, int n); /* ���������� ���� �� ��������� n � ���� number*/
struct listitem* getitem_str(List, char* str); /* ���������� ���� �� ��������� str � ���� name*/
void printList(List list); /* ����� �� ����� ��� �������� ��������� ������ */
void printNumberedList(List list); /* */
void insertInMiddle(List* list, char* itemName); /* ��������� ����� ������� � �������� ������������ ������ */

#endif /* _LIST_H */

int main() {
    setlocale(LC_ALL, "RUS");

    List list;
    initlist(&list);

    // ������� 2.1 "�������" ���������, ������� 15 - 10 = 5

    /*������� �������� ���������������� ������ �� 7 ����� �����.
    �������� � ������ ����� 10 ����� ������� �������� � ������������� ���������.*/

    int num_elements = 7;
    int val;
    printf("������� %d ����� �����:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("����� %d: ", i + 1);
        scanf_s("%d", &val);
        insertback(&list, val);
    }
    printf("������ �� ��������������: ");
    printList(list);

    // ��������� 10 ����� ������� �������������� ��������
    List current = list;
    while (current != NULL) {
        if (current->number < 0) {

            List new_node = (List)malloc(sizeof(struct listitem));
            if (new_node == NULL) {
                fprintf(stderr, "������ ��������� ������\n");
                exit(1);
            }
            new_node->number = 10;
            new_node->next = current->next;
            current->next = new_node;

            current = new_node->next;

        }
        else {
            current = current->next;
        }
    }

    printf("������ ����� ��������������: ");
    printList(list);

    // ����������� ������, ���������� ��� ������.
    current = list;
    while (current != NULL) {
        List temp = current;
        current = current->next;
        free(temp);
    }

    initlist(&list);

    // ������� 2.2 "�������" ���������, ������� 15 - 8 = 7

    /* 7. ��� - ���� �������
        -������� ������ �� 10 ��������� �������.
        - ��������� �������� � �������� ������.
        - �������� �������� � ���� ���������������� ������.
        - ������� �������� � ������ ������.*/

    char* tovar[] = { "������", "����", "����", "���", "�����", "������", "������", "���", "����", "���" };
    for (int i = 0; i < 10; i++) {
        insertback_str(&list, tovar[i]);
    }
    printf("\n\n�������� ������:\n");
    printNumberedList(list);

    // 2. ��������� �������� � ��������
    insertInMiddle(&list, "�������");

    printf("\n������ ����� ���������� � ��������:\n");
    printNumberedList(list);

    // 3. ������� �������� � ������ ������

    if (!isempty(&list)) {
        destroyItem(&list, list);
    }

    printf("\n������ ����� �������� � ������:\n");
    printNumberedList(list);

    // ����������� ������
    current = list;
    while (current != NULL) {
        List temp = current;
        current = current->next;
        free(temp);
    }
}

/* ������������� ������ ������ ���������� */
void initlist(List* list) { 
    *list = NULL;
}

/* ������� ������ ���� � ������ �������� ������ */
void insertfront(List* list, int val) { 
    List new_node = (List)malloc(sizeof(struct listitem)); // ��������� ������ ��� ������ ����
    if (new_node == NULL) {
        return;
    }
    new_node->number = val; // ������������� ������ ����
    new_node->next = *list; // ��������� �� ������ ���� ������
    *list = new_node; // ���������� ��������� �� ������ ������
}

/* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertback(List* list, int val) { 
    List new_node = (List)malloc(sizeof(struct listitem)); // ��������� ������ ��� ������ ����
    if (new_node == NULL) {
        return;
    }
    new_node->number = val; // ������������� ������ ����
    new_node->next = NULL; // ��������� �� ��������� ���� � ������

    if (*list == NULL) {  // ���� ������ ����, �� ����� ���� ���������� ������
        *list = new_node; // � ������������ ��������� ������.
    }
    else {
        List current = *list;  // ��������� ��������� �� ������ ������
        while (current->next != NULL) { // ���� �� ������ �� ���������� ���� 
            current = current->next; //������������ �� ��������� ����
        }
        current->next = new_node; // ���������� ��������� �� ����� ������
    }
}

/* ������� � ������ ����� ����� �� ��������� str � ���� name */
void insertfront_str(List* list, char* str) { 
    List new_node = (List)malloc(sizeof(struct listitem)); // ��������� ������ ��� ������ ����
    if (new_node == NULL) {
        return;
    }
    strncpy(new_node->name, str, sizeof(new_node->name) - 1); // �������� ������
    new_node->name[sizeof(new_node->name) - 1] = '\0'; // ������ ������ ����� ����-���������������
    new_node->next = *list; // ��������� �� "������" ������ �������
    *list = new_node; // ��������� �� ������ ������ ������
}

/* ������� � ������ ����� ����� �� ��������� str � ���� name */
void insertback_str(List* list, char* str) {
    List new_node = (List)malloc(sizeof(struct listitem)); // ��������� ������ ��� ������ ����
    if (new_node == NULL) {
        return;
    }
    strncpy(new_node->name, str, sizeof(new_node->name) - 1); // �������� ������
    new_node->name[sizeof(new_node->name) - 1] = '\0'; // ������ ������ ����� ����-���������������
    new_node->next = NULL; // ����� ���� - ��������� 

    if (*list == NULL) { // ���� ������ ����, �� ����� ���� ���������� ������
        *list = new_node;// � ������������ ��������� ������
    }
    else {
        List current = *list; // �������� ��������� �� ������
        while (current->next != NULL) { // ���� �� ������ �� ���������� ���� 
            current = current->next; //������������ �� ��������� ����
        }
        current->next = new_node; // ���������� ��������� �� ����� ������
    }
}

/* ���������, �������� �� ������ ������*/
bool isempty(List* list) { 
    return *list == NULL;
}

/* ����������� ����� ������ */
int length(List list) { 
    int count = 0; // ������� ����� ������
    List current = list;
    while (current != NULL) { // ���� �������� �� ������ �� ����� ������
        count++;
        current = current->next; // ����������� �� ����. �������
    }
    return count;
}

/* �������� ��������� ���� node �� ������ */
void destroyItem(List* list, List node) { 
    if (*list == NULL || node == NULL) { // �������� �� ������ ������
        return;
    }

    if (*list == node) { // �������� ������� ����
        *list = node->next;
        free(node);
        return;
    }

    List current = *list; // ��������� �� ������ ������
    while (current != NULL && current->next != node) { // ���� �� ����� �� ����� ������ � ���� �� ������ ������ ����
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        return;
    }

    current->next = node->next; // �������������� ��������� � ���������� �� ���������
    free(node); // ����������� ������ ���������� ����
}

/* ���������� ���� �� ��������� n � ���� number*/
struct listitem* getitem_int(List list, int n) { 
    List current = list;
    while (current != NULL) { // ���� ��������� �� ����� ����� ������
        if (current->number == n) {
            return current; // ���� ���� ���� ����� ��������� �������� - ����� ������� ����
        }
        current = current->next;
    }
    return NULL;
}

/* ���������� ���� �� ��������� str � ���� name*/
struct listitem* getitem_str(List list, char* str) { 
    List current = list;
    while (current != NULL) {
        if (strcmp(current->name, str) == 0) { // ����� �� ������ �������� ���� �������� ������
            return current; //����� ����
        }
        current = current->next;
    }
    return NULL;
}

/* ����� �� ����� ��� �������� ��������� ������ */
void printList(List list) { 
    List current = list;
    while (current != NULL) {
        printf("%d ", current->number); // ������� �� ����� �������� �������� ����
        current = current->next;
    }
    printf("\n");
}

/* ������� �� ����� �������� ������ (������) � ��������������� ����*/
void printNumberedList(List list) { 
    List current = list;
    int count = 1; // ��� ��������� ������
    while (current != NULL) {
        printf("%d. %s\n", count++, current->name); // ������� ����� �������� �������� � ������ � ���� name �������� ����
        current = current->next;
    }
}

/* ��������� ����� ������� (����) � �������� ������������ ������.*/
void insertInMiddle(List* list, char* itemName) { 
    int len = length(*list); // ����������� ������� ����� ������
    if (len == 0) {
        insertback_str(list, itemName); // ���� ������ ����, �� ������� ����������� � �����(������) ������
    }
    else {
        int middle = len / 2; // ������� �������� ������
        List new_node = (List)malloc(sizeof(struct listitem)); // �������� ������ ��� ������ ����
        if (new_node == NULL) {
            fprintf(stderr, "������ ��������� ������");
            exit(1);
        }

        strncpy(new_node->name, itemName, sizeof(new_node->name) - 1); // ���������� ������ itemName � ���� name ������ ����.
        new_node->name[sizeof(new_node->name) - 1] = '\0'; // ������ ����������� ����-������������

        if (middle == 0) { // ���� �������� ���, �� ����� ������� ����������� � ������ ������
            insertfront_str(list, itemName);
            return;
        }

        List current = *list;
        for (int i = 1; i < middle; i++) { 
            current = current->next;
        }

        new_node->next = current->next; // ��������� �� ����� ���� = ��������� �� ���� ����� ���������
        current->next = new_node; // ��������� ����� ���� � ������
    }
}