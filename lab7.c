//#_CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>

int main()
{
	// задание 1
	setlocale(LC_ALL, "RUS");

	char a;
	puts("¬ведите символы 'буквы' or 'цифры': ");
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
		printf("Ёто цифра\n");
		break;

	default:
		printf("Ёто буква\n");
		break;

	}

	// задание 2

	float x, y, r;
	char c;

	puts("¬ведите первое число, операцию ('+', '-', '*', '/') , второе число");
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
		printf("Ќекорректна€ запись, попробуйте ещЄ раз...\n");
		break;

	}

	// задание 3, вариант 15

	int m;
	puts("¬ведите кол-во мес€цев...");
	scanf_s("%d", &m);
	switch (m)
	{
	case 0:
	case 1:
		printf("новорожденный\n");
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		printf("младенец\n");
		break;
	case 12:
	case 24:
		printf("раннее детство\n");
		break;
	case 36:
	case 48:
	case 60:
	case 72:
		printf("дошкольник\n");
		break;
	case 84:
	case 96:
	case 108:
	case 120:
	case 132:
	case 144:
		printf("школьник\n");
		break;
	case 156:
	case 168:
	case 180:
	case 192:
		printf("подросток\n");
		break;

	default:
		printf("от 17 лет и старше\n");
		break;

	}
}