#include <stdio.h>
#include <locale.h>
#define N 10

main() {
	setlocale(LC_ALL, "RUS");

	int A[N];

	int temp;

	for (int i = 0; i < 10; i++) {
		printf("a[%d] = ", i);
		scanf_s("%d", &temp);
		A[i] = temp;
	}

	printf("\n");

	int sum = 0;
	int max = A[0];
	int max_index;

	for (int i = 1; i < N; i++) {
		if (A[i] > max) {
			max = A[i];
			max_index = i;
		}
	}

	for (int i = max_index + 1; i < N; i++) {
		sum += i;
	}

	printf("Сумма порядковых номеров элементов масива после максимального элемента массива = %d", sum);
}