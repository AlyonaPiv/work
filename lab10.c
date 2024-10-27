#include <stdio.h>
#include <locale.h>
#include <math.h>

 // ������� ��� ������� �������

double fa(double x) {
	double y;
	if (x <= 3) {
		y = (pow(x, 2) - 3 * x + 9);
	}
	else {
		y = 1 / (pow(x, 3) + 3);
	}
	return y;
}

double fb(double x) {
	double y;
	y = x * exp(sin(pow(x,2)));
	return y;
}

//������� ��� ������� �������

double sin_1(double x1) {
	double y1;
	y1 = sin(x1);
	return y1;
}

double sin_n(double x1, int N) {
	double y1 = 0;
	double f = 1;
	for (int i = 1; i <= N; i++) {
		f *= (i == 1 ? 1 : (i * 2 - 2)) * (2 * i - 1); // ����������
		y1 += (pow(-1, i - 1) * pow(x1, 2 * i - 1)) / f; // ���������
	}
	return y1;
}

double sin_eps(double x1, double eps) {
	double y1 = 0;
	double f = 1;
	for (int i = 1; i <= 100; i++) {
		f *= (i == 1 ? 1 : (i * 2 - 2)) * (2 * i - 1); // ����������
		y1 += (pow(-1, i - 1) * pow(x1, 2 * i - 1)) / f; // ���������
	}
	return round(y1 * pow(10, eps) / pow(10, eps)); //���������� ����� �� ���������� ������
}
main() {
	setlocale(LC_ALL, "RUS");

	//������� 1

	double x;
	printf("������� �������� � ��� ������� ��������� f(x): \n");
	scanf_s("%lf", &x);

	printf("\n");

	printf("fa(x) = %lf, fb(x) = %lf \n", fa(x), fb(x));

	printf("\n");

	printf("������������ ���� ������� = %lf \n", (fa(x) * fb(x)));
	printf("�������� ��������� ���� ������� = %lf \n", (pow(fa(x), 2) - pow(fb(x), 2)));
	printf("��������� ����� ���� ������� = %lf \n", (2 * (fa(x) + fb(x))));

	printf("\n");

	// ������� 2

	double x1;
	printf("������� �������� � ��� ���������� ������� sin(x): \n");
	scanf_s("%lf", &x1);

	printf("\n");

	int N;
	printf("������� ����� ����������� ������ ���� ��� ���������� ������� sin(x): \n");
	scanf_s("%d", &N);

	printf("\n");

	double eps;
	printf("������� ����� �������� ��� ���������� ������� sin(x): \n");
	scanf_s("%lf", &eps);

	printf("\n");

	printf("��������� ������� ���������� sin(x) = %lf \n", sin_1(x1));
	printf("��������� ������� ���������� sin(x) = %lf \n", sin_n(x1,N));
	printf("��������� �������� ���������� sin(x) = %lf \n", sin_eps(x1,eps));
}