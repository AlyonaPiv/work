#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct Stack { // для 1 задания
    int top;
    TYPE data[NMAX];
} stack;

// для 2 задания
struct Node { // Определение узла связанного списка
    TYPE data;
    struct Node* next;
};

typedef struct { // Определение структуры очереди
    struct Node* front;
    struct Node* back;
} queue_list;

// для 3 задания 
typedef struct {
    int top;
    int data[NMAX];
} StackInt;

typedef struct {
    int top;
    char data[NMAX];
} StackChar;

// функции для 1 задания
int isempty(stack* s);  // проверить, если стек пуст {top==0} вернуть 1, иначе 0
int isfull(stack* s);   // проверить, если стек полон {top==NMAX-1} вернуть 1, иначе 0
int push(stack* s, TYPE a); //поместить элемент а в стек  {top=top+1, data[top]=a}, если стек не полон
TYPE pop(stack* s); // вернуть элемент {data[top]}, удалив его из стека {top=top-1}, если стек не пуст
TYPE top(stack* s); //вернуть значение элемента в вершине стека {return data[top]}
void display(stack* s); // вывод содержимого стека на экран

// функции для 2 задания
void enQueue(queue_list* que, TYPE element); // добавить элемент в очередь
TYPE deQueue(queue_list* que);  // извлечь элемент из очереди
void display1(queue_list* que); // Выводит содержимое очереди que на экран.

// функции для 3 задания 
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

    // задание 1
    stack s;
    s.top = -1; // Стек пуст. Нужно начать с -1, т.к. при push сначала инкрементируем top.
    char input1[NMAX];

    printf("Введите строку для стека: ");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = 0; // убираем символ новой строки

    for (int i = 0; input1[i] != '\0'; i++) {
        if (!push(&s, input1[i])) {
            printf("Стек полон, невозможно добавить '%c'.\n", input1[i]);
            break;
        }
    }

    printf("Содержимое стека:\n");
    display(&s);

    // задание 2
    printf("\n");

    queue_list Str;
    Str.front = NULL;
    Str.back = NULL;

    char temp[100];
    printf("\nВведите строку для очереди: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0; // Убираем символ новой строки

    for (int i = 0; temp[i] != '\0'; i++) {
        enQueue(&Str, temp[i]);
    }

    printf("\nСодержимое очереди:\n");
    display1(&Str);

    // задание 3
    printf("\n");

    StackInt chisla;
    StackChar znak;
    initStackInt(&chisla);
    initStackChar(&znak);
    char input2[NMAX];

    printf("Введите выражение (заканчивается =): ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = 0;  // убираем символ новой строки

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
            printf("Ошибка: некорректный символ '%c' в выражении.\n", input2[i]);
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
        printf("Результат: %d\n", popInt(&chisla));
    else
        printf("Ошибка: некорректное выражение (не осталось результата).\n");

    return 0;
}

// проверяет, является ли стек пустым
int isempty(stack* s) { 
    return s->top == -1;
}

// проверяет является ли стек полным
int isfull(stack* s) { 
    return s->top == NMAX - 1; 
}

// Помещает элемент a на вершину стека s.
int push(stack* s, TYPE a) { 
    if (isfull(s)) {
        return 0; // Стек полон, не удалось добавить
    }
    s->top++;
    s->data[s->top] = a;
    return 1; // Успешно добавлен
}

//  Извлекает и возвращает элемент с вершины стека s.
TYPE pop(stack* s) { 
    if (isempty(s)) {
        return '\0'; // Стек пуст, возвращаем null char
    }
    TYPE result = s->data[s->top];
    s->top--;
    return result;
}

// Возвращает значение элемента на вершине стека s, не извлекая его.
TYPE top(stack* s) { 
    if (isempty(s)) {
        return '\0'; // Стек пуст, возвращаем null char
    }
    return s->data[s->top];
}

// Выводит содержимое стека s на экран.
void display(stack* s) { 
    int i = s->top;
    while (i >= 0) {
        printf(FTYPE, s->data[i--]);
    }
    printf("\n");
}

// Функция для добавления элемента в конец очереди
void enQueue(queue_list* que, TYPE element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;

    if (que->back == NULL) { // Очередь пуста
        que->front = newNode;
        que->back = newNode;
    }
    else { // Очередь не пуста
        que->back->next = newNode;
        que->back = newNode;
    }
}

// Функция для извлечения элемента из начала очереди
TYPE deQueue(queue_list* que) {
    if (que->front == NULL) {
        return '\0'; // Возвращаем NULL char, если очередь пуста.
    }

    struct Node* temp = que->front;
    TYPE data = temp->data;

    que->front = temp->next;
    if (que->front == NULL) {
        que->back = NULL; // Если очередь стала пустой, back тоже должен стать NULL
    }
    free(temp);
    return data;
}

// Выводит содержимое очереди que на экран.
void display1(queue_list* que) {
    struct Node* temp = que->front;
    while (temp != NULL) {
        printf(FTYPE, temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Инициализирует стек целых чисел, устанавливая top в -1.
void initStackInt(StackInt* s) {  
    s->top = -1; 
}

// Инициализирует символьный стек, устанавливая top в - 1.
void initStackChar(StackChar* s) { 
    s->top = -1; 
}
// Проверяет, пуст ли стек целых чисел.
int isEmptyInt(StackInt* s) { 
    return s->top == -1; 
}

// Проверяет, пуст ли символьный стек.
int isEmptyChar(StackChar* s) { 
    return s->top == -1; 
}

// Добавляет целое число a в стек целых чисел.
void pushInt(StackInt* s, int a) { 
    s->data[++s->top] = a; 
}

//  Добавляет символ a в символьный стек.
void pushChar(StackChar* s, char a) { 
    s->data[++s->top] = a; 
}

// Извлекает и возвращает целое число из стека целых чисел
int popInt(StackInt* s) { 
    return isEmptyInt(s) ? "ошибка" : s->data[s->top--];
}

// Извлекает и возвращает символ из символьного стека
char popChar(StackChar* s) { 
    return isEmptyChar(s) ? '\0' : s->data[s->top--]; 
}

//  Выполняет арифметическую операцию над двумя целыми числами a и b в зависимости от оператора op.
int calculate(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    default:  return "ошибка";
    }
}

// Проверка, является ли символ цифрой (0-9)
int chislo(char c) {
    return c >= '0' && c <= '9';
}