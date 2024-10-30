#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10

main() {
	setlocale(LC_ALL, "RUS");

	// задание 1

	float A[10];
	float temp;

	for (int i = 0; i < 10; i++) {
		printf("a[%d] = ", i);
		scanf_s("%f", &temp);
		A[i] = temp;
	}

	printf("\n");

	//вариант 3

	printf("ќбнуление отрицательных цифр в массиве\n\n");
	
	float sum = 0.0;

	printf("|   индекс\t| исходное значение\t| новое значение\t|\n");

	for (int i = 0; i < N; i++) {
		printf("a[%d] = ", i);
		scanf_s("%f", &temp);
		A[i] = temp;
		if (A[i] < 0) {
			A[i] = 0;
		}
		printf("|        %d \t|             %.f  \t|            %.f  \t|\n", i, temp, A[i]);
		sum += A[i];
	}

	float srZnach = sum / N;

	printf("Cредее арифметическое значение новых элементов массива = %.2f \n", srZnach);


	// лабораторна€ работа 8, задание 2, 9 вариант

	printf("\n ¬торое задание \n");
	/*
	int nach = 2; // интервал от 2 до 4 вкл
	int kon = 4;
	float sh; // шаг
	printf("¬ведите шаг\n\n");
	scanf_s("%f", &sh); //ввод шага табул€ции
	printf("‘ункци€ y = x^3 + 3*x^2 - 3 \n\n");
	printf("¬ведите шаг\n\n");

	scanf_s("%d", &sh); //ввод шага табул€ции

	for (int x = nach; x <= kon; x += sh) {
		double y = (pow(x, 3) + (3 * pow(x, 2)) - 3);

		printf("|  %.d\t|  %.lf\t|\n", x, y);
		printf("-----------------\n");
	} */
	printf("\n");

	double A1[100];
	double sum_plus = 0.0, sum_minus = 0.0;
	int  c1 = 0, c2 = 0;

	double sh1 = (4 - 2) / 100.;
	for (double x = 2, i = 0; x < 4 && i < 100; x += sh1, i++) {
		A1[(int)i] = pow(x, 3) + 3 * pow(x, 2) - 3;
		printf("|  %.f \t|  %lf\t|\n", i, A1[(int)i]);
		if (A1[(int)i] > 0) {
			sum_plus += A1[(int)i];
			c1 += 1;
		}
		if (A[(int)i] < 0) {
			sum_minus += A1[(int)i];
			c2 += 1;
		}
	}
	double  srZnach1 = sum_plus / c1;
	double  srZnach2 = sum_minus / c2;
	
	printf("\n\t“аблица вычислений \n\n");


	printf("| им€ массива\t|         сумма элементов  \t|        кол-во элементов\t|      среднее значение \t|\n");
	printf("|            \t| полож.\t| отриц. \t| полож.\t| отриц.\t| полож. \t| отриц.\t|\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("|   A1[]   \t|   %.2f \t|   %.2f \t|  %d  \t|   %d  \t|   %.2f  \t|   %.2f \t|\n", sum_plus, sum_minus, c1, c2, srZnach1, srZnach2);
	printf("-----------------------------------------------------------------------------------------------------------------\n");

}