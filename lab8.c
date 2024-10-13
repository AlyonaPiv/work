#include <stdio.h>
#include <locale.h>
#include <math.h>

double main(void)
{
	setlocale(LC_ALL, "RUS");
	// задание 1

	int m, n, i, S = 0, k = 0;

    printf("Введите начальное значение m: ");
    scanf_s("%d", &m);
    printf("Введите конечное значение n: ");
    scanf_s("%d", &n);
    for (i = m; i >= n; i--) {
        S += i;
        k += 1;
    }
    printf("Выполнено %d раз\n", k);
    printf("Сумма чисел от %d до %d равна: %d\n", m, n, S);

    // задание 2, вариант 15-12 = 3

    double a, b, result, x;
    double step;
    printf("Функция 1,8x^2 - sin10x \n");
    printf("Введите начальное значение x: ");
    scanf_s("%lf", &a);
    printf("Введите конечное значение x: ");
    scanf_s("%lf", &b);
    printf("шаг: ");
    scanf_s("%lf", &step);
    for (x = a; x <= b; x += step) {
        result = 1,8 * pow(x, 2) - sin(10*x);
        printf(" ---------------\n");
        printf("| %.2lf | %.2lf |\n", x, result);
        printf(" ---------------\n");

    }

    // задание 3, 15 вариант

    double res1 = 1.0, res2 = 1.0, o;
    printf("Введите N: ");
    scanf_s("%lf", &x);
    for (o = 1; o <= 63; o += 2) {
        res1 *= (x - o);
    }
    for (int i = 0; i <= 6; i++) {
        res2 *= (x - (pow(2, i)));
    }
    double res = res1 / res2;
    printf("%lf", res);
}