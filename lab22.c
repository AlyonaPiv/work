#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*TFun)(double); // объявление типа указателя на функци.

double fun1(double); // объявление прототипов функций
double fun2(double);
double fun3(double);
void out_rez(TFun, double, double, double);
void print_array(double** arr, double s, double k);
double action(TFun f, double xmin, double xmax, int sh);

int main() {
	setlocale(LC_ALL, "RUS");

	while (1) {
		char o;

		double x1, x2, x3; // переменные для вычисления функций
		int F;

		int menu;
		printf("\t\t\tМеню:\n\t1 - Вычислить значение;\n\t2 - Табулировать;\n\t3 - Выполнить операцию;\n\t4 - Найти точку максимма;\n\t");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: { // вычеслить результат функции при заданных пользователем значениях (кроме шага табуляции)
			printf("\n\t\tВыберите функцию:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x);\n\t");
			scanf_s("%d", &F); // выбор фукции

			printf("Введите значения x1, x2 для вычисления функций:\n");
			printf("x1 (начальное значение) = ");
			scanf_s("%lf", &x1);
			printf("\nx2 (конечное значение > %lf) = ", x1); // ввод значений для вычисления
			scanf_s("%lf", &x2);
			double sh = 1.5; // произвольный шаг табуляции

			switch (F) {
			case 1: {
				printf("\n\nФункция y = log(abs(sqrt(x^3))):\n\n"); // если пользователь выбрал первую функцию
				out_rez(fun1, x1, x2, sh);
				break;
			}
			case 2: { // если пользователь выбрал вторую функцию
				printf("\n\nФункция y = sqrt(tan(x^2 - 1)) при (x>1) | y = -2x при (0<=x<=1)| y = exp(cos(x)) при (x<0) :\n\n");
				out_rez(fun2, x1, x2, sh);
				break;
			}
			case 3: { // если пользователь выбрал третью функцию
				printf("\n\nФункция y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), при s = (x - 1) / (x + 1) :\n\n");
				out_rez(fun3, x1, x2, sh);
				break;
			}
			default:
				printf("Произошли технические неполадки, повторите снова...");
				break;
			}
			break;
		}
		case 2: { // // вычеслить результат функции при заданных пользователем значениях (диапазон от -x1 до x1 и шаг табуляции)
			printf("\n\t\tВыберите функцию:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x); \n\t");
			scanf_s("%d", &F);

			printf("Введите значение интервала и шаг табуляции для вычисления функций:\n");
			printf("dx (диапазон)");
			scanf_s("%lf", &x1);
			printf("\nx3 (шаг табуляции)= ");
			scanf_s("%lf", &x3);

			switch (F) {
			case 1: {
				printf("\n\nФункция y = log(abs(sqrt(x^3))):\n\n"); // если пользователь выбрал первую функцию
				out_rez(fun1, -x1, x1, x3);
				break;
			}
			case 2: { // если пользователь выбрал вторую функцию
				printf("\n\nФункция y = sqrt(tan(x^2 - 1)) при (x>1) | y = -2x при (0<=x<=1)| y = exp(cos(x)) при (x<0) :\n\n");
				out_rez(fun2, -x1, x1, x3);
				break;
			}
			case 3: {
				printf("\n\nФункция y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), при s = (x - 1) / (x + 1) :\n\n");
				out_rez(fun3, -x1, x1, x3);
				break;
			}
			default: // если пользователь выбрал третью функцию
				printf("Произошли технические неполадки, повторите снова...\n");
				break;
			}
			break;
		}
		case 3: { // Вариант 7 - сформировать двухмерный маив аргументов и значений функции
			printf("Операция 7-го варианта - сформировать двухмерный массив аргументов и значений функции\n\n");
			printf("\n\t\tВыберите функцию:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x);\n\t");
			scanf_s("%d", &F);

			printf("Введите значения x1, x2 для вычисления функций:\n");
			printf("x1 (начальное значение) = ");
			scanf_s("%lf", &x1);
			printf("\nx2 (конечное значение > %lf) = ", x1);
			scanf_s("%lf", &x2);
			printf("\nx3 (шаг табуляции)= ");
			scanf_s("%lf", &x3);
			int sh1 = (int)((x2 - x1) / x3); // сколько строк массив A будет иметь, основываясь на диапазоне и размере шага

			double** A = (double**)malloc(sh1 * sizeof(double*)); // выделение памяти
			if (A == NULL) {
				puts("Технические неполадки");
				return -1;
			}

			for (int i = 0; i < sh1; i++) {
				A[i] = (double*)malloc(sh1 * sizeof(double));
				if (A[i] == NULL) {
					puts("Технические неполадки");
					return -1;
				}
			}

			switch (F) {
			case 1: { // если пользователь выбрал первую функцию
				printf("\n\nФункция y = log(abs(sqrt(x^3))):\n\n");
				for (int s = 0; s < sh1; s++) { // по строкам
					double x = x1 + s * x3;
					for (int k = 0; k < sh1; k++) { // по столбцам
						A[s][k] = fun1(x); // каждый элемент массива заполняется значениями функции
					}
				}
				print_array(A, sh1, sh1); // вывод массива
				for (int i = 0; i < sh1; i++) {
					free(A[i]); // освобождение памяти
				}
				free(A);
				break;
			}
			case 2: { // если пользователь выбрал вторую функцию
				printf("\n\nФункция y = sqrt(tan(x^2 - 1)) при (x>1) | y = -2x при (0<=x<=1)| y = exp(cos(x)) при (x<0) :\n\n");
				for (int s = 0; s < sh1; s++) { // по строкам
					double x = x1 + s * x3;
					for (int k = 0; k < sh1; k++) { // по столбцам
						A[s][k] = fun2(x);
					}
				}
				print_array(A, sh1, sh1); // вывод массива
				for (int i = 0; i < sh1; i++) {
					free(A[i]); // освобождение памяти
				}
				free(A);
				break;
			}
			case 3: { // если пользователь выбрал третью функцию
				printf("\n\nФункция y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), при s = (x - 1) / (x + 1) :\n\n");
				for (int s = 0; s < sh1; s++) { // по строкам
					double x = x1 + s * x3;
					for (int k = 0; k < sh1; k++) { // по столбцам
						A[s][k] = fun3(x);
					}
				}
				print_array(A, sh1, sh1); // вывод массива
				for (int i = 0; i < sh1; i++) {
					free(A[i]); // освобождение памяти
				}
				free(A);
				break;
			}
			default:
				printf("Произошли технические неполадки, повторите снова...");
				break;
			}
			break;
		}
		case 4: { // ДЗ  вариант 15 - найти точку максимума функции 
			printf("\n\t\tВыберите функцию:\n\t1 - Y(x);\n\t2 - V(x);\n\t3 - S(x);\n\t");
			scanf_s("%d", &F);

			printf("Введите значения x1, x2 для вычисления точки максимума функций:\n");
			printf("x1 (начальное значение) = ");
			scanf_s("%lf", &x1);
			printf("\nx2 (конечное значение > %lf) = ", x1);
			scanf_s("%lf", &x2);
			printf("\nx3 (шаг табуляции)= ");
			scanf_s("%lf", &x3);
			switch (F) {
			case 1: {
				printf("\n\nФункция y = log(abs(sqrt(x^3))):\n\n");
				printf("Точка максимума Y(x) = %lf", action(fun1, x1, x2, (int)x3));
				printf("\n");
				break;
			}
			case 2: {
				printf("\n\nФункция y = sqrt(tan(x^2 - 1)) при (x>1) | y = -2x при (0<=x<=1)| y = exp(cos(x)) при (x<0) :\n\n");
				printf("Точка максимума V(x) = %lf", action(fun2, x1, x2, (int)x3));	
				printf("\n");
				break;
			}
			case 3: {
				printf("\n\nФункция y = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7), при s = (x - 1) / (x + 1) :\n\n");
				printf("Точка максимума S(x) = %lf", action(fun3, x1, x2, (int)x3));
				printf("\n");
				break;
			}
			default:
				printf("Произошли технические неполадки, повторите снова...");
				break;
			}
		}
		default:
			printf("Произошли технические неполадки, повторите снова...");
			break;
		}
		printf("Желаете продолжить? (Да - 'y' , Нет - 'n' \n"); // возможность закончить программу
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

double fun1(double x) { // первая функция
	double Y;
	if (x > 0) {
		Y = log(fabs(sqrt(pow(x, 3))));
		return Y;
	}
	else {
		printf("Для выполнения этой функции x должен быть > 0\n");
		return Y = 0;
	}
}

double fun2(double x) { // вторая функция
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

double fun3(double x) { // третья функция
	double S;
	if (x == -1) {
		S = 0;
	}
	double s = (x - 1) / (x + 1);
	S = s + (1.0 / 3.0) * pow(s, 3) + (1.0 / 5.0) * pow(s, 5) + (1.0 / 7.0) * pow(s, 7);
	return S;
}

void out_rez(TFun f, double xn, double xk, double h) { // функция печати аргумента и значения
	for (double x = xn; x <= xk; x += h) {
		double y = f(x);
		printf("| %.2lf\t| %.2lf\t|\n", x, y);
		printf("-----------------\n");
	}
}

void print_array(double** arr, double s, double k) { // вывод массива с результатом функции
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < k; j++) {
			printf("%.2lf\t", arr[i][j]);
		}
		printf("\n");
	}
}

double action(TFun f, double xmin, double xmax, int sh) { // определяет точку максимума функции
	double max = f(xmin); // начальное значение максимума функции
	double tmax = 0; // для сравнения 

	for (double x = xmin; x <= xmax; x += sh) {
		double t = f(x); // значение на каждой точке
		if (t > max) { // сравнение
			max = t;
			tmax = x;
		}
	}
	return tmax;
}