#include <stdio.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "RUS");

    int I;
    int *p1 = &I; // ��������� ������ 
    int* p2 = p1 + 1; // ��������� �� ��������� ��������
    
    int size = (char*)p2 - (char*)p1; 

    printf("������ int ����� %d ������", size);
}