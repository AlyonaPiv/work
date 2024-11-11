#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define N 10

//������� ����� ������������ �������
int vvod_massiva(int a[10][10], int n, int m) {
	
	if (!(n < 10) || !(m < 10)) return;
	// ���� ��������� �������
	for (int i = 0; i < n; i++) // ���� �� �������
	{
		for (int j = 0; j < m; j++) {// ���� �� ��������
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &a[i][j]);
		}
	}
	// ����� ��������� �������
	for (int i = 0; i < n; i++) // ���� �� �������
	{
		for (int j = 0; j < m; j++) // ���� �� ��������

		{
			printf(" %d ", a[i][j]); //
		}
		printf("\n");
	}
}

// ������� ��������� ��������� ������� �� �������� ������
int product_matric(int C[10][10], int A[10][10], int B[10][10], int s1, int s2, int k1, int k2) {
	if (!(s1 < 10) || !(k1 < 10)) return;
	printf("������ �������: \n\n");
	// ���� ��������� �������
	for (int i = 0; i < s1; i++) // ���� �� �������
	{
		for (int j = 0; j < k1; j++) {// ���� �� ��������
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &A[i][j]);
		}
	}
	printf("\n");
	// ����� ��������� �������
	for (int i = 0; i < s1; i++) // ���� �� �������
	{
		for (int j = 0; j < k1; j++) // ���� �� ��������
		{
			printf(" %d ", A[i][j]); //
		}
		printf("\n");
	}
	printf("\n������ �������: \n\n");
	if (!(s2 < 10) || !(k2 < 10)) return;
	// ���� ��������� �������
	for (int i = 0; i < s2; i++) // ���� �� �������
	{
		for (int j = 0; j < k2; j++) {// ���� �� ��������
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &B[i][j]);
		}
	}
	printf("\n");
	// ����� ��������� �������
	for (int i = 0; i < s2; i++) // ���� �� �������
	{
		for (int j = 0; j < k2; j++) // ���� �� ��������
		{
			printf(" %d ", B[i][j]); //
		}
		printf("\n");
	}
	printf("\n���������: \n\n");
	// ������������ ���� ������
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < k1; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	// ����� ����������
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k2; j++) {
			printf(" %d ", C[i][j]);
		}
		printf("\n");
	}
}

// ������� ���������� ������� ������� ��������
int sort_massiv() {
	
}

int main() {
	setlocale(LC_ALL, "RUS");
	int a[10][10];

	int g;
	printf("������� ����������� �������:  ");
	scanf_s("%d", &g);
	// ��������� ������ ��� �������
	int *A, *B , *C;
	A = (int*)malloc(g * sizeof(int));
	B = (int*)malloc(g * sizeof(int));
	C = (int*)malloc(g * sizeof(int));
	
	int n, m;

	int s1, s2, k1, k2;
	
	while (1)
	{
		char o;

		int e;
		printf("������� ����� ��������: \n 1 - ���� ������������ �������; \n 2 - ��������� ������� � �� ������ B �� �������� ������; \n 3 - ��������� ���������� �������.\n");
		scanf_s("%d", &e);

		switch (e) {
		case 1:
			printf("������� ���������� �����: ");
			scanf_s("%d", &n);
			printf("������� ���������� ��������: ");
			scanf_s("%d", &m);
			vvod_massiva(a,n, m);
			break;
		case 2:
			puts("\t������� ������� ������, ��� ��������� ����� ����� �� ������������\n");
			printf("\n������� ���������� ����� ������ �������:  ");
			scanf_s("%d", &s1);
			printf("\n������� ���������� �������� ������ �������:  ");
			scanf_s("%d", &k1);

			printf("\n\n������� ���������� ����� ������ �������:  ");
			scanf_s("%d", &s2);
			printf("\n������� ���������� �������� ������ �������:  ");
			scanf_s("%d", &k2);

			printf("\n\n������ ������ ������� %d*%d, ������ ������ ������� %d*%d\n", s1, k1, s2, k2);

			if (k1 != s2) {
				printf("���������� �������� ������ ������� �� ��������� � ����������� ����� ������ �������: \n\t��������� ����������");
			}
			else {
				printf("\n��������� ��������! \n\n");
			}
			product_matric(C, A, B, s1, s2, k1, k2);
			break;
		case 3:

		default:
			printf("��������� ����������� ���������, ��������� �����\n");
			break;
		}


		printf("���������� ? (�� - y, ��� - n)  ");
		if ((o = getchar()) == 'n')
			break;
	}
}