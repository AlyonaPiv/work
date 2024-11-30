#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#define p 100

double rand_double(double dmin, double dmax);//������������ ����� � �������� ��������� 
double* rand_double1(double* b, int q, double dm);// q ������������ ����� � ��������� �� -dm �� +dm 
void sort_bubble(double* b, int n); // ���������� ��������� 
int put_elements(double* b, int q); // ����� �������

int main() {
	setlocale(LC_ALL, "RUS");

	int q;
	printf("������� ���-�� ��������� � �������:  ");
	scanf_s("%d", &q);

	double b[p];

	double dm;
	printf("\n������� ����� ��������� ��� ���������� �������:  ");
	scanf_s("%lf", &dm);
	printf("\n");

	printf("������, ����������� ���������� �������:  \n");
	rand_double1(b, q, dm);
	printf("\n\n");

	printf("�������������� ������:  \n");
	sort_bubble(b, q);
	put_elements(b, q);
}

double rand_double(double dmin, double dmax) { //������������ ����� � �������� ��������� 
	double n = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	return n;
}

double* rand_double1(double* b, int q, double dm) {// q ������������ ����� � ��������� �� -dm �� +dm 
	for (int i = 0; i < q; i++) {
		b[i] = rand_double(-dm, dm); // ���������� ���������� �������
		printf(" %.2lf ", b[i]); // ����� ������������ �������
	}
	return b;
}

void sort_bubble(double* b, int q) { // ���������� ��������� �� �������� ���������
	for (int i = 0; i < q - 1; i++) {
		for (int j = i + 1; j < q; j++) {
			if ((int)b[i] < (int)b[j]) { // ���� ����� ����� ������� �������� < ����� ����� �������, ��:
				double temp = b[i]; // ���������� �������
				b[i] = b[j]; // ������ �������� �������
				b[j] = temp; 
			}
		}
	}
	return b;
}

int put_elements(double* b, int q) { // ����� ��������� �������
	for (int i = 0; i < q; i++) {
		printf(" %.2lf ", b[i]);
	}
	return 0;
}