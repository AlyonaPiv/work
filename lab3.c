#include <stdio.h>
#include <locale.h>
#define D 2.54
#define S 2.7076 
int main()
{
	int num, v;
	setlocale(LC_ALL, "RUS");
	puts("������� �����");
	scanf_s("%d",&num);
	puts("������� ����� �");
	puts("������� �����");
	scanf_s("%d", &v);
	puts("������� ����� B");
	printf("%d + %d = %d\n", num, v, num + v);
	printf("%d - %d = %d\n", num, v, num - v);
	printf("%d * %d = %d\n", num, v, num * v);
	printf("%d / %d = %d, � ������� = %d\n", num, v, num / v, num % v);
	int dym;
	float result;
	puts("������� �����");
	scanf_s("%d",&dym);
	result = D * dym;
	printf("%d ������ - ��� %.1f ��\n", dym, result);
	int sdym;
	float _result;
	puts("������� �����");
	scanf_s("%d",&sdym);
	_result = S * sdym;
	printf("%d �������������� ������ - ��� %.1f ��\n", sdym, _result);
	float a, b;
	puts("������� �����");
	scanf_s("%f",&a);
	puts("������� �����");
	scanf_s("%f",&b);
	puts("_________________________\n");
	puts("| a*b\t | a+b\t | a-b\t|\n");
	puts("-------------------------");
	printf("| %2.f*%2.f\t| %2.f+%2.f\t| %2.f-%2.f\t|\n", a, b, a, b, a, b);
	puts("-------------------------\n");
	printf("| %3.f \t|  %3.f \t |  %3.f\t|\n", a * b, a + b, a - b);
	puts("-------------------------\n");
}