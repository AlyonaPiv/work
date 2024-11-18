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
	printf("Введите количество строк: ");
	scanf_s("%d", &str);
	printf("Введите количество столбцов: ");
	scanf_s("%d", &stl);
	printf("\n");

	// задание 1

	if (!(str < N) || !(stl < N)) return;
	// Ввод элементов массива
	for (int i = 0; i < str; i++) { // цикл по строкам
		for (int j = 0; j < stl; j++) {// цикл по столбцам
			a[i][j] = i + 1.f * ((j + 1) - i) * rand() / RAND_MAX; // вар.5 заполнение случайным вещественным значением в интервале от порядкового номера строки до номера столбца + 1;
		}
	}
	// Вывод элементов массива
	for (int i = 0; i < str; i++) { // цикл по строкам
		for (int j = 0; j < stl; j++) { // цикл по столбцам
			printf("a[%d][%d] = %.2f ", i, j, a[i][j]); //
		}
		printf("\n");
	}
	printf("\n");
	// вывод любого элемента из второй строки, вар.5
	printf("Элемент из второй строки массива:   %.2f\n", a[1][0]);
	printf("\n");
	int S;
	printf("Введите номер столбца для поиска макс элемента (от 0 до %d):   ", (stl - 1));
	scanf_s("%d", &S);
	float max = a[0][S];
	for (int i = 1; i < str; i++) {
		if (a[i][S] > max) {
			max = a[i][S];
		}
	}
	printf("Максимальный элемент в столбце %d - %.2f ", S, max);
	printf("\n\n");
	// задание 2
	printf("Исходный масив: \n");
	int b[X][X];
	for (int i = 0; i < X; i++) { // цикл по строкам
		for (int j = 0; j < X; j++) {// цикл по столбцам
			b[i][j] = rand() % 21 - 10; // заполнение целыми числами от -10 до 10
		}
	}
	for (int i = 0; i < X; i++) { // вывод массива
		for (int j = 0; j < X; j++) {
			printf("%4d", b[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	printf("Транспонированный массив:  \n");
	int trans[X][X];
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			trans[i][j] = b[j][i];
		}
	}
	for (int i = 0; i < X; i++) { // вывод массива
		for (int j = 0; j < X; j++) {
			printf("%4d", trans[i][j]);
		}
		printf("\n");
	}

	int sumchet = 0;
	int k = 0;
	for (int i = 0; i < X; i++) {
		if (trans[i][2] % 2 == 0) {
			sumchet += trans[i][2]; // сумма четных элементов третьего столбца
			k++;
		}
	}
	int srznach = sumchet / k; // среднее значение
	printf("Сумма четных элементов третьего столбца = %d, количество элементов = %d, среднее значение суммы четн.эл = %d\n", sumchet, k, srznach);

	int k1 = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X - 1; j++) {
			if (trans[i][j] == trans[i][j+1]) {
				k1++;
			}
		}
	}
	printf(" Количество одинаковых пар элементов в  =  %d\n", k1);

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
	printf(" Максимально число = %d, координата по строчке = %d, координата по столбцу = %d\n\n", MAX, max_X, max_Y);
	printf("\tТаблица зарплат\n");

	// ДЗ вариант 15
	int ZP[CHEL][MES];
	int sum_zp = 0;
	zp(ZP);
	printf_zp(ZP);
	printf("\n\n");
	int mes;
	printf("Выберите месяц для нахождения средней зарплаты сотрудников (от 1 до 12):   ");
	scanf_s("%d", &mes);


	printf("\nЗа %d месяц среднее значение зарплаты = %d\n",mes, sumsrzn_zp(ZP, mes));
}
int zp(int ZP[CHEL][MES]) { // заполнение рандомными положительными числами
	for (int i = 0; i < CHEL; i++) {
		for (int j = 0; j < MES; j++) {
			ZP[i][j] = rand() % 1001;
		}
	}
	return 0;
}
int printf_zp(int ZP[CHEL][MES]) {
	printf(" | январь|февраль | март | апрель |  май  | июнь | июль | август | сентябрь|октябрь | ноябрь|декабрь |\n");
	for (int i = 0; i < CHEL; i++) { // вывод массива
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
	printf("Сумма зарплаты всех сотрудников за месяц = %d", sum);
	int srzn = sum / k2; // среднее значение
	return srzn;
}