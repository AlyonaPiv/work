#include <stdio.h>
#include <locale.h>

//15 �������
main()
{
	setlocale(LC_ALL, "RUS");
	int x, y;
	puts("������� �������� ���������� �� ��...");
	scanf_s("%d", &x);
	puts("������� �������� ���������� �� ��...");
	scanf_s("%d", &y);
	if (((x >= 2) && (x <= 6)) && ((y >= 4) && (y <= 6)))
		printf("����� � ������������ (%d,%d) ����������� �������", x, y);
	else
		printf("����� � ������������ (%d,%d) �� ����������� �������", x, y);
}