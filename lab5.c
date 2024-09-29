#include <stdio.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define c 1.3 //для 2 задания

int main()
{
	setlocale(LC_ALL, "RUS");
	//1 задание
	double gr;
	puts("Введите количество радиан");
	scanf_s("%lf", &gr);
	double rad = sin(gr * M_PI / 180);
	printf("Ответ: %.6lf\n", rad);
	double gr1;
	puts("Введите количество радиан");
	scanf_s("%lf", &gr1);
	double rad1 = sin(gr1 * M_PI / 180);
	printf("Ответ: %.6lf\n", rad1);
	double gr2;
	puts("Введите количество радиан");
	scanf_s("%lf", &gr2);
	double rad2 = sin(gr2 * M_PI / 180);
	printf("Ответ: %.6lf\n", rad2);
	//2 задание, 8 вариант
	float x;
	puts("Введите переменную x...");
	scanf_s("%f", &x);
	float y = exp(x) + pow(5.8, -(pow(pow(c, 3) + log(fabs(x)), 2) + sqrt(c)));
	printf("Ответ: У = %.1f\n", y);
	float b = pow(pow(c, 3) + log(fabs(x)), 2) + sqrt(c);
	printf("Ответ: b = %.1f\n", b);
	float a = pow(c, 3) + log(fabs(x));
	printf("Ответ: a = %.1f\n", a);
	//3 задание
	int A = (int)a;
	int B = (int)b;
	int C = (int)y;
	printf("A - %d, B - %d, C - %d\n", A, B, C);
	if (((A % 2 == 0) && (B % 2 != 0)) || ((A % 2 != 0) && (B % 2 == 0)))
		printf("истина - %d\n", 1);
	else
		printf("ложь - %d\n", 0);
	if ((A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0))
		printf("истина - %d\n", 1);
	else
		printf("ложь - %d\n", 0);
}