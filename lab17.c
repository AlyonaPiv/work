#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define dm 150

void sort_bubble(double* arr, int n);
void sort_sheik(double* arr, int n);
void sort_select(double* arr, int n);
void sort_insert(double* arr, int n);
double print(double* arr, int n);
double* full_arr(double* arr, int n);
double* rand_double1(double* b, int q);

int main() {
	setlocale(LC_ALL, "RUS");
	// задание 1
	int size;
	printf("Введите размер масива для демонстрации сортировок:  ");
	scanf_s("%d", &size);

	double* A = (double*)malloc(size * sizeof(double));
	printf("\n\n");

	printf("Исходный массив: \n");
	full_arr(A, size);
	print(A, size);
	printf("\n\n");

	printf("Сортировка пузырьком: \n");
	sort_bubble(A, size);
	print(A, size);
	printf("\n\n");

	printf("Сортировка простым выбором: \n");
	sort_select(A, size);
	print(A, size);
	printf("\n\n");

	printf("Сортировка вставками: \n");
	sort_insert(A, size);
	print(A, size);
	printf("\n\n");

	printf("Сортировка шейкером: \n");
	sort_sheik(A, size);
	print(A, size);
	printf("\n\n");

	// задание 2

	int size_1;
	printf("Введите размер масива для сравнения времени сортировки (100):  \n");
	scanf_s("%d", &size_1);
	double* A_1 = (double*)malloc(size_1 * sizeof(double));
	int size_2;
	printf("Введите размер масива для сравнения времени сортировки (1000):  \n");
	scanf_s("%d", &size_2);
	double* A_2 = (double*)malloc(size_2 * sizeof(double));
	int size_3;
	printf("Введите размер масива для сравнения времени сортировки (10000):  \n");
	scanf_s("%d", &size_3);
	double* A_3 = (double*)malloc(size_3 * sizeof(double));

	// вставками
	rand_double1(A_1, size_1);
	int t_1 = clock();
	sort_insert(A_1, size_1);
	double time_1 = (clock() - t_1) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_2, size_2);
	int t_2 = clock();
	sort_insert(A_2, size_2);
	double time_2 = (clock() - t_2) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_3, size_3);
	int t_3 = clock();
	sort_insert(A_3, size_3);
	double time_3 = (clock() - t_3) * 1. / CLOCKS_PER_SEC;
	printf("\n\t\tСортировка вставками\n");
	printf("Время выполнения сортировки %d элементов - %lf\n", size_1, time_1);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_2, time_2);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_3, time_3);
	// пузырьком
	rand_double1(A_1, size_1);
	int t1 = clock();
	sort_bubble(A_1, size_1);
	double time1 = (clock() - t1) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_2, size_2);
	int t2 = clock();
	sort_bubble(A_2, size_2);
	double time2 = (clock() - t2) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_3, size_3);
	int t3 = clock();
	sort_bubble(A_2, size_3);
	double time3 = (clock() - t3) * 1. / CLOCKS_PER_SEC;
	printf("\n\t\tСортировка пузырьком:\n");
	printf("Время выполнения сортировки %d элементов - %lf\n", size_1, time1);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_2, time2);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_3, time3);
	// шейкерная
	rand_double1(A_1, size_1);
	t_1 = clock();
	sort_sheik(A_1, size_1);
	time_1 = (clock() - t_1) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_2, size_2);
	t_2 = clock();
	sort_sheik(A_2, size_2);
	time_2 = (clock() - t_2) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_3, size_3);
	t_3 = clock();
	sort_sheik(A_3, size_3);
	time_3 = (clock() - t_3) * 1. / CLOCKS_PER_SEC;
	printf("\n\t\tСортировка шейкером:\n");
	printf("Время выполнения сортировки %d элементов - %lf\n", size_1, time_1);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_2, time_2);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_3, time_3);
	// простым выбором
	rand_double1(A_1, size_1);
	t1 = clock();
	sort_select(A_1, size_1);
	time1 = (clock() - t1) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_2, size_2);
	t2 = clock();
	sort_select(A_2, size_2);
	time2 = (clock() - t2) * 1. / CLOCKS_PER_SEC;

	rand_double1(A_3, size_3);
	t3 = clock();
	sort_select(A_3, size_3);
	time3 = (clock() - t3) * 1. / CLOCKS_PER_SEC;
	printf("\n\t\tСортировка простым выбором:\n");
	printf("Время выполнения сортировки %d элементов - %lf\n", size_1, time1);
	printf("Время выполнения сортировки %d элементов - %lf\n", size_2, time2);
	printf("Время выполнения сортировки %d элементов - %lf\n\n", size_3, time3);
	// задание 3

	free(A);
	free(A_1);
	free(A_2);
	free(A_3);
	
}

void sort_bubble(double* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				double t = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	return;
}

void sort_sheik(double* arr, int n) {
	int left = 2, right = n;
	for (int i = left; i < right; i++) {
		if (arr[i] < arr[i - 1]) {
			double t = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = t;
		}
		right = right - 1;
		for (int j = right; j < left; j++) {
			if (arr[j]<arr[j - 1]) {
				double x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
			}
			left = left + 1;
		}
	}
	return;
}

void sort_select(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		int imax = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[imax] < arr[j]) {
				imax = j;
			}
		}
		double t = arr[i];
		arr[i] = arr[imax];
		arr[imax] = t;
	}
	return;
}

void sort_insert(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		while (arr[j - 1] < arr[j] && j != 0) {
			double t = arr[j - 1];
			arr[i] = arr[j - 1];
			arr[j - 1] = t;
		}
	}
	return;
}

double print(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %.2lf ", arr[i]);
	}
	return 0;
}

double* full_arr(double* arr, int n) {
	double sh = (4. - 2) / (n - 1);
	double x = 2.;
	for (int i = 0; i < n; i++) {
		arr[i] = pow(x, 3) + 3 * pow(x, 2) + 3;
		x += sh;
	}
	return arr;
}

double* rand_double1(double* b, int q) {// q вещественных чисел в диапазоне от -dm до +dm 
	for (int i = 0; i < q; i++) {
		b[i] = dm + 1.f * (dm - -(dm)) * rand() / RAND_MAX; // заполнение рандомными числами
	}
	return b;
}
