#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int* zap_sobstv(int** A, int s1, int k1);
int* random(int** A, int d, int s1, int k1);
int* proizvedenie(int** C, int** A, int** B, int s1, int k1, int k2);
int* print(int** A, int s1, int k1);

int main() {
	setlocale(LC_ALL, "RUS");

	puts("\t****************************************************************************************");
	puts("\t*                                 Курсовой проект                                      *");
	puts("\t*                                                                                      *");
	puts("\t*                        Подготовил студент группы: бИД-242                            *");
	puts("\t*                           Пивоварова Алёна Анатольевна                               *");
	puts("\t****************************************************************************************");

	while (1) {

		char o;

		int g;
		printf("\tВведите размерность массива:  ");
		scanf_s("%d", &g);

		int s1, s2, k1, k2;

		printf("\n\tВведите количество строк первой матрицы:  ");
		scanf_s("%d", &s1);
		printf("\n\tВведите количество столбцов первой матрицы:  ");
		scanf_s("%d", &k1);

		if (!(s1 < g) || !(k1 < g)) return; // проверка размерности матрицы

		// выделение памяти под первый массив
		int** A = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			A[i] = (int*)malloc(k1 * sizeof(int));
		}
		if (A == NULL) {
			puts("Технические шоколадки");
			return -1;
		}

		printf("\n\tВведите количество строк второй матрицы:  ");
		scanf_s("%d", &s2);
		printf("\n\tВведите количество столбцов второй матрицы:  ");
		scanf_s("%d", &k2);

		if (!(s2 < g) || !(k2 < g)) return; // проверка размерности матрицы

		// выделение памяти под второй массив
		int** B = (int**)malloc(s2 * sizeof(int*));
		for (int i = 0; i < s2; i++) {
			B[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (B == NULL) {
			puts("Технические шоколадки");
			return -1;
		}

		int spsb, end, d;
		printf("\n\tВыберете способ инициализации массивов: \n\t\t 1 - собственноручно; \n\t\t 2 - с помощью генерации случайных чисел\n\t\t\t");
		scanf_s("%d", &spsb);

		printf("\n\tВыберете способ вывода результата: \n\t\t 1 - только новый, получившийся в результате умножения массив; \n\t\t 2 - все три массива;\n\t\t 3 - все три массива с комментариями\n\t\t\t");
		scanf_s("%d", &end);

		// проверка выполнения условия умножения матриц 
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

		switch (spsb) { // инициализация по выбору пользователя
		case(1):
			puts("\n\t\tВведите первую матрицу:   \n");
			zap_sobstv(A, s1, k1);
			printf("\n");

			puts("\n\tВведите вторую матрицу:   \n");
			zap_sobstv(B, s2, k2);
			printf("\n");
			break;

		case (2):
			puts("\n\tВведите максимальное значение диапазона > 1:  ");
			scanf_s("%d", &d);

			random(A, d, s1, k1);
			random(B, d, s2, k2);
			break;
		}

		// выделение памяти под результирующий массив
		int** C = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			C[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (C == NULL) {
			puts("Технические шоколадки");
			return -1;
		}

		// Произведение двух матриц
		proizvedenie(C, A, B, s1, k1, k2);

		switch (end) { // вывод результатов по выбору пользователя
		case(1):
			printf("\n\t\tРезультат: \n\n");
			// вывод результата
			print(C, s1, k2);
			
			break;
		case(2):
			printf("\n\t\tПервая матрица: \n\n");
			// Вывод элементов ПЕРВОГО массива
			print(A, s1, k1);
			printf("\n");

			printf("\n\t\tВторая матрица: \n\n");
			// Вывод элементов ВТОРОГО массива
			print(B, s2, k2);
			
			printf("\n");

			printf("\n\t\tРезультат: \n\n");
			// вывод результата
			print(C, s1, k2);
			
			break;
		case (3):
			// пояснения - условие, при котором матрицы могут быть умножены друг на друга
			printf("\tКоличество столбцов первой матрицы совпадает с количеством строк второй матрицы, поэтому умножение возможно.\n\n");

			printf("\n\t\tПервая матрица: \n\n");
			// Вывод элементов ПЕРВОГО массива
			print(A, s1, k1);

			printf("\n");
			printf("\n\t\tВторая матрица: \n\n");
			// Вывод элементов ВТОРОГО массива
			print(B, s2, k2);

			printf("\n");
			// пояснения - как происходит умножение
			printf("\tУмножение матриц осуществляется путем умножения строки на столбец. \n");
			printf("Находятся произведения первого элемента строки и первого элемента столбца, второго элемента строки и второго элемента столбца и т.д. \n");
			printf("Затем полученные произведения суммируются.\n");

			printf("\n\t\tРезультат: \n\n");
			// вывод результата
			print(C, s1, k2);

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

		printf("\n");

		printf("Продолжить ? (Да - y, нет - n)  ");
		o = getchar();

		if (o == 'n') {
			break;
		}
	}
}

int* zap_sobstv(int** A, int s1, int k1) {
	for (int i = 0; i < s1; i++) { // цикл по строкам

		for (int j = 0; j < k1; j++) {// цикл по столбцам
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &A[i][j]);
		}
	}
	return *A;
}

int* random(int** A, int d, int s1, int k1) {
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k1; j++) {
			A[i][j] = -d + rand() % (d - (-d));
		}
	}
	return *A;
}

int* proizvedenie(int** C, int** A, int** B, int s1,int k1, int k2) {
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < k1; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return *C;
}

int* print(int** A, int s1, int k1) {
	for (int i = 0; i < s1; i++) { // цикл по строкам
		for (int j = 0; j < k1; j++) { // цикл по столбцам

			printf(" %3d ", A[i][j]); //
		}
		printf("\n");
	}
	return 0;
}