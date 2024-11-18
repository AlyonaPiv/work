#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50
#define X 7
#define CHEL 18
#define MES 12

int main() {
	setlocale(LC_ALL, "RUS");
	float a[N][N];
	int str, stl;
	printf("������� ���������� �����: ");
	scanf_s("%d", &str);
	printf("������� ���������� ��������: ");
	scanf_s("%d", &stl);
	printf("\n");

	// ������� 1

	if (!(str < N) || !(stl < N)) return;
	// ���� ��������� �������
	for (int i = 0; i < str; i++) { // ���� �� �������
		for (int j = 0; j < stl; j++) {// ���� �� ��������
			a[i][j] = i + 1.f * ((j + 1) - i) * rand() / RAND_MAX; // ���.5 ���������� ��������� ������������ ��������� � ��������� �� ����������� ������ ������ �� ������ ������� + 1;
		}
	}
	// ����� ��������� �������
	for (int i = 0; i < str; i++) { // ���� �� �������
		for (int j = 0; j < stl; j++) { // ���� �� ��������
			printf("a[%d][%d] = %.2f ", i, j, a[i][j]); //
		}
		printf("\n");
	}
	printf("\n");
	// ����� ������ �������� �� ������ ������, ���.5
	printf("������� �� ������ ������ �������:   %.2f\n", a[1][0]);
	printf("\n");
	int S;
	printf("������� ����� ������� ��� ������ ���� �������� (�� 0 �� %d):   ", (stl - 1));
	scanf_s("%d", &S);
	float max = a[0][S];
	for (int i = 1; i < str; i++) {
		if (a[i][S] > max) {
			max = a[i][S];
		}
	}
	printf("������������ ������� � ������� %d - %.2f ", S, max);
	printf("\n\n");
	// ������� 2
	printf("�������� �����: \n");
	int b[X][X];
	for (int i = 0; i < X; i++) { // ���� �� �������
		for (int j = 0; j < X; j++) {// ���� �� ��������
			b[i][j] = rand() % 21 - 10; // ���������� ������ ������� �� -10 �� 10
		}
	}
	for (int i = 0; i < X; i++) { // ����� �������
		for (int j = 0; j < X; j++) {
			printf("%4d", b[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	printf("����������������� ������:  \n");
	int trans[X][X];
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			trans[i][j] = b[j][i];
		}
	}
	for (int i = 0; i < X; i++) { // ����� �������
		for (int j = 0; j < X; j++) {
			printf("%4d", trans[i][j]);
		}
		printf("\n");
	}

	int sumchet = 0;
	int k = 0;
	for (int i = 0; i < X; i++) {
		if (trans[i][2] % 2 == 0) {
			sumchet += trans[i][2]; // ����� ������ ��������� �������� �������
			k++;
		}
	}
	int srznach = sumchet / k; // ������� ��������
	printf("����� ������ ��������� �������� ������� = %d, ���������� ��������� = %d, ������� �������� ����� ����.�� = %d\n", sumchet, k, srznach);

	int k1 = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X - 1; j++) {
			if (trans[i][j] == trans[i][j+1]) {
				k1++;
			}
		}
	}
	printf(" ���������� ���������� ��� ��������� �  =  %d\n", k1);

	printf("\n\n");

	int MAX = trans[0][0];
	int max_X = 0, max_Y = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			if (trans[i][j] > MAX) {
				MAX = trans[i][j];
				max_X = i;
				max_Y = j;
			}
		}
	}
	printf(" ����������� ����� = %d, ���������� �� ������� = %d, ���������� �� ������� = %d\n\n", MAX, max_X, max_Y);
	printf("\t������� �������\n");

	// �� ������� 15
	int ZP[CHEL][MES];
	int sum_zp = 0;
	zp(ZP);
	printf_zp(ZP);
	printf("\n\n");
	int mes;
	printf("�������� ����� ��� ���������� ������� �������� ����������� (�� 1 �� 12):   ");
	scanf_s("%d", &mes);


	printf("\n�� %d ����� ������� �������� �������� = %d\n",mes, sumsrzn_zp(ZP, mes));
}
int zp(int ZP[CHEL][MES]) { // ���������� ���������� �������������� �������
	for (int i = 0; i < CHEL; i++) {
		for (int j = 0; j < MES; j++) {
			ZP[i][j] = rand() % 1001;
		}
	}
	return 0;
}
int printf_zp(int ZP[CHEL][MES]) {
	printf(" | ������|������� | ���� | ������ |  ���  | ���� | ���� | ������ | ��������|������� | ������|������� |\n");
	for (int i = 0; i < CHEL; i++) { // ����� �������
		for (int j = 0; j < MES; j++) {
			printf("%8d", ZP[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int sumsrzn_zp(int ZP[CHEL][MES], int mes) {
	int sum = 0;
	int k2 = 0;
	for (int i = 0; i < CHEL; i++) {
		sum += ZP[i][mes - 1];
		k2++;
	}
	printf("����� �������� ���� ����������� �� ����� = %d", sum);
	int srzn = sum / k2; // ������� ��������
	return srzn;
}