#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define SIZE 6

// ��� 3 ������� 
// ��� �� ���������� ���������� ���� gryzovik
typedef struct gryzovik {
	char marka[50];
	char proizvoditel[100];
	float gr_pod;
	int year_vipysk;
	int data_registr;
} GR;

int randomNumber(int min, int max);                            // ��������� ��������� �����
void random_strin(char* str, const char* arr[], int arr_size); // ��������� �����/�������������� ����������
void fill_array(GR gr_ik[], int size);                         // ���������� ������� ���������� ����������
int writefile(char* fname, GR* gr_ik, int size);			   // ������ ����� ��������� � ����

int main() {
	setlocale(LC_ALL, "RUS");

	// ������� 1

	char fname[20] = "number.txt"; // ��� �����
	FILE* out; // ���� �����
	puts("�������� �����\n");
	if ((out = fopen(fname, "wt")) == NULL) {
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	/* ������ ������ � ������ */
	fprintf(out, "%d", 5); // ���� ����� 5 � ����
	fclose(out); // ������� ����

	if ((out = fopen(fname, "a")) == NULL) {
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	//* ������ ������ � ������ */
	fprintf(out, "\n%.2f", 12.56); // ���� ����� 5 � ����
	//* ����� ������ � ������ */
	fclose(out); // ������� ����
	printf("��������� ������� ����� � ���������� � ��� ������!\n");

	// ������� 2

	int sh1; // ���

	printf("\n������� y = x^3 + 3*x^2 - 3 \n\n");
	printf("������� �������� ��� ���������� ����\n\n");
	scanf_s("%d", &sh1); //���� ���� ���������

	double sh = (4. - 2) / (sh1- 1);
	double x = 2.;

	for (int i = 0; i < sh1; i++) {
		double y = pow(x, 3) + 3 * pow(x, 2) - 3; // �� 2-�� ������� ���.8
		x += sh;
		printf("|  %.2lf\t|  %.lf\t|\n", x, y);
		printf("-----------------\n");
	}

	char fname1[20] = "temp.txt"; // ��� �����
	FILE* zadanie2; // ���� �����
	
	int V;
	printf("�������� ��������� ������������� �������: \n\t1 - � ����� ����;\n\t2 - �������� � ������������\n");
	scanf_s("%d", &V);
	switch (V) {
	case 1:
		puts("�������� ������ �����, ����������, ��������� ���� ���������");
		
		if ((zadanie2 = fopen(fname1, "wt")) == NULL) {
			printf("������ �������� ����� ��� ������");
			return 0;
		}

		for (int i = 0; i < sh1; i++) {
			double y = pow(x, 3) + 3 * pow(x, 2) - 3; // �� 2-�� ������� ���.8
			x += sh;
			fprintf(zadanie2,"|  %.2lf\t|  %.2lf  |\n", x, y);
			fprintf(zadanie2,"--------------------\n");
		}
		
		fclose(zadanie2); // ������� ����
		break;
	case 2:
		puts("���������� � ������������ ����!");
		if ((out = fopen(fname, "a")) == NULL) {
			printf("������ �������� ����� ��� ������");
			return 0;
		}
		
		for (int i = 0; i < sh1; i++) {
			double y = pow(x, 3) + 3 * pow(x, 2) - 3; // �� 2-�� ������� ���.8
			x += sh;
			fprintf(out, "\n|  %.2lf\t|  %.2lf  |", x, y);
			fprintf(out, "\n--------------------");
		}
		fclose(out);
		break;
	default:
		printf("\n��������� ����������� ���������, ��������� �����...");
		break;
	}

	// ������� 3

	srand(time(NULL));  // ������������� ���������� ��������� �����
	char fname2[100] = "gryzoviki.txt";
	
	printf("\n\t\t������ '��������' : \n");

	GR* gr = (GR*)malloc(SIZE * sizeof(GR));
	if (gr == NULL) {
		printf("������ ��������� ������");
		return 1;  // �������� �� �������� ��������� ������
	}
	fill_array(gr, SIZE);
	writefile(fname2, gr, SIZE);

	printf("\n\t��������, ��������� ���� 'gryzoviki.txt' \n");
	free(gr);  // ����������� ���������� ������
}

// ��������� ��������� �����
int randomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}



// ��������� ��������� �����/�������������� ����������
void random_strin(char* str, const char* arr[], int arr_size) {
	int index = rand() % arr_size;
	strcpy(str, arr[index]);
}

// ������������� ������� �������� � ���������� ����������
void fill_array(GR gr_ik[], int size) {
	const char* marka[] = { "Mercedes Atego", "Mitsubishi F F", "N", "KamAZ-43118", "Y20�40", "MAZ-6501" };
	const char* proizvoditel[] = { "Mercedes - Benz", "Mitsubishi", "Isuzu", "KamAZ", "Toyota", "MAZ" };

	for (int i = 0; i < size; i++) {
		random_strin(gr_ik[i].marka, marka, (sizeof(marka) / sizeof(marka[0])));
		random_strin(gr_ik[i].proizvoditel, proizvoditel, (sizeof(proizvoditel) / sizeof(proizvoditel[0])));
		gr_ik[i].gr_pod = randomNumber(1, 25);
		gr_ik[i].year_vipysk = randomNumber(1959, 2008);
		gr_ik[i].data_registr = randomNumber(2000, 2024);
	}
}

int writefile(char* fname, GR* gr_ik, int size) {
	FILE* gruz_ik = fopen(fname,"wt");
	if (gruz_ik == NULL) {
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	
	fprintf(gruz_ik, "__________________________________________________________________________________\n");
	fprintf(gruz_ik, "| �����\t| �������������\t| ����������������\t| ��� �������\t| ���� �����������\t|\n");
	fprintf(gruz_ik, "----------------------------------------------------------------------------------\n");

	for (int i = 0; i < size; i++) {
		fprintf(gruz_ik, "| %15s | %15s | %10.2f | %10d | %10d |\n", gr_ik[i].marka, gr_ik[i].proizvoditel, gr_ik[i].gr_pod, gr_ik[i].year_vipysk, gr_ik[i].data_registr); // ������ ����� ���������
	}
	fclose(gruz_ik);
	return 1;
}
