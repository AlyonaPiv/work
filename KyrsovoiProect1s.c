#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int g;
	printf("\tВведите размерность массива:  ");
	scanf_s("%d", &g);

	while (1){
	
		char o;

		int s1, s2, k1, k2;

		printf("\n\tВведите количество строк первой матрицы:  ");
		scanf_s("%d", &s1);
		printf("\n\tВведите количество столбцов первой матрицы:  ");
		scanf_s("%d", &k1);
		puts("\n\t\tВведите матрицу:   \n");

		if (!(s1 < g) || !(k1 < g)) return; // проверка размерности маатрицы

		// выделение памяти под первый массив
		int** A = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			A[i] = (int*)malloc(k1 * sizeof(int));
		}
		if (A == NULL) {
			puts("Технические шоколадки");
			return -1;
		}
		// Ввод элементов ПЕРВОГО массива
		for (int i = 0; i < s1; i++) { // цикл по строкам

			for (int j = 0; j < k1; j++) {// цикл по столбцам
				printf(" a[%d][%d] = ", i, j);
				scanf_s("\n%d", &A[i][j]);
			}
		}
		printf("\n");

		printf("\n\tВведите количество строк второй матрицы:  ");
		scanf_s("%d", &s2);
		printf("\n\tВведите количество столбцов второй матрицы:  ");
		scanf_s("%d", &k2);
		puts("\n\tВведите матрицу:   \n");

		if (!(s2 < g) || !(k2 < g)) return; // проверка размерности маатрицы

		// выделение памяти под второй массив
		int** B = (int**)malloc(s2 * sizeof(int*));
		for (int i = 0; i < s2; i++) {
			B[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (B == NULL) {
			puts("Технические шоколадки");
			return -1;
		}
		// Ввод элементов ВТОРОГО массива
		for (int i = 0; i < s2; i++) { // цикл по строкам

			for (int j = 0; j < k2; j++) {// цикл по столбцам
				printf(" a[%d][%d] = ", i, j);
				scanf_s("\n%d", &B[i][j]);
			}
		}
		printf("\n");

		printf("\n\t\tПервая матрица: \n\n");
		// Вывод элементов ПЕРВОГО массива
		for (int i = 0; i < s1; i++) { // цикл по строкам

			for (int j = 0; j < k1; j++) {// цикл по столбцам

				printf(" %d ", A[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\t\tВторая матрица: \n\n");
		// Вывод элементов ВТОРОГО массива
		for (int i = 0; i < s2; i++) { // цикл по строкам

			for (int j = 0; j < k2; j++) { // цикл по столбцам

				printf(" %d ", B[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\n\tРазмер первой матрицы %d*%d, размер второй матрицы %d*%d\n", s1, k1, s2, k2);

		if (k1 != s2) {
			printf("\n\tКоличество столбцов первой матрицы не совпадает с количеством строк второй матрицы: \n\tУМНОЖЕНИЕ НЕВОЗМОЖНО\n");
			// Освобождение памяти, если матрицы нельзя перемножить
			for (int i = 0; i < s1; i++) {
				free(A[i]);
			}
			free(A);
			for (int i = 0; i < s2; i++) {
				free(B[i]);
			}
			free(B);
			return 1;
		}
		else {
			printf("\n\t\tУмножение возможно! \n\n");
		}
		printf("\n\t\tПервая матрица: \n\n");
		// Вывод элементов ПЕРВОГО массива
		for (int i = 0; i < s1; i++) { // цикл по строкам

			for (int j = 0; j < k1; j++) { // цикл по столбцам

				printf(" %d ", A[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\t\tВторая матрица: \n\n");
		// Вывод элементов ВТОРОГО массива
		for (int i = 0; i < s2; i++) { // цикл по строкам

			for (int j = 0; j < k2; j++) { // цикл по столбцам

				printf(" %d ", B[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\t\tРезультат: \n\n");
		// Произведение двух матриц
		int** C = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			C[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (C == NULL) {
			puts("Технические шоколадки");
			return -1;
		}
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
		// Освобождение памяти 
		for (int i = 0; i < s1; i++) {
			free(A[i]);
		}
		free(A);
		for (int i = 0; i < s2; i++) {
			free(B[i]);
		}
		free(B);
		for (int i = 0; i < s1; i++) {
			free(C[i]);
		}
		free(C);

		printf("Продолжить ? (Да - y, нет - n)  ");
		o = getchar();

		if (o == 'n') {
			break;
		}
	}
	return 0;
}