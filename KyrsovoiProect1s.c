#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int g;
	printf("\t������� ����������� �������:  ");
	scanf_s("%d", &g);

	while (1){
	
		char o;

		int s1, s2, k1, k2;

		printf("\n\t������� ���������� ����� ������ �������:  ");
		scanf_s("%d", &s1);
		printf("\n\t������� ���������� �������� ������ �������:  ");
		scanf_s("%d", &k1);
		puts("\n\t\t������� �������:   \n");

		if (!(s1 < g) || !(k1 < g)) return; // �������� ����������� ��������

		// ��������� ������ ��� ������ ������
		int** A = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			A[i] = (int*)malloc(k1 * sizeof(int));
		}
		if (A == NULL) {
			puts("����������� ���������");
			return -1;
		}
		// ���� ��������� ������� �������
		for (int i = 0; i < s1; i++) { // ���� �� �������

			for (int j = 0; j < k1; j++) {// ���� �� ��������
				printf(" a[%d][%d] = ", i, j);
				scanf_s("\n%d", &A[i][j]);
			}
		}
		printf("\n");

		printf("\n\t������� ���������� ����� ������ �������:  ");
		scanf_s("%d", &s2);
		printf("\n\t������� ���������� �������� ������ �������:  ");
		scanf_s("%d", &k2);
		puts("\n\t������� �������:   \n");

		if (!(s2 < g) || !(k2 < g)) return; // �������� ����������� ��������

		// ��������� ������ ��� ������ ������
		int** B = (int**)malloc(s2 * sizeof(int*));
		for (int i = 0; i < s2; i++) {
			B[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (B == NULL) {
			puts("����������� ���������");
			return -1;
		}
		// ���� ��������� ������� �������
		for (int i = 0; i < s2; i++) { // ���� �� �������

			for (int j = 0; j < k2; j++) {// ���� �� ��������
				printf(" a[%d][%d] = ", i, j);
				scanf_s("\n%d", &B[i][j]);
			}
		}
		printf("\n");

		printf("\n\t\t������ �������: \n\n");
		// ����� ��������� ������� �������
		for (int i = 0; i < s1; i++) { // ���� �� �������

			for (int j = 0; j < k1; j++) {// ���� �� ��������

				printf(" %d ", A[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\t\t������ �������: \n\n");
		// ����� ��������� ������� �������
		for (int i = 0; i < s2; i++) { // ���� �� �������

			for (int j = 0; j < k2; j++) { // ���� �� ��������

				printf(" %d ", B[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\n\t������ ������ ������� %d*%d, ������ ������ ������� %d*%d\n", s1, k1, s2, k2);

		if (k1 != s2) {
			printf("\n\t���������� �������� ������ ������� �� ��������� � ����������� ����� ������ �������: \n\t��������� ����������\n");
			// ������������ ������, ���� ������� ������ �����������
			for (int i = 0; i < s1; i++) {
				free(A[i]);
			}
			free(A);
			for (int i = 0; i < s2; i++) {
				free(B[i]);
			}
			free(B);
			return 1;
		}
		else {
			printf("\n\t\t��������� ��������! \n\n");
		}
		printf("\n\t\t������ �������: \n\n");
		// ����� ��������� ������� �������
		for (int i = 0; i < s1; i++) { // ���� �� �������

			for (int j = 0; j < k1; j++) { // ���� �� ��������

				printf(" %d ", A[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\t\t������ �������: \n\n");
		// ����� ��������� ������� �������
		for (int i = 0; i < s2; i++) { // ���� �� �������

			for (int j = 0; j < k2; j++) { // ���� �� ��������

				printf(" %d ", B[i][j]); //
			}
			printf("\n");
		}
		printf("\n");

		printf("\n\t\t���������: \n\n");
		// ������������ ���� ������
		int** C = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			C[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (C == NULL) {
			puts("����������� ���������");
			return -1;
		}
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
		// ������������ ������ 
		for (int i = 0; i < s1; i++) {
			free(A[i]);
		}
		free(A);
		for (int i = 0; i < s2; i++) {
			free(B[i]);
		}
		free(B);
		for (int i = 0; i < s1; i++) {
			free(C[i]);
		}
		free(C);

		printf("���������� ? (�� - y, ��� - n)  ");
		o = getchar();

		if (o == 'n') {
			break;
		}
	}
	return 0;
}