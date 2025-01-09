#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct Stack { // ��� 1 �������
    int top;
    TYPE data[NMAX];
} stack;

// ��� 2 �������
struct Node { // ����������� ���� ���������� ������
    TYPE data;
    struct Node* next;
};

typedef struct { // ����������� ��������� �������
    struct Node* front;
    struct Node* back;
} queue_list;

// ��� 3 ������� 
typedef struct {
    int top;
    int data[NMAX];
} StackInt;

typedef struct {
    int top;
    char data[NMAX];
} StackChar;

// ������� ��� 1 �������
int isempty(stack* s);  // ���������, ���� ���� ���� {top==0} ������� 1, ����� 0
int isfull(stack* s);   // ���������, ���� ���� ����� {top==NMAX-1} ������� 1, ����� 0
int push(stack* s, TYPE a); //��������� ������� � � ����  {top=top+1, data[top]=a}, ���� ���� �� �����
TYPE pop(stack* s); // ������� ������� {data[top]}, ������ ��� �� ����� {top=top-1}, ���� ���� �� ����
TYPE top(stack* s); //������� �������� �������� � ������� ����� {return data[top]}
void display(stack* s); // ����� ����������� ����� �� �����

// ������� ��� 2 �������
void enQueue(queue_list* que, TYPE element); // �������� ������� � �������
TYPE deQueue(queue_list* que);  // ������� ������� �� �������
void display1(queue_list* que); // ������� ���������� ������� que �� �����.

// ������� ��� 3 ������� 
void initStackInt(StackInt* s);
void initStackChar(StackChar* s);
int isEmptyInt(StackInt* s);
int isEmptyChar(StackChar* s);
void pushInt(StackInt* s, int a);
void pushChar(StackChar* s, char a);
int popInt(StackInt* s);
char popChar(StackChar* s);
int calculate(int a, int b, char op);
int chislo(char c);

int main() {
    setlocale(LC_ALL, "RUS");

    // ������� 1
    stack s;
    s.top = -1; // ���� ����. ����� ������ � -1, �.�. ��� push ������� �������������� top.
    char input1[NMAX];

    printf("������� ������ ��� �����: ");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = 0; // ������� ������ ����� ������

    for (int i = 0; input1[i] != '\0'; i++) {
        if (!push(&s, input1[i])) {
            printf("���� �����, ���������� �������� '%c'.\n", input1[i]);
            break;
        }
    }

    printf("���������� �����:\n");
    display(&s);

    // ������� 2
    printf("\n");

    queue_list Str;
    Str.front = NULL;
    Str.back = NULL;

    char temp[100];
    printf("\n������� ������ ��� �������: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0; // ������� ������ ����� ������

    for (int i = 0; temp[i] != '\0'; i++) {
        enQueue(&Str, temp[i]);
    }

    printf("\n���������� �������:\n");
    display1(&Str);

    // ������� 3
    printf("\n");

    StackInt chisla;
    StackChar znak;
    initStackInt(&chisla);
    initStackChar(&znak);
    char input2[NMAX];

    printf("������� ��������� (������������� =): ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = 0;  // ������� ������ ����� ������

    int i = 0;
    while (input2[i] != '=' && input2[i] != '\0') {
        if (chislo(input2[i])) {
            int num = 0;
            while (chislo(input2[i]))
                num = num * 10 + (input2[i++] - '0');
            pushInt(&chisla, num);
        }
        else if (input2[i] == '+' || input2[i] == '-') {
            while (!isEmptyChar(&znak)) {
                int b = popInt(&chisla);
                int a = popInt(&chisla);

                char op = popChar(&znak);
                int res = calculate(a, b, op);
                pushInt(&chisla, res);
            }
            pushChar(&znak, input2[i++]);
        }
        else if (input2[i] == ' ')
            i++;
        else {
            printf("������: ������������ ������ '%c' � ���������.\n", input2[i]);
            return 1;
        }
    }


    while (!isEmptyChar(&znak)) {
        int b = popInt(&chisla);
        int a = popInt(&chisla);
        char op = popChar(&znak);
        int res = calculate(a, b, op);
        pushInt(&chisla, res);
    }

    if (!isEmptyInt(&chisla))
        printf("���������: %d\n", popInt(&chisla));
    else
        printf("������: ������������ ��������� (�� �������� ����������).\n");

    return 0;
}

// ���������, �������� �� ���� ������
int isempty(stack* s) { 
    return s->top == -1;
}

// ��������� �������� �� ���� ������
int isfull(stack* s) { 
    return s->top == NMAX - 1; 
}

// �������� ������� a �� ������� ����� s.
int push(stack* s, TYPE a) { 
    if (isfull(s)) {
        return 0; // ���� �����, �� ������� ��������
    }
    s->top++;
    s->data[s->top] = a;
    return 1; // ������� ��������
}

//  ��������� � ���������� ������� � ������� ����� s.
TYPE pop(stack* s) { 
    if (isempty(s)) {
        return '\0'; // ���� ����, ���������� null char
    }
    TYPE result = s->data[s->top];
    s->top--;
    return result;
}

// ���������� �������� �������� �� ������� ����� s, �� �������� ���.
TYPE top(stack* s) { 
    if (isempty(s)) {
        return '\0'; // ���� ����, ���������� null char
    }
    return s->data[s->top];
}

// ������� ���������� ����� s �� �����.
void display(stack* s) { 
    int i = s->top;
    while (i >= 0) {
        printf(FTYPE, s->data[i--]);
    }
    printf("\n");
}

// ������� ��� ���������� �������� � ����� �������
void enQueue(queue_list* que, TYPE element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("������ ��������� ������!\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;

    if (que->back == NULL) { // ������� �����
        que->front = newNode;
        que->back = newNode;
    }
    else { // ������� �� �����
        que->back->next = newNode;
        que->back = newNode;
    }
}

// ������� ��� ���������� �������� �� ������ �������
TYPE deQueue(queue_list* que) {
    if (que->front == NULL) {
        return '\0'; // ���������� NULL char, ���� ������� �����.
    }

    struct Node* temp = que->front;
    TYPE data = temp->data;

    que->front = temp->next;
    if (que->front == NULL) {
        que->back = NULL; // ���� ������� ����� ������, back ���� ������ ����� NULL
    }
    free(temp);
    return data;
}

// ������� ���������� ������� que �� �����.
void display1(queue_list* que) {
    struct Node* temp = que->front;
    while (temp != NULL) {
        printf(FTYPE, temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// �������������� ���� ����� �����, ������������ top � -1.
void initStackInt(StackInt* s) {  
    s->top = -1; 
}

// �������������� ���������� ����, ������������ top � - 1.
void initStackChar(StackChar* s) { 
    s->top = -1; 
}
// ���������, ���� �� ���� ����� �����.
int isEmptyInt(StackInt* s) { 
    return s->top == -1; 
}

// ���������, ���� �� ���������� ����.
int isEmptyChar(StackChar* s) { 
    return s->top == -1; 
}

// ��������� ����� ����� a � ���� ����� �����.
void pushInt(StackInt* s, int a) { 
    s->data[++s->top] = a; 
}

//  ��������� ������ a � ���������� ����.
void pushChar(StackChar* s, char a) { 
    s->data[++s->top] = a; 
}

// ��������� � ���������� ����� ����� �� ����� ����� �����
int popInt(StackInt* s) { 
    return isEmptyInt(s) ? "������" : s->data[s->top--];
}

// ��������� � ���������� ������ �� ����������� �����
char popChar(StackChar* s) { 
    return isEmptyChar(s) ? '\0' : s->data[s->top--]; 
}

//  ��������� �������������� �������� ��� ����� ������ ������� a � b � ����������� �� ��������� op.
int calculate(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    default:  return "������";
    }
}

// ��������, �������� �� ������ ������ (0-9)
int chislo(char c) {
    return c >= '0' && c <= '9';
}