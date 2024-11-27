#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

double* dz_random(double* A, int size);
int printf_element(double* A, int size);
double* dz(double* A, double* B, double* C, double* D, int size_a, int size_b, int size_c,int size_d);


double* dz_random(double* A, int size) { // заполнение случайными числами из диапазона массива 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size; i++) {
		A[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return A;
}
int printf_element(double* A, int size) { //вывод масива 

	for (int i = 0; i < size; i++) {
		printf("A[%2d] = %.lf\n", i, A[i]);
	}
	return 0;
}

// заполнение массива числами из других массивов кроме каждого четвертого числа
double* dz(double* A, double* B, double* C, double* D, int size_a, int size_b, int size_c, int size_d) {
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

	dz_random(A, size_a);
	printf("\nмасив A:  \n");
	printf_element(A, size_a);
	dz_random(B, size_b);
	printf("\nмасив B:  \n");
	printf_element(B, size_b);
	dz_random(C, size_c);
	printf("\nмасив C:  \n");
	printf_element(C, size_c);
	dz(A, B, C, D, size_a, size_b, size_c,size_d);
	printf("\nмасив D:  \n");
	printf_element(D, size_d);

	// освобождение памяти
	free(A);
	free(B);
	free(C);
	free(D);
}