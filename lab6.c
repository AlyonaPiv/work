#include <stdio.h>
#include <locale.h>
#include <math.h>

double F(double x)
{
	double f;
	if (x > 3.6)
		f = 45 * pow(x, 2) + 5;

	else
		f = (5 * x) / (10 * pow(x, 2) + 1);

	return f;
}
main()
{
	setlocale(LC_ALL, "RUS");

	//задание 1.1
	int year;
	puts("Введите год");
	scanf_s("%d", &year);
	int year4 = year % 4;
	if (year4 == 0)
		printf("Год %d - високосный\n", year);
	else
		printf("Год %d - не високосный\n", year);

	//1.2
	if (((year4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("Год %d - високосный\n", year);
	else
		printf("Год %d - не високосный\n", year);

	//задание 2, 15 вариант
	double x;
	puts("Введите x...");
	scanf_s("%lf", &x);
	printf("Ответ: %.2lf\n", F(x)); // при х = 3,7 должен быть результат 621,05;
	puts("Введите x...");
	scanf_s("%lf", &x);
	printf("Ответ: %.2lf\n", F(x));//  при х = 3,5 результат должен быть равен 0,14;
	puts("Введите x...");
	scanf_s("%lf", &x);
	printf("Ответ: %.2lf\n", x > 3.6 ? (45 * pow(x, 2) + 5) : ((5 * x) / (10 * pow(x, 2) + 1))); // вывод с помощью тернарной операции в функции printf

	//Задание 3 , вариант 15
	int a;
	puts("Введите целое число a");
	scanf_s("%d", &a);
	int b;
	puts("Введите целое число b");
	scanf_s("%d", &b);
	if (a % b == 0)
		printf("%d делится нацело на %d\n", a, b);
	else
		printf("% d не делится нацело на % d\n", a, b);
}