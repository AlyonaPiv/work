//15 �������
#include <stdio.h>
#include <locale.h>
#define AS 63240 // ���� �������� ��� ����� 63240 �������������� ������

int svet(int sg)
{
	int res = sg * AS;
	return res;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int sg;
	puts("������� �����");
	scanf_s("%d", &sg);
	printf("%d �������� ��� - ��� %d ��������������� ������", sg, svet(sg));
}