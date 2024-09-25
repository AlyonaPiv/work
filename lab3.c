#include <stdio.h>
#include <locale.h>
#define D 2.54
#define S 2.7076 
int main()
{
	int num, v;
	setlocale(LC_ALL, "RUS");
	puts("введите число");
	scanf_s("%d",&num);
	puts("введено число А");
	puts("введите число");
	scanf_s("%d", &v);
	puts("введено число B");
	printf("%d + %d = %d\n", num, v, num + v);
	printf("%d - %d = %d\n", num, v, num - v);
	printf("%d * %d = %d\n", num, v, num * v);
	printf("%d / %d = %d, а остаток = %d\n", num, v, num / v, num % v);
	int dym;
	float result;
	puts("введите число");
	scanf_s("%d",&dym);
	result = D * dym;
	printf("%d дюймов - это %.1f см\n", dym, result);
	int sdym;
	float _result;
	puts("введите число");
	scanf_s("%d",&sdym);
	_result = S * sdym;
	printf("%d старолитовских дюймов - это %.1f см\n", sdym, _result);
	int a, b;
	puts("введите число");
	scanf_s("%d", &a);
	puts("введите число");
	scanf_s("%d", &b);
	puts("___________________\n");
	puts("| a*b | a+b | a-b |\n");
	puts("-------------------");
	printf("| %2.f*%2.f | %2.f+%2.f | %2.f-%2.f |\n",a,b,a,b,a,b);
	puts("-------------------\n");
	printf("| %3.f |  %3.f  |  %3.f  |\n", a*b, a+b, a-b);
	puts("-------------------");
}