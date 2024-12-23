#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*TFun)(double); // ���������� ���� ��������� �� ������.

double fun1(double); // ���������� ���������� �������
double fun2(double);
double fun3(double);
void out_rez(TFun, double, double, double);
void print_array(double** arr, double s, double k);
double action(TFun f, double xmin, double xmax, int sh);

int main() {
	setlocale(LC_ALL, "RUS");

	while (1) {
		char o;

		double x1, x2, x3; // ���������� ��� ���������� �������
		int F;

		int menu;
		printf("\t\t\t����:\n\t1 - ��������� ��������;\n\t2 - ������������;\n\t3 - ��������� ��������;\n\t4 - ����� ����� ��������;\n\t");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: { // ��������� ��������� ������� ��� �������� ������������� ��������� (����� ���� ���������)
			printf("\n\t\t�������� �������:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x);\n\t");
			scanf_s("%d", &F); // ����� ������

			printf("������� �������� x1, x2 ��� ���������� �������:\n");
			printf("x1 (��������� ��������) = ");
			scanf_s("%lf", &x1);
			printf("\nx2 (�������� �������� > %lf) = ", x1); // ���� �������� ��� ����������
			scanf_s("%lf", &x2);
			double sh = 1.5; // ������������ ��� ���������

			switch (F) {
			case 1: {
				printf("\n\n������� y = log(abs(sqrt(x^3))):\n\n"); // ���� ������������ ������ ������ �������
				out_rez(fun1, x1, x2, sh);
				break;
			}
			case 2: { // ���� ������������ ������ ������ �������
				printf("\n\n������� y = sqrt(tan(x^2 - 1)) ��� (x>1) | y = -2x ��� (0<=x<=1)| y = exp(cos(x)) ��� (x<0) :\n\n");
				out_rez(fun2, x1, x2, sh);
				break;
			}
			case 3: { // ���� ������������ ������ ������ �������
				printf("\n\n������� y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), ��� s = (x - 1) / (x + 1) :\n\n");
				out_rez(fun3, x1, x2, sh);
				break;
			}
			default:
				printf("��������� ����������� ���������, ��������� �����...");
				break;
			}
			break;
		}
		case 2: { // // ��������� ��������� ������� ��� �������� ������������� ��������� (�������� �� -x1 �� x1 � ��� ���������)
			printf("\n\t\t�������� �������:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x); \n\t");
			scanf_s("%d", &F);

			printf("������� �������� ��������� � ��� ��������� ��� ���������� �������:\n");
			printf("dx (��������)");
			scanf_s("%lf", &x1);
			printf("\nx3 (��� ���������)= ");
			scanf_s("%lf", &x3);

			switch (F) {
			case 1: {
				printf("\n\n������� y = log(abs(sqrt(x^3))):\n\n"); // ���� ������������ ������ ������ �������
				out_rez(fun1, -x1, x1, x3);
				break;
			}
			case 2: { // ���� ������������ ������ ������ �������
				printf("\n\n������� y = sqrt(tan(x^2 - 1)) ��� (x>1) | y = -2x ��� (0<=x<=1)| y = exp(cos(x)) ��� (x<0) :\n\n");
				out_rez(fun2, -x1, x1, x3);
				break;
			}
			case 3: {
				printf("\n\n������� y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), ��� s = (x - 1) / (x + 1) :\n\n");
				out_rez(fun3, -x1, x1, x3);
				break;
			}
			default: // ���� ������������ ������ ������ �������
				printf("��������� ����������� ���������, ��������� �����...\n");
				break;
			}
			break;
		}
		case 3: { // ������� 7 - ������������ ���������� ���� ���������� � �������� �������
			printf("�������� 7-�� �������� - ������������ ���������� ������ ���������� � �������� �������\n\n");
			printf("\n\t\t�������� �������:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x);\n\t");
			scanf_s("%d", &F);

			printf("������� �������� x1, x2 ��� ���������� �������:\n");
			printf("x1 (��������� ��������) = ");
			scanf_s("%lf", &x1);
			printf("\nx2 (�������� �������� > %lf) = ", x1);
			scanf_s("%lf", &x2);
			printf("\nx3 (��� ���������)= ");
			scanf_s("%lf", &x3);
			int sh1 = (int)((x2 - x1) / x3); // ������� ����� ������ A ����� �����, ����������� �� ��������� � ������� ����

			double** A = (double**)malloc(sh1 * sizeof(double*)); // ��������� ������
			if (A == NULL) {
				puts("����������� ���������");
				return -1;
			}

			for (int i = 0; i < sh1; i++) {
				A[i] = (double*)malloc(sh1 * sizeof(double));
				if (A[i] == NULL) {
					puts("����������� ���������");
					return -1;
				}
			}

			switch (F) {
			case 1: { // ���� ������������ ������ ������ �������
				printf("\n\n������� y = log(abs(sqrt(x^3))):\n\n");
				for (int s = 0; s < sh1; s++) { // �� �������
					double x = x1 + s * x3;
					for (int k = 0; k < sh1; k++) { // �� ��������
						A[s][k] = fun1(x); // ������ ������� ������� ����������� ���������� �������
					}
				}
				print_array(A, sh1, sh1); // ����� �������
				for (int i = 0; i < sh1; i++) {
					free(A[i]); // ������������ ������
				}
				free(A);
				break;
			}
			case 2: { // ���� ������������ ������ ������ �������
				printf("\n\n������� y = sqrt(tan(x^2 - 1)) ��� (x>1) | y = -2x ��� (0<=x<=1)| y = exp(cos(x)) ��� (x<0) :\n\n");
				for (int s = 0; s < sh1; s++) { // �� �������
					double x = x1 + s * x3;
					for (int k = 0; k < sh1; k++) { // �� ��������
						A[s][k] = fun2(x);
					}
				}
				print_array(A, sh1, sh1); // ����� �������
				for (int i = 0; i < sh1; i++) {
					free(A[i]); // ������������ ������
				}
				free(A);
				break;
			}
			case 3: { // ���� ������������ ������ ������ �������
				printf("\n\n������� y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), ��� s = (x - 1) / (x + 1) :\n\n");
				for (int s = 0; s < sh1; s++) { // �� �������
					double x = x1 + s * x3;
					for (int k = 0; k < sh1; k++) { // �� ��������
						A[s][k] = fun3(x);
					}
				}
				print_array(A, sh1, sh1); // ����� �������
				for (int i = 0; i < sh1; i++) {
					free(A[i]); // ������������ ������
				}
				free(A);
				break;
			}
			default:
				printf("��������� ����������� ���������, ��������� �����...");
				break;
			}
			break;
		}
		case 4: { // ��  ������� 15 - ����� ����� ��������� ������� 
			printf("\n\t\t�������� �������:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x);\n\t");
			scanf_s("%d", &F);

			printf("������� �������� x1, x2 ��� ���������� ����� ��������� �������:\n");
			printf("x1 (��������� ��������) = ");
			scanf_s("%lf", &x1);
			printf("\nx2 (�������� �������� > %lf) = ", x1);
			scanf_s("%lf", &x2);
			printf("\nx3 (��� ���������)= ");
			scanf_s("%lf", &x3);
			switch (F) {
			case 1: {
				printf("\n\n������� y = log(abs(sqrt(x^3))):\n\n");
				printf("����� ��������� Y(x) = %lf", action(fun1, x1, x2, (int)x3));
				printf("\n");
				break;
			}
			case 2: {
				printf("\n\n������� y = sqrt(tan(x^2 - 1)) ��� (x>1) | y = -2x ��� (0<=x<=1)| y = exp(cos(x)) ��� (x<0) :\n\n");
				printf("����� ��������� V(x) = %lf", action(fun2, x1, x2, (int)x3));	
				printf("\n");
				break;
			}
			case 3: {
				printf("\n\n������� y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), ��� s = (x - 1) / (x + 1) :\n\n");
				printf("����� ��������� S(x) = %lf", action(fun3, x1, x2, (int)x3));
				printf("\n");
				break;
			}
			default:
				printf("��������� ����������� ���������, ��������� �����...");
				break;
			}
		}
		default:
			printf("��������� ����������� ���������, ��������� �����...");
			break;
		}
		printf("������� ����������? (�� - 'y' , ��� - 'n' \n"); // ����������� ��������� ���������
		scanf_s("%c", &o);
		if ((o = getchar()) == 'n') {
			break;
		}
		else if ((o = getchar()) == 'y') {
			system("pause");
		}
		printf("\n");
	}

	
}

double fun1(double x) { // ������ �������
	double Y;
	if (x > 0) {
		Y = log(fabs(sqrt(pow(x, 3))));
		return Y;
	}
	else {
		printf("��� ���������� ���� ������� x ������ ���� > 0\n");
		return Y = 0;
	}
}

double fun2(double x) { // ������ �������
	double V;
	if (x > 1) {
		V = sqrt(tan(pow(x, 2) - 1));
	}
	else if (x >= 0 && x <= 1) {
		V = -2 * x;
	}
	else if (x < 0) {
		V = exp(cos(x));
	}
	return V;
}

double fun3(double x) { // ������ �������
	double S;
	if (x == -1) {
		S = 0;
	}
	double s = (x - 1) / (x + 1);
	S = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7);
	return S;
}

void out_rez(TFun f, double xn, double xk, double h) { // ������� ������ ��������� � ��������
	for (double x = xn; x <= xk; x += h) {
		double y = f(x);
		printf("| %.2lf\t| %.2lf\t|\n", x, y);
		printf("-----------------\n");
	}
}

void print_array(double** arr, double s, double k) { // ����� ������� � ����������� �������
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < k; j++) {
			printf("%.2lf\t", arr[i][j]);
		}
		printf("\n");
	}
}

double action(TFun f, double xmin, double xmax, int sh) { // ���������� ����� ��������� �������
	double max = f(xmin); // ��������� �������� ��������� �������
	double tmax = 0; // ��� ��������� 

	for (double x = xmin; x <= xmax; x += sh) {
		double t = f(x); // �������� �� ������ �����
		if (t > max) { // ���������
			max = t;
			tmax = x;
		}
	}
	return tmax;
}