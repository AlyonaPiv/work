//15 вариант
#include <stdio.h>
#include <locale.h>
#include <math.h>

main()
{
	// добавление локализации
	setlocale(LC_ALL, "RUS");

	// объ€вление переменных
	float x, y, z; 

	//ввод переменых с клавиатуры
	puts("¬ведите значение x...");
	scanf_s("%f", &x);
	puts("¬ведите значение y...");
	scanf_s("%f", &y);
	puts("¬ведите значение z...");
	scanf_s("%f", &z);

	//уравнение из услови€ задачи
	float h = (((pow(x, y +1) + exp(y - 1)) / (1 + (x * fabs(y - tan(z))))) * (1 + fabs(y - x))) + (((pow(fabs(y - x), 2)) / 2) - ((pow(fabs(y - x), 3)) / 3));
	
	//вывод результата
	printf("ќтвет: %.5f", h);
}