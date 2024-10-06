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

	//������� 1.1
	int year;
	puts("������� ���");
	scanf_s("%d", &year);
	int year4 = year % 4;
	if (year4 == 0)
		printf("��� %d - ����������\n", year);
	else
		printf("��� %d - �� ����������\n", year);

	//1.2
	if (((year4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("��� %d - ����������\n", year);
	else
		printf("��� %d - �� ����������\n", year);

	//������� 2, 15 �������
	double x;
	puts("������� x...");
	scanf_s("%lf", &x);
	printf("�����: %.2lf\n", F(x)); // ��� � = 3,7 ������ ���� ��������� 621,05;
	puts("������� x...");
	scanf_s("%lf", &x);
	printf("�����: %.2lf\n", F(x));//  ��� � = 3,5 ��������� ������ ���� ����� 0,14;
	puts("������� x...");
	scanf_s("%lf", &x);
	printf("�����: %.2lf\n", x > 3.6 ? (45 * pow(x, 2) + 5) : ((5 * x) / (10 * pow(x, 2) + 1))); // ����� � ������� ��������� �������� � ������� printf

	//������� 3 , ������� 15
	int a;
	puts("������� ����� ����� a");
	scanf_s("%d", &a);
	int b;
	puts("������� ����� ����� b");
	scanf_s("%d", &b);
	if (a % b == 0)
		printf("%d ������� ������ �� %d\n", a, b);
	else
		printf("% d �� ������� ������ �� % d\n", a, b);
}