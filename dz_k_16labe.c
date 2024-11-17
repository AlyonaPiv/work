#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

double* dzA(double* A, int size_a) { // заполнение случайными числами из диапазона массива 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size_a; i++) {
		A[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return A;
}
int printf_element1(double* A, int size_a) { //вывод масива 

	for (int i = 0; i < size_a; i++) {
		printf("A[%2d] = %.lf\n", i, A[i]);
	}
	return 0;
}

double* dzB(double* B, int size_b) { // заполнение случайными числами из диапазона массива 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size_b; i++) {
		B[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return B;
}
int printf_element2(double* B, int size_b) { //вывод масива

	for (int i = 0; i < size_b; i++) {
		printf("B[%2d] = %.lf\n", i, B[i]);
	}
	return 0;
}

double* dzC(double* C, int size_c) { // заполнение случайными числами из диапазона массива 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size_c; i++) {
		C[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return C;
}
int printf_element3(double* C, int size_c) { //вывод масива

	for (int i = 0; i < size_c; i++) {
		printf("C[%2d] = %.lf\n", i, C[i]);
	}
	return 0;
}
// заполнение массива числами из других массивов кроме каждого четвертого числа
double* dz(double* A, double* B, double* C, double* D, int size_a, int size_b, int size_c) {
	int t = 0;//счетчик каждого 4-го символа
	int index = 0;
	
	for (int i = 0; i < size_a; i++) { // сначала добавляет числа из первого массива 
		t++;
		if (t % 4 != 0) {
			D[index] = A[i];
			index++;
		}
	}
	for (int i = 0; i < size_b; i++) { // затем из второго
		t++;
		if (t % 4 != 0) {
			D[index] = B[i];
			index++;
		}
	}
	for (int i = 0; i < size_c; i++) { // затем из третьего
		t++;
		if (t % 4 != 0) {
			D[index] = C[i];
			index++;
		}
	}
	return D;
}
int printf_element4(double* D, int size_d) { // вывод массива

	for (int i = 0; i < size_d; i++) {
		printf("D[%2d] = %.lf\n", i, D[i]);
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "RUS");

	// ДЗ вариант 15

	double* A, * B, * C, * D;
	int size_a, size_b, size_c, size_d;

	printf("\nВведите размер массива А:   ");
	scanf_s("%d", &size_a);
	printf("\nВведите размер массива B:   ");
	scanf_s("%d", &size_b);
	printf("\nВведите размер массива C:   ");
	scanf_s("%d", &size_c);

	size_d = (size_a + size_b + size_c) - ((size_a + size_b + size_c)/4);

	// выделение памяти
	A = (double*)malloc(size_a * sizeof(double));
	if (A == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}
	B = (double*)malloc(size_b * sizeof(double));
	if (B == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}
	C = (double*)malloc(size_c * sizeof(double));
	if (C == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}
	D = (double*)malloc(size_d * sizeof(double));
	if (D == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}

	dzA(A, size_a);
	printf("\nмасив A:  \n");
	printf_element1(A, size_a);
	dzB(B, size_b);
	printf("\nмасив B:  \n");
	printf_element2(B, size_b);
	dzC(C, size_c);
	printf("\nмасив C:  \n");
	printf_element3(C, size_c);
	dz(A, B, C, D, size_a, size_b, size_c);
	printf("\nмасив D:  \n");
	printf_element4(D, size_d);

	// освобождение памяти
	free(A);
	free(B);
	free(C);
	free(D);
}