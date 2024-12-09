#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int* zap_sobstv(int** A, int s1, int k1);
int* random(int** A, int d, int s1, int k1);
int* proizvedenie(int** C, int** A, int** B, int s1, int k1, int k2);
int* print(int** A, int s1, int k1);

int main() {
	setlocale(LC_ALL, "RUS");

	puts("\t****************************************************************************************");
	puts("\t*                                 �������� ������                                      *");
	puts("\t*                                                                                      *");
	puts("\t*                        ���������� ������� ������: ���-242                            *");
	puts("\t*                           ���������� ���� �����������                               *");
	puts("\t****************************************************************************************");

	while (1) {

		char o;

		int g;
		printf("\t������� ����������� �������:  ");
		scanf_s("%d", &g);

		int s1, s2, k1, k2;

		printf("\n\t������� ���������� ����� ������ �������:  ");
		scanf_s("%d", &s1);
		printf("\n\t������� ���������� �������� ������ �������:  ");
		scanf_s("%d", &k1);

		if (!(s1 < g) || !(k1 < g)) return; // �������� ����������� �������

		// ��������� ������ ��� ������ ������
		int** A = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			A[i] = (int*)malloc(k1 * sizeof(int));
		}
		if (A == NULL) {
			puts("����������� ���������");
			return -1;
		}

		printf("\n\t������� ���������� ����� ������ �������:  ");
		scanf_s("%d", &s2);
		printf("\n\t������� ���������� �������� ������ �������:  ");
		scanf_s("%d", &k2);

		if (!(s2 < g) || !(k2 < g)) return; // �������� ����������� �������

		// ��������� ������ ��� ������ ������
		int** B = (int**)malloc(s2 * sizeof(int*));
		for (int i = 0; i < s2; i++) {
			B[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (B == NULL) {
			puts("����������� ���������");
			return -1;
		}

		int spsb, end, d;
		printf("\n\t�������� ������ ������������� ��������: \n\t\t 1 - ���������������; \n\t\t 2 - � ������� ��������� ��������� �����\n\t\t\t");
		scanf_s("%d", &spsb);

		printf("\n\t�������� ������ ������ ����������: \n\t\t 1 - ������ �����, ������������ � ���������� ��������� ������; \n\t\t 2 - ��� ��� �������;\n\t\t 3 - ��� ��� ������� � �������������\n\t\t\t");
		scanf_s("%d", &end);

		// �������� ���������� ������� ��������� ������ 
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

		switch (spsb) { // ������������� �� ������ ������������
		case(1):
			puts("\n\t\t������� ������ �������:   \n");
			zap_sobstv(A, s1, k1);
			printf("\n");

			puts("\n\t������� ������ �������:   \n");
			zap_sobstv(B, s2, k2);
			printf("\n");
			break;

		case (2):
			puts("\n\t������� ������������ �������� ��������� > 1:  ");
			scanf_s("%d", &d);

			random(A, d, s1, k1);
			random(B, d, s2, k2);
			break;
		}

		// ��������� ������ ��� �������������� ������
		int** C = (int**)malloc(s1 * sizeof(int*));
		for (int i = 0; i < s1; i++) {
			C[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (C == NULL) {
			puts("����������� ���������");
			return -1;
		}

		// ������������ ���� ������
		proizvedenie(C, A, B, s1, k1, k2);

		switch (end) { // ����� ����������� �� ������ ������������
		case(1):
			printf("\n\t\t���������: \n\n");
			// ����� ����������
			print(C, s1, k2);
			
			break;
		case(2):
			printf("\n\t\t������ �������: \n\n");
			// ����� ��������� ������� �������
			print(A, s1, k1);
			printf("\n");

			printf("\n\t\t������ �������: \n\n");
			// ����� ��������� ������� �������
			print(B, s2, k2);
			
			printf("\n");

			printf("\n\t\t���������: \n\n");
			// ����� ����������
			print(C, s1, k2);
			
			break;
		case (3):
			// ��������� - �������, ��� ������� ������� ����� ���� �������� ���� �� �����
			printf("\t���������� �������� ������ ������� ��������� � ����������� ����� ������ �������, ������� ��������� ��������.\n\n");

			printf("\n\t\t������ �������: \n\n");
			// ����� ��������� ������� �������
			print(A, s1, k1);

			printf("\n");
			printf("\n\t\t������ �������: \n\n");
			// ����� ��������� ������� �������
			print(B, s2, k2);

			printf("\n");
			// ��������� - ��� ���������� ���������
			printf("\t��������� ������ �������������� ����� ��������� ������ �� �������. \n");
			printf("��������� ������������ ������� �������� ������ � ������� �������� �������, ������� �������� ������ � ������� �������� ������� � �.�. \n");
			printf("����� ���������� ������������ �����������.\n");

			printf("\n\t\t���������: \n\n");
			// ����� ����������
			print(C, s1, k2);

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

		printf("\n");

		printf("���������� ? (�� - y, ��� - n)  ");
		o = getchar();

		if (o == 'n') {
			break;
		}
	}
}

int* zap_sobstv(int** A, int s1, int k1) {
	for (int i = 0; i < s1; i++) { // ���� �� �������

		for (int j = 0; j < k1; j++) {// ���� �� ��������
			printf(" a[%d][%d] = ", i, j);
			scanf_s("\n%d", &A[i][j]);
		}
	}
	return *A;
}

int* random(int** A, int d, int s1, int k1) {
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k1; j++) {
			A[i][j] = -d + rand() % (d - (-d));
		}
	}
	return *A;
}

int* proizvedenie(int** C, int** A, int** B, int s1,int k1, int k2) {
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < k2; j++) {
			C[i][j] = 0;
			for (int k = 0; k < k1; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return *C;
}

int* print(int** A, int s1, int k1) {
	for (int i = 0; i < s1; i++) { // ���� �� �������
		for (int j = 0; j < k1; j++) { // ���� �� ��������

			printf(" %3d ", A[i][j]); //
		}
		printf("\n");
	}
	return 0;
}