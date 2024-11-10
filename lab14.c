#include <stdio.h>
#include <locale.h>
#define N 30
#include <math.h>

// ������� ��� ���������� ������
double* full_elements(double* ptr_array, int n) { 

	double sh = (4. - 2) / (n - 1); // ���
	double x = 2.;

	for (int i = 0; i < n; i++) {
		ptr_array[i] = pow(x, 3) + 3 * pow(x, 2) - 3; // �� 2 ������� ���.8
		x += sh;
	}
	return ptr_array;
}

// ������� ������ ��������� �������
int put_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {

		printf("array[%2d] = %lf\n", i, ptr_array[i]);

	}

	return n;
}

// ������� ��������� ��������� ������� (��������� ������������� ���������)
double* calc_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {

		if (ptr_array[i] < 0) {
			ptr_array[i] = 0;
		}
	}
	return ptr_array;
}

// ������� ���������� ����� ��������� ������
double sum_elements(double* ptr_array, int begin, int end) {

	double sum = 0.0;

	for (int i = begin; i <= end; i++) {

		sum += ptr_array[i];

	}
	return sum;
}

// ������� ������ ��������
int find_element(double* ptr_array, int n, double element) {

	int i = 0;
	while (ptr_array[i] != element && i < n)
	{
		i++;//������� ���������
		if (ptr_array[i] == element) {
			return i;
		}
		else {
			return -1;
		}
	}
}
// ������� ����������� ������� ������������ �������� �������
int function(double* ptr_array, int n) {
	int min_index = 0;
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] < 0) {
			min_index = i;
		}
		return min_index;
	}
}
int main() {
	setlocale(LC_ALL, "RUS");

	// ������� 1

	double array[N];
	int size;
	printf("������� ������ �������(������, ��� %d)   ", N);
	scanf_s("%d", &size);
	
	full_elements(array, size);
	put_elements(array, size);

	// ������� 2
	int begin, end;
	printf("\n������� ��������� ������:   ");
	scanf_s("%d", &begin);

	printf("\n������� �������� ������:   ");
	scanf_s("%d", &end);

	printf("\n����� ��������� �������:  %lf", sum_elements(array, begin, end));

	double e;
	printf("\n\n������� ������� ��������:  ");
	scanf_s("%lf", &e);

	if (find_element(array, size, e)) {
		printf("\n\n������� �������� ��� �������� %d", find_element(array, size, e));
	}

	// ������� 3 - �� (������� 15)

	int min_index = function(array, size);
	if (min_index == 0) {
		printf("\n\n� ������ ��� ������������� ���������\n");
	}
}