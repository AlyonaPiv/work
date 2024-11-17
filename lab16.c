#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
// задание 1
double* full_elements(double* ptr_array, int size);// заполнения массива значениями собственной функции
double* calc_elements(double* ptr_array, int size);// обработка элементов массива (обнуление отрицательных элементов)
int put_elements(double* ptr_array, int size);// вывод массива
// задание 2
double* full_random(double* ptr_array2, int size1);// заполнение случайными значениями
int put_element(double* ptr_array2, int size1);// вывод массива
int delete_k(double* ptr_array2, int size1);// удаление заданного эл-та, вариант 7 (15-8)
// задание 3
double* insert(double* ptr_arr, int size2);// вставляет -999 до и после мин.элемента

// заполнения массива значениями собственной функции
double* full_elements(double* ptr_array, int size) {

	double sh = (4. - 2) / (size - 1);
	double x = 2.;

	for (int i = 0; i < size; i++) {

		ptr_array[i] = pow(x, 3) + 3 * pow(x, 2) - 3; // из 2-го задания лаб.8
		x += sh;
	}
	return ptr_array;
}

// обработка элементов массива (обнуление отрицательных элементов)
double* calc_elements(double* ptr_array, int size) {

	for (int i = 0; i < size; i++) {

		if (ptr_array[i] < 0) {
			ptr_array[i] = 0;
		}
	}
	return ptr_array;
}

// вывод массива
int put_elements(double* ptr_array, int size) {

	for (int i = 0; i < size; i++) {
		printf("array[%2d] = %.lf\n", i, ptr_array[i]);
	}
	return 0;
}

// задание 2
// заполнение случайными значениями
double* full_random(double* ptr_array2, int size1) {

	int XMIN = -10, XMAX = 10;

	for (int i = 0; i < size1; i++) {
		ptr_array2[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return ptr_array2;
}

// вывод массива
int put_element(double* ptr_array2, int size1) {

	for (int i = 0; i < size1; i++) {
		printf("array[%2d] = %.lf\n", i, ptr_array2[i]);
	}
	return 0;
}

// удаление заданного эл-та, вариант 7 (15-8)
int delete_k(double* ptr_array2, int size1){
	/* ptr_array2 - адрес массива
	   size1 - число элементов*/
	int minI = 0, maxI = 0;
	for (int i = 1; i < size1; i++) {
		if (ptr_array2[i] < ptr_array2[minI]) { //поиск ИНДЕКСА минимального элемента
			minI = i;
		}
		if (ptr_array2[i] > ptr_array2[maxI]) { //поиск ИНДЕКСА максимального элемента
			maxI = i;
		}
	}
	for (int i = maxI; i < (size1 - 1); i++) { // удаление максимального элемента
		ptr_array2[i] = ptr_array2[i + 1];
	}
	size1--;
	for (int i = minI; i < (size1 - 1); i++) { // удаление минимального элемента
		ptr_array2[i] = ptr_array2[i + 1];
	}
	size1--;
	return size1;
}

// задание 3
// вставляет -999 до и после мин.элемента
double* insert(double* ptr_arr, int size2) {
	int XMIN = -50, XMAX = 50;
	for (int i = 0; i < size2; i++) {
		ptr_arr[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	
	int minI = 0;
	for (int i = 0; i < size2; i++) {
		if (ptr_arr[i] < ptr_arr[minI]) { //поиск ИНДЕКСА минимального элемента
			minI = i;
		}
	}
	int j = 0;
	for (int i = 0; i < size2; i++) {
		if (ptr_arr[i] == ptr_arr[minI]) {
			ptr_arr[i - 1] = -999;
			ptr_arr[i + 1] = -999;
		}
	}
	return ptr_arr;
}
int put_element1(double* ptr_arr, int size2) {
	for (int i = 0; i < size2; i++) {
		printf("array[%2d] = %.lf\n", i, ptr_arr[i]);
	}
	return 0;
}
main() {
	setlocale(LC_ALL, "RUS");
	double* ptr_array;
	int size;
	printf("Введите размерность массива:   ");
	scanf_s("%d", &size);

	// выделение памяти 
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}
	// задание 1
	full_elements(ptr_array, size);
	calc_elements(ptr_array, size);
	printf("Заполнение элементами собственной функции:  \n");
	put_elements(ptr_array, size);
	printf("\n");
	free(ptr_array);

	// задание 2
	double* ptr_array2;
	int size1, size2, MAX = 1, MIN = -1;
	printf("Введите размерность массива:   ");
	scanf_s("%d", &size1);

	// выделение памяти
	ptr_array2 = (double*)malloc(size1 * sizeof(double));
	if (ptr_array2 == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}

	full_random(ptr_array2, size1);
	printf("Заполнение рандомными числами:  \n");
	put_element(ptr_array2, size1);
	printf("\n");


	delete_k(ptr_array2, size1);
	printf("Удаление минимального и максимального элемента:  \n");
	put_element(ptr_array2, size1);
	printf("\n");
	free(ptr_array2);

	printf("Введите размерность массива:   ");
	scanf_s("%d", &size2);
	double* ptr_arr;
	ptr_arr = (double*)malloc(size2 * sizeof(double));
	if (ptr_arr == NULL) { // проверка выделения памяти
		puts("Технические шоколадки");
		return -1;
	}

	insert(ptr_arr, size2);
	printf("\nВставка -999 до и после минимального элемента в массиве\n");
	put_element1(ptr_arr, size2);
	free(ptr_arr);

}
// удаление элемента
/* Пример:
* int delete_k (double* ptr_arr, int size, int k) {
	//ptr_arr - адрес массива
    //size - число элементов
	//k - индекс удаляемого элемента

  int n = size - 1;

  for (int i = k; i < (size - 1); i++){
	ptr_arr[i] = ptr_arr[i + 1];
  }
  return n;//возвращает число элементов массива
}
*/

// вставка -999 
/* Пример:
	int* insert(int* ptr_arr,int* size, int index, int num){
		//ptr_arr - адрес массива
		//size - число элементов
		//k - индекс добовляемого элемента
		//num - вставляемое значение
		int size_n = (*size)+1;
		if (ptr_arr == NULL) return NULL;
		int* ptr_arr_n = (int*)realloc(ptr_arr, size_n * sizeof(int));
		if (ptr_arr_n == NULL) return ptr_arr;
		ptr_arr = ptr_arr_n;
		for (int i = size_n - 1; i > index; i--){
			ptr_arr[i] = ptr_arr[i - 1];
		}
		ptr_arr[index] = num;
		*size = size_n;
		return ptr_arr;
	}
*/