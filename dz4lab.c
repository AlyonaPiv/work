//15 �������
#include <stdio.h>
#include <locale.h>

int s(int D, int L)
{
	int  S = (D * L);
	return S;
}

int money(int D, int L, int X)
{
	int dG = (D * L * X);
	return dG;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int L, D, X;
	puts("������� ����� �������...");
	scanf_s("%d", &D);
	puts("������� ������ �������...");
	scanf_s("%d", &L);
	puts("������� ��������� �� ���� �������� ���� �������...");
	scanf_s("%d", &X);
	printf("�� %d �������� ������ ���� �������� %d ������� �����", s(D,L), money(D,L,X));
}