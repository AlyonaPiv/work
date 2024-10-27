#include <stdio.h>
#include <locale.h>
#include <math.h>

 // функции для первого задания

double fa(double x) {
	double y;
	if (x <= 3) {
		y = (pow(x, 2) - 3 * x + 9);
	}
	else {
		y = 1 / (pow(x, 3) + 3);
	}
	return y;
}

double fb(double x) {
	double y;
	y = x * exp(sin(pow(x,2)));
	return y;
}

//функции для второго задания

double sin_1(double x1) {
	double y1;
	y1 = sin(x1);
	return y1;
}

double sin_n(double x1, int N) {
	double y1 = 0;
	double f = 1;
	for (int i = 1; i <= N; i++) {
		f *= (i == 1 ? 1 : (i * 2 - 2)) * (2 * i - 1); // фактариалы
		y1 += (pow(-1, i - 1) * pow(x1, 2 * i - 1)) / f; // результат
	}
	return y1;
}

double sin_eps(double x1, double eps) {
	double y1 = 0;
	double f = 1;
	for (int i = 1; i <= 100; i++) {
		f *= (i == 1 ? 1 : (i * 2 - 2)) * (2 * i - 1); // фактариалы
		y1 += (pow(-1, i - 1) * pow(x1, 2 * i - 1)) / f; // результат
	}
	return round(y1 * pow(10, eps) / pow(10, eps)); //округление числа до ближайшего целого
}
main() {
	setlocale(LC_ALL, "RUS");

	//задание 1

	double x;
	printf("Введите значение х для решения уравнений f(x): \n");
	scanf_s("%lf", &x);

	printf("\n");

	printf("fa(x) = %lf, fb(x) = %lf \n", fa(x), fb(x));

	printf("\n");

	printf("Произведение двух функций = %lf \n", (fa(x) * fb(x)));
	printf("Разность квадратов двух функций = %lf \n", (pow(fa(x), 2) - pow(fb(x), 2)));
	printf("Удвоенная сумма двух функций = %lf \n", (2 * (fa(x) + fb(x))));

	printf("\n");

	// задание 2

	double x1;
	printf("Введите значение х для вычисления функции sin(x): \n");
	scanf_s("%lf", &x1);

	printf("\n");

	int N;
	printf("Введите число суммируемых членов ряда для вычисления функции sin(x): \n");
	scanf_s("%d", &N);

	printf("\n");

	double eps;
	printf("Введите число точности для вычисления функции sin(x): \n");
	scanf_s("%lf", &eps);

	printf("\n");

	printf("Результат первого вычисления sin(x) = %lf \n", sin_1(x1));
	printf("Результат второго вычисления sin(x) = %lf \n", sin_n(x1,N));
	printf("Результат третьего вычисления sin(x) = %lf \n", sin_eps(x1,eps));
}