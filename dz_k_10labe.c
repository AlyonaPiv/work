#include <stdio.h>
#include <locale.h>
#include <math.h>

double area_triangle(double a, double b) { //������� ������� �������
	return 0.5 * a * b;
}
void defining_a_figure(int j) { //������� ����������� ������
	int m;
	switch (j) {
	case 1:
		printf("������������� ����������� � ��� �����������, � �������� ���� �� ����� ����� 90�.\n\n");
		break;
	case 2: 
		printf("���������� - ��� �������, ������� �������� ������� ����.\n\n");
		break;
	case 3:
		printf("������ - ���  ��� ������� �������������� ������������, ������� �������� ������ ����.\n\n");
		break;
	case 4:
		printf("�������� ������ ������� �������������� ������������: \n 1 - ������ �������; \n 2 - ������� �������� ������; \n 3 - ������ �������; \n 4 - ������� �������� ������; \n 5 - ������ �������; \n");
		scanf_s("%d", &m);
		switch (m) {
		case 1:
			printf("������� �������������� ������������, ����������� � ����������, ����� �� ��������.\n\n");
			break;
		case 2:
			printf("���� ������� ������������ ����� �������� �������, � ������� ��� ���������, �� ����������� -� �������������.\n\n");
			break;
		case 3:
			printf("� ������������� ������������ �����, ������� �������� ���� 30 ��������, ����� �������� ����������.\n\n");
			break;
		case 4:
			printf("���� � ������������� ������������ ����� ����� �������� ���������� , �� �� ����� ������ ���� � 30 ��������.\n\n");
			break;
		case 5:
			printf("����� ����������, ��������� ����� �������������� ������������, ����� �� �������� ����������.\n\n");
			break;

		default:
			printf("��������� ����������� ���������, ��������� �����");
			break;
		}
	default:
		printf("��������� ����������� ���������, ��������� �����");
		break;
	}
}
void draw_round(double a,double b, char si) { //������� ��������� ������
	double c = sqrt(pow(a, 2) + pow(b, 2)); //���������� ������������
	for (int i = 0; i < a; i++) {
		for (int j = 0; j <= i; j++) {
			if (j <= c) {
				printf("%c", si);
			}
		}
		printf("\n");
	}
}
main() {
	setlocale(LC_ALL, "RUS");

	int j, l;
	double a, b;
	char si;

	printf("������� ����� ��������: \n 1 - ���������� ������� �������������� ������������; \n 2 - ����������� �������������� ������������; \n 3 - ������� �������������� ����������� \n");
	scanf_s("%d", &j);
	switch (j) {
	case 1:
		printf("������� ������ ����� �������������� ������������: \n");
		scanf_s("%lf", &a);

		printf("������� ������ ����� �������������� ������������: \n");
		scanf_s("%lf", &b);

		printf("������� �������������� ������������ � ��������� ����������� = %.lf \n", area_triangle(a, b));

		break;
	case 2:
		printf("������� ����� �����������: \n 1 - ������������� �����������; \n 2 - ����������; \n 3 - ������; \n 4 - ������� �������������� ����������� \n");
		scanf_s("%d", &l);
		defining_a_figure(l);
		break;
	case 3:
		printf("������� ������ ����� �������������� ������������: \n");
		scanf_s("%lf", &a);

		printf("������� ������ ����� �������������� ������������: \n");
		scanf_s("%lf", &b);

		printf("������� ����� ������: \n");
		scanf_s("%c", &si);
		si = getchar();
		printf("\n");

		draw_round(a, b, si);

		break;
	default:
		printf("��������� ����������� ���������, ��������� �����");
		break;
	}
}