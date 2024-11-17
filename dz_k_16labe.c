#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

double* dzA(double* A, int size_a) { // ���������� ���������� ������� �� ��������� ������� 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size_a; i++) {
		A[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return A;
}
int printf_element1(double* A, int size_a) { //����� ������ 

	for (int i = 0; i < size_a; i++) {
		printf("A[%2d] = %.lf\n", i, A[i]);
	}
	return 0;
}

double* dzB(double* B, int size_b) { // ���������� ���������� ������� �� ��������� ������� 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size_b; i++) {
		B[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return B;
}
int printf_element2(double* B, int size_b) { //����� ������

	for (int i = 0; i < size_b; i++) {
		printf("B[%2d] = %.lf\n", i, B[i]);
	}
	return 0;
}

double* dzC(double* C, int size_c) { // ���������� ���������� ������� �� ��������� ������� 
	int XMIN = -10, XMAX = 10;
	for (int i = 0; i < size_c; i++) {
		C[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
	}
	return C;
}
int printf_element3(double* C, int size_c) { //����� ������

	for (int i = 0; i < size_c; i++) {
		printf("C[%2d] = %.lf\n", i, C[i]);
	}
	return 0;
}
// ���������� ������� ������� �� ������ �������� ����� ������� ���������� �����
double* dz(double* A, double* B, double* C, double* D, int size_a, int size_b, int size_c) {
	int t = 0;//������� ������� 4-�� �������
	int index = 0;
	
	for (int i = 0; i < size_a; i++) { // ������� ��������� ����� �� ������� ������� 
		t++;
		if (t % 4 != 0) {
			D[index] = A[i];
			index++;
		}
	}
	for (int i = 0; i < size_b; i++) { // ����� �� �������
		t++;
		if (t % 4 != 0) {
			D[index] = B[i];
			index++;
		}
	}
	for (int i = 0; i < size_c; i++) { // ����� �� ��������
		t++;
		if (t % 4 != 0) {
			D[index] = C[i];
			index++;
		}
	}
	return D;
}
int printf_element4(double* D, int size_d) { // ����� �������

	for (int i = 0; i < size_d; i++) {
		printf("D[%2d] = %.lf\n", i, D[i]);
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "RUS");

	// �� ������� 15

	double* A, * B, * C, * D;
	int size_a, size_b, size_c, size_d;

	printf("\n������� ������ ������� �:   ");
	scanf_s("%d", &size_a);
	printf("\n������� ������ ������� B:   ");
	scanf_s("%d", &size_b);
	printf("\n������� ������ ������� C:   ");
	scanf_s("%d", &size_c);

	size_d = (size_a + size_b + size_c) - ((size_a + size_b + size_c)/4);

	// ��������� ������
	A = (double*)malloc(size_a * sizeof(double));
	if (A == NULL) { // �������� ��������� ������
		puts("����������� ���������");
		return -1;
	}
	B = (double*)malloc(size_b * sizeof(double));
	if (B == NULL) { // �������� ��������� ������
		puts("����������� ���������");
		return -1;
	}
	C = (double*)malloc(size_c * sizeof(double));
	if (C == NULL) { // �������� ��������� ������
		puts("����������� ���������");
		return -1;
	}
	D = (double*)malloc(size_d * sizeof(double));
	if (D == NULL) { // �������� ��������� ������
		puts("����������� ���������");
		return -1;
	}

	dzA(A, size_a);
	printf("\n����� A:  \n");
	printf_element1(A, size_a);
	dzB(B, size_b);
	printf("\n����� B:  \n");
	printf_element2(B, size_b);
	dzC(C, size_c);
	printf("\n����� C:  \n");
	printf_element3(C, size_c);
	dz(A, B, C, D, size_a, size_b, size_c);
	printf("\n����� D:  \n");
	printf_element4(D, size_d);

	// ������������ ������
	free(A);
	free(B);
	free(C);
	free(D);
}