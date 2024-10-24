#include <stdio.h>
# include <locale.h>
#include <math.h>

main() {
	setlocale(LC_ALL, "RUS");

	// вариант 15

	int N;

	printf("введите целое число N\n");
	scanf_s("%d", &N);

	double p = 0, o = 0;

	for (int i = 1; i <= N; i++) {
		p += sin(i);
		o += 1 / p;
	}
	printf("%lf", o);
}