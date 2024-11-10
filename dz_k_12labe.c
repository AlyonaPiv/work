#include <stdio.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "RUS");

    int I;
    int *p1 = &I; // получение адреса 
    int* p2 = p1 + 1; // указатель на следующее значение
    
    int size = (char*)p2 - (char*)p1; 

    printf("Размер int равен %d байтам", size);
}