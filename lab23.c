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

void initlist(List*);   /* инициализация списка пустым содержимым */
void insertfront(List*, int val);   /* вставка в список перед узлом со значением поля number=val */
void insertback(List*, int val);   /* вставка в список перед узлом со значением поля number=val */
void insertfront_str(List*, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertback_str(List*, char* str); /* вставка в список перед узлом со значением str в поле name */
bool isempty(List*); /* проверяет, является ли список пустым*/
int length(List); /* определение длины списка */
void destroyItem(List*, List node); /* удаление заданного узла node из списка */
struct listitem* getitem_int(List, int n); /* нахождение узла со значением n в поле number*/
struct listitem* getitem_str(List, char* str); /* нахождение узла со значением str в поле name*/
void printList(List list); /* вывод на экран все значения элементов списка */
void printNumberedList(List list); /* */
void insertInMiddle(List* list, char* itemName); /* добавляет новый элемент в середину односвязного списка */

#endif /* _LIST_H */

int main() {
    setlocale(LC_ALL, "RUS");

    List list;
    initlist(&list);

    // задание 2.1 "простая" программа, вариант 15 - 10 = 5

    /*Создать линейный однонаправленный список из 7 целых чисел.
    Вставить в список число 10 после каждого элемента с отрицательным значением.*/

    int num_elements = 7;
    int val;
    printf("Введите %d целых чисел:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Число %d: ", i + 1);
        scanf_s("%d", &val);
        insertback(&list, val);
    }
    printf("Список до преобразования: ");
    printList(list);

    // Вставляем 10 после каждого отрицательного элемента
    List current = list;
    while (current != NULL) {
        if (current->number < 0) {

            List new_node = (List)malloc(sizeof(struct listitem));
            if (new_node == NULL) {
                fprintf(stderr, "Ошибка выделения памяти\n");
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

    printf("Список после преобразования: ");
    printList(list);

    // Освобождаем память, выделенную для списка.
    current = list;
    while (current != NULL) {
        List temp = current;
        current = current->next;
        free(temp);
    }

    initlist(&list);

    // задание 2.2 "средняя" программа, вариант 15 - 8 = 7

    /* 7. Чек - лист покупок
        -Создать список из 10 различных товаров.
        - Добавлять элементы в середину списка.
        - Выводить элементы в виде пронумерованного списка.
        - Удалять элементы с начала списка.*/

    char* tovar[] = { "Молоко", "Хлеб", "Яйца", "Сыр", "Масло", "Яблоки", "Бананы", "Сок", "Кофе", "Чай" };
    for (int i = 0; i < 10; i++) {
        insertback_str(&list, tovar[i]);
    }
    printf("\n\nИсходный список:\n");
    printNumberedList(list);

    // 2. Добавляем элементы в середину
    insertInMiddle(&list, "Печенье");

    printf("\nСписок после добавления в середину:\n");
    printNumberedList(list);

    // 3. Удаляем элементы с начала списка

    if (!isempty(&list)) {
        destroyItem(&list, list);
    }

    printf("\nСписок после удаления с начала:\n");
    printNumberedList(list);

    // Освобождаем память
    current = list;
    while (current != NULL) {
        List temp = current;
        current = current->next;
        free(temp);
    }
}

/* инициализация списка пустым содержимым */
void initlist(List* list) { 
    *list = NULL;
}

/* вставка нового узла в начало связного списка */
void insertfront(List* list, int val) { 
    List new_node = (List)malloc(sizeof(struct listitem)); // выделение памяти для нового узла
    if (new_node == NULL) {
        return;
    }
    new_node->number = val; // инициализация нового узла
    new_node->next = *list; // указатель на первый узел списка
    *list = new_node; // обновление указателя на начало списка
}

/* вставка в список перед узлом со значением поля number=val */
void insertback(List* list, int val) { 
    List new_node = (List)malloc(sizeof(struct listitem)); // выделение памяти для нового узла
    if (new_node == NULL) {
        return;
    }
    new_node->number = val; // инициализация нового узла
    new_node->next = NULL; // указатель на последний узел в списке

    if (*list == NULL) {  // Если список пуст, то новый узел становится первым
        *list = new_node; // и единственным элементом списка.
    }
    else {
        List current = *list;  // временный указатель на начало списка
        while (current->next != NULL) { // пока не дойдет до последнего узла 
            current = current->next; //перемещается на следующий узел
        }
        current->next = new_node; // обновление указателя на конец списка
    }
}

/* вставка в список перед узлом со значением str в поле name */
void insertfront_str(List* list, char* str) { 
    List new_node = (List)malloc(sizeof(struct listitem)); // выделение памяти для нового узла
    if (new_node == NULL) {
        return;
    }
    strncpy(new_node->name, str, sizeof(new_node->name) - 1); // копирует строку
    new_node->name[sizeof(new_node->name) - 1] = '\0'; // строка всегда будет нуль-терминированной
    new_node->next = *list; // указатель на "старый" первый элемент
    *list = new_node; // указатель на начало нового списка
}

/* вставка в список перед узлом со значением str в поле name */
void insertback_str(List* list, char* str) {
    List new_node = (List)malloc(sizeof(struct listitem)); // выделение памяти для нового узла
    if (new_node == NULL) {
        return;
    }
    strncpy(new_node->name, str, sizeof(new_node->name) - 1); // копирует строку
    new_node->name[sizeof(new_node->name) - 1] = '\0'; // строка всегда будет нуль-терминированной
    new_node->next = NULL; // новый узел - последний 

    if (*list == NULL) { // если список пуст, то новый узел становится первым
        *list = new_node;// и единственным элементом списка
    }
    else {
        List current = *list; // временый указатель на начало
        while (current->next != NULL) { // пока не дойдет до последнего узла 
            current = current->next; //перемещается на следующий узел
        }
        current->next = new_node; // обновление указателя на конец списка
    }
}

/* проверяет, является ли список пустым*/
bool isempty(List* list) { 
    return *list == NULL;
}

/* определение длины списка */
int length(List list) { 
    int count = 0; // счетчик длины списка
    List current = list;
    while (current != NULL) { // пока указаель не дойдет до конца списка
        count++;
        current = current->next; // перемещение на след. элемент
    }
    return count;
}

/* удаление заданного узла node из списка */
void destroyItem(List* list, List node) { 
    if (*list == NULL || node == NULL) { // проверка на пустой список
        return;
    }

    if (*list == node) { // удаление первого узла
        *list = node->next;
        free(node);
        return;
    }

    List current = *list; // указатель на начало списка
    while (current != NULL && current->next != node) { // пока не дошли до конца списка и пока не найден нужный узел
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        return;
    }

    current->next = node->next; // перенаправляем указатель с удаляемого на следующий
    free(node); // освобождаем память удаляемого узла
}

/* нахождение узла со значением n в поле number*/
struct listitem* getitem_int(List list, int n) { 
    List current = list;
    while (current != NULL) { // пока указатель не равен концу списка
        if (current->number == n) {
            return current; // если поле узла равно заданному значению - вывод нужного узла
        }
        current = current->next;
    }
    return NULL;
}

/* нахождение узла со значением str в поле name*/
struct listitem* getitem_str(List list, char* str) { 
    List current = list;
    while (current != NULL) {
        if (strcmp(current->name, str) == 0) { // равна ли строка текушего узла заданной строке
            return current; //вывод узла
        }
        current = current->next;
    }
    return NULL;
}

/* вывод на экран все значения элементов списка */
void printList(List list) { 
    List current = list;
    while (current != NULL) {
        printf("%d ", current->number); // выводит на экран значение текущего узла
        current = current->next;
    }
    printf("\n");
}

/* выводит на экран элементы списка (строки) в пронумерованном виде*/
void printNumberedList(List list) { 
    List current = list;
    int count = 1; // для нумерации списка
    while (current != NULL) {
        printf("%d. %s\n", count++, current->name); // выводит номер текущего элемента и строку в поле name текущего узла
        current = current->next;
    }
}

/* вставляет новый элемент (узел) в середину односвязного списка.*/
void insertInMiddle(List* list, char* itemName) { 
    int len = length(*list); // определение текущей длины списка
    if (len == 0) {
        insertback_str(list, itemName); // если список пуст, то элемент вставляется в конец(начало) списка
    }
    else {
        int middle = len / 2; // находим середину списка
        List new_node = (List)malloc(sizeof(struct listitem)); // выделяем память для нового узла
        if (new_node == NULL) {
            fprintf(stderr, "Ошибка выделения памяти");
            exit(1);
        }

        strncpy(new_node->name, itemName, sizeof(new_node->name) - 1); // Копируется строка itemName в поле name нового узла.
        new_node->name[sizeof(new_node->name) - 1] = '\0'; // строка завершается нуль-терминатором

        if (middle == 0) { // если середины нет, то новый элемент вставляется в начало списка
            insertfront_str(list, itemName);
            return;
        }

        List current = *list;
        for (int i = 1; i < middle; i++) { 
            current = current->next;
        }

        new_node->next = current->next; // указатель на новый узел = указателю на узел перед серединой
        current->next = new_node; // вставляет новый узел в список
    }
}