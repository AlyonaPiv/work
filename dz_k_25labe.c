#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#define p 100

double rand_double(double dmin, double dmax);//вещественное число в заданном диапазоне 
double* rand_double1(double* b, int q, double dm);// q вещественных чисел в диапазоне от -dm до +dm 
void sort_bubble(double* b, int n); // сортировка пузырьком 
int put_elements(double* b, int q); // вывод массива

int main() {
	setlocale(LC_ALL, "RUS");

	int q;
	printf("¬¬едите кол-во элементов в массиве:  ");
	scanf_s("%d", &q);

	double b[p];

	double dm;
	printf("\n¬ведите конец диапазона дл€ заполнени€ массива:  ");
	scanf_s("%lf", &dm);
	printf("\n");

	printf("ћассив, заполненный случайными числами:  \n");
	rand_double1(b, q, dm);
	printf("\n\n");

	printf("ќтсортированый массив:  \n");
	sort_bubble(b, q);
	put_elements(b, q);
}

double rand_double(double dmin, double dmax) { //вещественное число в заданном диапазоне 
	double n = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	return n;
}

double* rand_double1(double* b, int q, double dm) {// q вещественных чисел в диапазоне от -dm до +dm 
	for (int i = 0; i < q; i++) {
		b[i] = rand_double(-dm, dm); // заполнение рандомными числами
		printf(" %.2lf ", b[i]); // вывод заполненного массива
	}
	return b;
}

void sort_bubble(double* b, int q) { // сортировка пузырьком по убыванию элементов
	for (int i = 0; i < q - 1; i++) {
		for (int j = i + 1; j < q; j++) {
			if ((int)b[i] < (int)b[j]) { // если цела€ часть первого элемента < целой части второго, то:
				double temp = b[i]; // запоминаем элемент
				b[i] = b[j]; // мен€ем элементы местами
				b[j] = temp; 
			}
		}
	}
	return b;
}

int put_elements(double* b, int q) { // вывод элементов массива
	for (int i = 0; i < q; i++) {
		printf(" %.2lf ", b[i]);
	}
	return 0;
}