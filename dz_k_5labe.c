//15 �������
#include <stdio.h>
#include <locale.h>
#include <math.h>

main()
{
	// ���������� �����������
	setlocale(LC_ALL, "RUS");

	// ���������� ����������
	float x, y, z; 

	//���� ��������� � ����������
	puts("������� �������� x...");
	scanf_s("%f", &x);
	puts("������� �������� y...");
	scanf_s("%f", &y);
	puts("������� �������� z...");
	scanf_s("%f", &z);

	//��������� �� ������� ������
	float h = (((pow(x, y +1) + exp(y - 1)) / (1 + (x * fabs(y - tan(z))))) * (1 + fabs(y - x))) + (((pow(fabs(y - x), 2)) / 2) - ((pow(fabs(y - x), 3)) / 3));
	
	//����� ����������
	printf("�����: %.5f", h);
}