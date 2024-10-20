#include <stdio.h>
#include <locale.h>
#define ROW 9
#define COL 9

void main()
{
	setlocale(LC_ALL, "RUS");

	// задание 1.1
	int row, col; // объ€вление переменных

	printf("“аблица ѕифагора\n");
	printf("\n");

	for (row = 1; row <= ROW; ++row) { 
		for (col = 1; col <= COL; ++col)
		printf("%5d", col*row);
		printf("\n");
	}
	printf("\n");
	system("pause");
	printf("\n");

	// задание 1.2

	int row1, col1; // объ€вление переменных

	printf("Ћевый нижний угол таблицы ѕифагора\n");
	printf("\n");

	for (row1 = 1; row1 <= ROW; ++row1) {
		for (col1 = 1; col1 <= row1; ++col1) // мен€ем условие
			printf("%5d", col1 * row1);
		printf("\n");
	}
	printf("\n");
	system("pause");
	printf("\n");

	// задание 1.3 , вариант 15: напечатать полную таблицу сложени€

	int a, b; // объ€вление переменных

	printf("“аблица сложени€\n");
	printf("\n");

	for (a = 1; a <= ROW; ++a) {
		for (b = 1; b <= COL; ++b)
			printf("%d + %d = %d\t", a, b, (a + b));
		printf("\n");
	}
	printf("\n");
	system("pause");
	printf("\n");

	// задание 2
	int n;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n);
	printf("\n");
	int three = 0; // 1)
	while (n > 0) {
		
		int d = n % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d == 3) 
			three += 1; // счетчик кол-ва троек
		
		n /= 10;
	}
	printf("кол-во троек в введенном числе = %d\n", three); // кол-во троек в числе

	printf("\n");
	system("pause");
	printf("\n");

	int n1;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n1);
	printf("\n");

	int pov = 0; // 2)
	int ost = n1 % 10; // последн€€ цифра числа
	while (n1 > 0) {
		int d = n1 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d == ost) {
			pov += 1; // счетчик повторени€ последней цифры в числе
		}
		n1 /= 10;
	}
	printf("кол-во повторений последней цифры в введенном числе  = %d\n", pov); // кол-во повторений

	printf("\n");
	system("pause");
	printf("\n");

	int n2;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n2);
	printf("\n");

	int chet = 0; // 3)
	while (n2 > 0) {
		int d = n2 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d % 2 == 0) {
			chet += 1; // счетчик кол-ва четных цифр
		}
		n2 /= 10;
	}
	printf("кол-во четных цифр в введенном числе  = %d\n", chet); // кол-во четных цифр

	printf("\n");
	system("pause");
	printf("\n");

	int n3;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n3);
	printf("\n");

	int bol5 = 0; // 4)
	while (n3 > 0) {
		int d = n3 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d > 5) {
			bol5 += 1; // счетчик цифр, которые больше 5
		}
		n3 /= 10;
	}
	printf("кол-во цифр, которые больше 5, в введенном числе  = %d\n", bol5); // кол-во цифр больше 5

	printf("\n");
	system("pause");
	printf("\n");

	int n4;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n4);
	printf("\n");

	int nechet = 0; // 5)
	while (n4 > 0) {
		int d = n4 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d % 2 != 0) {
			nechet += d; // сумма нечетных чисел
		}
		n4 /= 10;
	}
	printf("—умма нечетных цифр в введенном числе  = %d\n", nechet); // сумма нечетных цифр

	printf("\n");
	system("pause");
	printf("\n");

	int n5;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n5);
	printf("\n");
	
	int sym7 = 0; // 6)
	while (n5 > 0) {
		int d = n5 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d >= 7) {
			sym7 += d; // сумма цифр, которые >=7
		}
		n5 /= 10;
	}
	printf("—умма цифр, которые больше или равны 7 в введенном числе  = %d\n", sym7); // сумма цифр >=7

	printf("\n");
	system("pause");
	printf("\n");

	int n6;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n6);
	printf("\n");

	int M = 1; // 7)
	while (n6 > 0) {
		int d = n6 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d != 0) {
			M *= d; // произведение всех цифр, кроме 0
		}
		n6 /= 10;
	}
	printf("ѕроизведение всех цифр числа, кроме 0 = %d\n", M); // произведение всех цифр

	printf("\n");
	system("pause");
	printf("\n");

	int n7;
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n7);
	printf("\n");

	int n0 = n7;
	int m1 = 0; // 8)
	int m2 = 0;
	int M1;
	int ost1 = n7 % 10;
	int dva = 0;
	while (n7 > 0) {
		int d = n7 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		n7 /= 10;
		dva += 1;
		if (dva == 2) { // втора€ цифра
			m1 += d;
		}
		if ((ost1) % 10 == d) {
			m2 += d; // предпосл цифра
		}
		M1 = m1 * m2;
	}
	printf("ѕроизведение второй и предпоследней цифр числа = %d\n", M1); // произведение второй и предпосл цифр

	printf("\n");
	system("pause");
	printf("\n");

	int n8; // 9)
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n8);
	printf("\n");

	int chet1 = 0;
	int v = 0;
	int ost2 = n8 % 10;
	n8 /= 10;

	while (n8 > 0) {
		int d = n8 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d % 2 == 0 && d != ost2) {
			chet1 += d;
		}
		n8 /= 10;
	}
	printf("—умма четных цифр числа, кроме последнего = %d\n", chet1); // сумма четных цифр без посл

	printf("\n");
	system("pause");
	printf("\n");

	int n9; // 10)
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n9);
	printf("\n");
	while (n9 > 0) {
		int d = n9 % 10; // последн€€ цифра числа
		printf("%d\n", d);
		if (d == (n9 / 10) % 10) {
			printf("–€дом расположенны две одинаковые цифры\n");
		}
		else {
			printf("Ќет двух одинаковых цифр, расположенных р€дом\n");
		}
		n9 /= 10;
	}

	printf("\n");
	system("pause");
	printf("\n");

	int n10; // 11)
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n10);
	printf("\n");
	int pol1 = 0; 
	int pol2 = 0;
	int ch = n10;
	int c = 0; // сколько всего цифр в числе
	while (n10 > 0) {
		n10 /= 10;
		c += 1;
	}
	for (int i = 0; i < c / 2; i++) {
		pol1 += ch % 10;
		ch /= 10;
	}

	for (int i = c / 2; i < c; i++) {
		pol2 += ch % 10;
		ch /= 10;
	}

	printf("—умма первой половины цифр = %d\n", pol1); // сумма первой половины
	printf("—умма второй половины цифр = %d\n", pol2); // сумма второй половины


	printf("\n");
	system("pause");
	printf("\n");

	int n11; // 12)
	printf("¬ведите произвольное целое число с клавиатуры...\n");
	scanf_s("%d", &n11);
	printf("\n");

	int ch1 = n11;
	int sumchet = 0;
	int sumnechet = 0;
	int p1 = 1; // разр€ды, начина€ с 1
	while (ch1 > 0) {
		int d = ch1 % 10;
		ch1 /= 10;
		if (p1 % 2 == 0){ // если разр€д четный
			sumchet += d;
		}
		else { // если нечетный
			sumnechet += d;
		}
		p1 += 1;
	}
	int M2 = sumchet * sumnechet;
	printf("—умма цифр четных разр€дов = %d, а цифр нечетных разр€дов = %d\n", sumchet, sumnechet); // суммы чет и нечет разр€дов
	printf("ѕроизведение сумм цифр четн и нечетн разр€дов = %d\n", M2); // произведение
}
