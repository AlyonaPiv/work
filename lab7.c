//#_CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>

int main()
{
	// ������� 1
	setlocale(LC_ALL, "RUS");

	char a;
	puts("������� ������� '�����' or '�����': ");
	scanf_s("%c", &a); //���������� � �������
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
		printf("��� �����\n");
		break;

	default:
		printf("��� �����\n");
		break;

	}

	// ������� 2

	float x, y, r;
	char c;

	puts("������� ������ �����, �������� ('+', '-', '*', '/') , ������ �����");
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
		printf("������������ ������, ���������� ��� ���...\n");
		break;

	}

	// ������� 3, ������� 15

	int m;
	puts("������� ���-�� �������...");
	scanf_s("%d", &m);
	switch (m)
	{
	case 0:
	case 1:
		printf("�������������\n");
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
		printf("��������\n");
		break;
	case 12:
	case 24:
		printf("������ �������\n");
		break;
	case 36:
	case 48:
	case 60:
	case 72:
		printf("����������\n");
		break;
	case 84:
	case 96:
	case 108:
	case 120:
	case 132:
	case 144:
		printf("��������\n");
		break;
	case 156:
	case 168:
	case 180:
	case 192:
		printf("���������\n");
		break;

	default:
		printf("�� 17 ��� � ������\n");
		break;

	}
}