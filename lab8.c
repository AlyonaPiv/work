#include <stdio.h>
#include <locale.h>
#include <math.h>

main()
{
	setlocale(LC_ALL, "RUS");

	// ������� 0

	for (int start = 1; start <= 10; start++) putchar('*'); printf("\n");

	int j; // ���������� ����������
	char a;

	printf("������� ���-�� ��������: \n");
	scanf_s("%d", &j); // ���� ���������� ��������

	printf("������� ��� ��������: \n");
	scanf_s("%c", &a); // ���� ���� ��������

	a = getchar(); // ���� �������, ������� ������������� ����������

	for (int start = 1; start <= j; start++) putchar(a); putchar('+'); // � ����� � �����
	printf("\n");

	int n; // ���������� ����������
	char a1, b;

	printf("������� ���-�� ��������: \n");
	scanf_s("%d", &n); // ���� ���������� ��������

	printf("������� ������ ��� ��������: \n");
	scanf_s("%c", &a1); // ���� ������� ���� ��������

	a1 = getchar(); // ���� �������, ������� ������������� ����������

	printf("������� ������ ��� ��������: \n");
	scanf_s("%c", &b); // ���� ������� ���� ��������

	b = getchar(); // ���� �������, ������� ������������� ����������

	for (int i = 1; i <= n; i++) {

		if (i <= n / 2)
			putchar(a1); // ������ �������� ��������
		else
			putchar(b); // ������ �������� ��������

		putchar('!'); // '!' ����� ������� �������
	}
	printf("\n");

	// ������� 1

	int m, n1; // ���������� ����������

	printf("\n");

	printf("������� ��������� ����� m \n");
	scanf_s("%d", &m); //���� ���������� �����
	printf("������� �������� ����� n \n");
	scanf_s("%d", &n1); //���� ��������� �����

	int s = 0; // ������� ��� ���������� ����������
	int k = 0; // ������� ��� ���������� ���-�� ��������

	for (int i = m; i >= n; i--) {

		s += i; // ����� �����������
	    k += 1; // ���-�� ��������

		printf("��������� %d ���\n", k);
	}
	printf("\n");
	printf("���������: %d\n\n", s);

	// ������� 1�

	int c;
	printf("������� ������������ ��� ������� ������\n\n");
	scanf_s("%d", &c); // ���� �������

	for (int i = 0; i <= c; i++) {
		double stepen = pow(2, i); // ���������� ������ � �������
		printf("2^%d = %.lf \n", i, stepen);
	}
	double last_s = pow(2, c);
	double res = last_s / 1024.0;
	printf("��������� ��� %d ������� - %.1lfK\n\n", c, res); // ���������  ��������� 0.1�

	// ������� 2, 9 �������

	int nach = 2; // �������� �� 2 �� 4 ���
	int kon = 4;
	int sh; // ���

	printf("������� y = x^3 + 3*x^2 - 3 \n\n");
	printf("������� ���\n\n");
	scanf_s("%d", &sh); //���� ���� ���������

	for (int x = nach; x <= kon; x += sh) {
		double y = (pow(x, 3) + (3 * pow(x, 2)) - 3);

		printf("|  %d\t|  %.lf\t|\n", x, y);
		printf("-----------------\n");
	}

	// ������� 3 (�������) ������� 15

	int N; 

	printf("������� ����� ����� N\n");
	scanf_s("%d", &N);

	double p = 0, o = 0;

	for (int i = 1; i <= N; i++) {
		 p += sin(i);
		 o += 1 / p;
		 printf("%lf", o);
	}
}