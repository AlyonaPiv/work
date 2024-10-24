#include <stdio.h>
#include <locale.h>
#include <math.h>

main() {
	setlocale(LC_ALL, "RUS");

	// задание 3 (домашка) , 3 вариант

	int a, b;
	char si;
	while (1)
	{
		char l;
		// Решение домашней задачи

		printf("Введите первый катет прямоугольного треугольника: \n");
		scanf_s("%d", &a);
		printf("Введите второй катет прямоугольного треугольника: \n");
		scanf_s("%d", &b);
		printf("Введите любой символ: \n");
		scanf_s("%c", &si);
		si = getchar();
		printf("\n");
		double c = sqrt(pow(a, 2) + pow(b, 2)); //гипотенуза треугольника
		for (int i = 0; i < a; i++) {
			for (int j = 0; j <= i; j++) {
				if (j <= c) {
					printf("%c", si);
				}
			}
			printf("\n");
		}
		printf("\n");
		printf("Продолжить ? (Да - y, нет - n)\n");
		if ((l = getchar()) == 'n') break;

	}
}