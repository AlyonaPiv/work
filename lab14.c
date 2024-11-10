#include <stdio.h>
#include <locale.h>
#define N 30
#include <math.h>

// функция для заполнения масива
double* full_elements(double* ptr_array, int n) { 

	double sh = (4. - 2) / (n - 1); // шаг
	double x = 2.;

	for (int i = 0; i < n; i++) {
		ptr_array[i] = pow(x, 3) + 3 * pow(x, 2) - 3; // из 2 задания лаб.8
		x += sh;
	}
	return ptr_array;
}

// функция печати элементов массива
int put_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {

		printf("array[%2d] = %lf\n", i, ptr_array[i]);

	}

	return n;
}

// функция обработки элементов массива (обнуление отрицательных элементов)
double* calc_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {

		if (ptr_array[i] < 0) {
			ptr_array[i] = 0;
		}
	}
	return ptr_array;
}

// функция вычислания суммы элементов масива
double sum_elements(double* ptr_array, int begin, int end) {

	double sum = 0.0;

	for (int i = begin; i <= end; i++) {

		sum += ptr_array[i];

	}
	return sum;
}

// функция поиска элемента
int find_element(double* ptr_array, int n, double element) {

	int i = 0;
	while (ptr_array[i] != element && i < n)
	{
		i++;//перебор элементов
		if (ptr_array[i] == element) {
			return i;
		}
		else {
			return -1;
		}
	}
}
// функция определения индекса минимального элемента массива
int function(double* ptr_array, int n) {
	int min_index = 0;
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] < 0) {
			min_index = i;
		}
		return min_index;
	}
}
int main() {
	setlocale(LC_ALL, "RUS");

	// задание 1

	double array[N];
	int size;
	printf("Введите размер массива(меньше, чем %d)   ", N);
	scanf_s("%d", &size);
	
	full_elements(array, size);
	put_elements(array, size);

	// задание 2
	int begin, end;
	printf("\nВведите начальный индекс:   ");
	scanf_s("%d", &begin);

	printf("\nВведите конечный индекс:   ");
	scanf_s("%d", &end);

	printf("\nСумма элементов массива:  %lf", sum_elements(array, begin, end));

	double e;
	printf("\n\nВведите искомое значение:  ");
	scanf_s("%lf", &e);

	if (find_element(array, size, e)) {
		printf("\n\nНайдено значение под индексом %d", find_element(array, size, e));
	}

	// задание 3 - дз (вариант 15)

	int min_index = function(array, size);
	if (min_index == 0) {
		printf("\n\nВ масиве нет отрицательных элементов\n");
	}
}