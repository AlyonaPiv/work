#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;
	printf("%c , %d , %.2ff , %.le\n", c, i, f, d);
	printf("%d , %.2ff\n", (int)f, f-(int)f);
	printf("%x , %d\n", (int)c, (int)c);
	printf("%g\n", 1./i);
	int a = 11;
	int b = 3;
	int x = a / b;
	float y = a / b;
	double z = a / b;
	printf("%d , %.3f , %.7lf \n", x, y, z);
	printf("%.3f , %.7f\n", (float)a/b, (double)a/b);
	int N;
	printf("Введите целое трехзначное число...\n");
	scanf_s("%d",&N);
	printf("Последняя цифра целого трехзначного числа - %d\n", N%10);
	printf("Первая цифра целого трехзначного числа - %d\n", N / 100);
	printf("Сумма цифр целого трехзначного числа - %d\n", (N / 100) + (N % 10) + (N%100-(N%10))/10);
	printf("Целое трехзначное число наоборот - %d%d%d\n", N % 10, (N % 100 - (N % 10)) / 10, N / 100);
}