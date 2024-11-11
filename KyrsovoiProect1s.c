#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define N 10

//функция ввода многомерного массива
int vvod_massiva(int a[10][10], int n, int m) {
	
	if (!(n < 10) || !(m < 10)) return;
	// Ввод элементов массива
	for (int i = 0; i < n; i++) // цикл по строкам
	{
		for (int j = 0; j < m; j++) {// цикл по столбцам
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &a[i][j]);
		}
	}
	// Вывод элементов массива
	for (int i = 0; i < n; i++) // цикл по строкам
	{
		for (int j = 0; j < m; j++) // цикл по столбцам

		{
			printf(" %d ", a[i][j]); //
		}
		printf("\n");
	}
}

// функция умножения элементов массива по принципу матриц
int product_matric(int C[10][10], int A[10][10], int B[10][10], int s1, int s2, int k1, int k2) {
	if (!(s1 < 10) || !(k1 < 10)) return;
	printf("Первая матрица: \n\n");
	// Ввод элементов массива
	for (int i = 0; i < s1; i++) // цикл по строкам
	{
		for (int j = 0; j < k1; j++) {// цикл по столбцам
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &A[i][j]);
		}
	}
	printf("\n");
	// Вывод элементов массива
	for (int i = 0; i < s1; i++) // цикл по строкам
	{
		for (int j = 0; j < k1; j++) // цикл по столбцам
		{
			printf(" %d ", A[i][j]); //
		}
		printf("\n");
	}
	printf("\nВторая матрица: \n\n");
	if (!(s2 < 10) || !(k2 < 10)) return;
	// Ввод элементов массива
	for (int i = 0; i < s2; i++) // цикл по строкам
	{
		for (int j = 0; j < k2; j++) {// цикл по столбцам
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &B[i][j]);
		}
	}
	printf("\n");
	// Вывод элементов массива
	for (int i = 0; i < s2; i++) // цикл по строкам
	{
		for (int j = 0; j < k2; j++) // цикл по столбцам
		{
			printf(" %d ", B[i][j]); //
		}
		printf("\n");
	}
	printf("\nРезультат: \n\n");
	// Произведение двух матриц
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < k1; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	// вывод результата
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k2; j++) {
			printf(" %d ", C[i][j]);
		}
		printf("\n");
	}
}

// функция сортировки массива методом пузырька
int sort_massiv() {
	
}

int main() {
	setlocale(LC_ALL, "RUS");
	int a[10][10];

	int g;
	printf("Введите размерность массива:  ");
	scanf_s("%d", &g);
	// выделение памяти под массивы
	int *A, *B , *C;
	A = (int*)malloc(g * sizeof(int));
	B = (int*)malloc(g * sizeof(int));
	C = (int*)malloc(g * sizeof(int));
	
	int n, m;

	int s1, s2, k1, k2;
	
	while (1)
	{
		char o;

		int e;
		printf("Введите номер операции: \n 1 - ввод многомерного массива; \n 2 - умножение массива А на массив B по правилам матриц; \n 3 - выполнить сортировку массива.\n");
		scanf_s("%d", &e);

		switch (e) {
		case 1:
			printf("Введите количество строк: ");
			scanf_s("%d", &n);
			printf("Введите количество столбцов: ");
			scanf_s("%d", &m);
			vvod_massiva(a,n, m);
			break;
		case 2:
			puts("\tВведите размеры матриц, для получения новой путем их перемножения\n");
			printf("\nВведите количество строк первой матрицы:  ");
			scanf_s("%d", &s1);
			printf("\nВведите количество столбцов первой матрицы:  ");
			scanf_s("%d", &k1);

			printf("\n\nВведите количество строк второй матрицы:  ");
			scanf_s("%d", &s2);
			printf("\nВведите количество столбцов второй матрицы:  ");
			scanf_s("%d", &k2);

			printf("\n\nРазмер первой матрицы %d*%d, размер второй матрицы %d*%d\n", s1, k1, s2, k2);

			if (k1 != s2) {
				printf("Количество столбцов первой матрицы не совпадает с количеством строк второй матрицы: \n\tУМНОЖЕНИЕ НЕВОЗМОЖНО");
			}
			else {
				printf("\nУмножение возможно! \n\n");
			}
			product_matric(C, A, B, s1, s2, k1, k2);
			break;
		case 3:

		default:
			printf("Произошли технические шоколадки, повторите снова\n");
			break;
		}


		printf("Продолжить ? (Да - y, нет - n)  ");
		if ((o = getchar()) == 'n')
			break;
	}
}