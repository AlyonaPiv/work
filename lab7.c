//#_CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>

int main()
{
	// задание 1
	setlocale(LC_ALL, "RUS");

	char a;
	puts("Введите символы 'буквы' or 'цифры': ");
	scanf_s("%c", &a); //считывание с консоли
	switch (a)
	{

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		printf("Это цифра\n");
		break;

	default:
		printf("Это буква\n");
		break;

	}

	// задание 2

	float x, y, r;
	char c;

	puts("Введите первое число, операцию ('+', '-', '*', '/') , второе число");
	//scanf_s("%f%c%f", &x, &c, &y);
	scanf_s("%f", &x);
	scanf_s("%c", &c);
	scanf_s("%f", &y);
	switch (c)
	{

	case '+':
		r = x + y;
		printf("= %.2f\n", r);
		break;
	case '-':
		r = x - y;
		printf("= %.2f\n", r);
		break;
	case '*':
		r = x * y;
		printf("= %.2f\n", r);
		break;
	case '/':
		r = x / y;
		printf("= %.2f\n", r);
		break;

	default:
		printf("Некорректная запись, попробуйте ещё раз...\n");
		break;

	}
}