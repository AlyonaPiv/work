#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10

main() {
	setlocale(LC_ALL, "RUS");

	// ������� 1

	float A[10];
	float temp;

	for (int i = 0; i < 10; i++) {
		printf("a[%d] = ", i);
		scanf_s("%f", &temp);
		A[i] = temp;
	}

	printf("\n");

	//������� 3

	printf("��������� ������������� ���� � �������\n\n");
	
	float sum = 0.0;

	printf("|   ������\t| �������� ��������\t| ����� ��������\t|\n");

	for (int i = 0; i < N; i++) {
		printf("a[%d] = ", i);
		scanf_s("%f", &temp);
		A[i] = temp;
		if (A[i] < 0) {
			A[i] = 0;
		}
		printf("|        %d \t|             %.f  \t|            %.f  \t|\n", i, temp, A[i]);
		sum += A[i];
	}

	float srZnach = sum / N;

	printf("C����� �������������� �������� ����� ��������� ������� = %.2f \n", srZnach);


	// ������������ ������ 8, ������� 2, 9 �������

	printf("\n ������ ������� \n");
	/*
	int nach = 2; // �������� �� 2 �� 4 ���
	int kon = 4;
	float sh; // ���
	printf("������� ���\n\n");
	scanf_s("%f", &sh); //���� ���� ���������
	printf("������� y = x^3 + 3*x^2 - 3 \n\n");
	printf("������� ���\n\n");

	scanf_s("%d", &sh); //���� ���� ���������

	for (int x = nach; x <= kon; x += sh) {
		double y = (pow(x, 3) + (3 * pow(x, 2)) - 3);

		printf("|  %.d\t|  %.lf\t|\n", x, y);
		printf("-----------------\n");
	} */
	printf("\n");

	double A1[100];
	double sum_plus = 0.0, sum_minus = 0.0;
	int  c1 = 0, c2 = 0;

	double sh1 = (4 - 2) / 100.;
	for (double x = 2, i = 0; x < 4 && i < 100; x += sh1, i++) {
		A1[(int)i] = pow(x, 3) + 3 * pow(x, 2) - 3;
		printf("|  %.f \t|  %lf\t|\n", i, A1[(int)i]);
		if (A1[(int)i] > 0) {
			sum_plus += A1[(int)i];
			c1 += 1;
		}
		if (A[(int)i] < 0) {
			sum_minus += A1[(int)i];
			c2 += 1;
		}
	}
	double  srZnach1 = sum_plus / c1;
	double  srZnach2 = sum_minus / c2;
	
	printf("\n\t������� ���������� \n\n");


	printf("| ��� �������\t|         ����� ���������  \t|        ���-�� ���������\t|      ������� �������� \t|\n");
	printf("|            \t| �����.\t| �����. \t| �����.\t| �����.\t| �����. \t| �����.\t|\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("|   A1[]   \t|   %.2f \t|   %.2f \t|  %d  \t|   %d  \t|   %.2f  \t|   %.2f \t|\n", sum_plus, sum_minus, c1, c2, srZnach1, srZnach2);
	printf("-----------------------------------------------------------------------------------------------------------------\n");

}