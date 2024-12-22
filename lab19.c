#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define SIZE 6

// для 3 задания 
// для дз объявление переменных типа gryzovik
typedef struct gryzovik {
	char marka[50];
	char proizvoditel[100];
	float gr_pod;
	int year_vipysk;
	int data_registr;
} GR;

int randomNumber(int min, int max);                            // Генерация случайных чисел
void random_strin(char* str, const char* arr[], int arr_size); // Генерация марок/производителей грузовиков
void fill_array(GR gr_ik[], int size);                         // Наполнение массива рандомными значениями
int writefile(char* fname, GR* gr_ik, int size);			   // Запись полей структуры в файл

int main() {
	setlocale(LC_ALL, "RUS");

	// задание 1

	char fname[20] = "number.txt"; // имя файла
	FILE* out; // файл чисел
	puts("Создание файла\n");
	if ((out = fopen(fname, "wt")) == NULL) {
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	/* Начало работы с файлом */
	fprintf(out, "%d", 5); // ввод числа 5 в файл
	fclose(out); // закрыть файл

	if ((out = fopen(fname, "a")) == NULL) {
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	//* Начало работы с файлом */
	fprintf(out, "\n%.2f", 12.56); // ввод числа 5 в файл
	//* Конец работы с файлом */
	fclose(out); // закрыть файл
	printf("Проверьте наличие файла и записанные в нем данные!\n");

	// задание 2

	int sh1; // шаг

	printf("\nФункция y = x^3 + 3*x^2 - 3 \n\n");
	printf("Введите параметр для вычисления шага\n\n");
	scanf_s("%d", &sh1); //ввод шага табуляции

	double sh = (4. - 2) / (sh1- 1);
	double x = 2.;

	for (int i = 0; i < sh1; i++) {
		double y = pow(x, 3) + 3 * pow(x, 2) - 3; // из 2-го задания лаб.8
		x += sh;
		printf("|  %.2lf\t|  %.lf\t|\n", x, y);
		printf("-----------------\n");
	}

	char fname1[20] = "temp.txt"; // имя файла
	FILE* zadanie2; // файл чисел
	
	int V;
	printf("Записать результат табулирования функции: \n\t1 - в новый файл;\n\t2 - дозапись в существующий\n");
	scanf_s("%d", &V);
	switch (V) {
	case 1:
		puts("Создание нового файла, пожалуйста, проверьте свой компьютер");
		
		if ((zadanie2 = fopen(fname1, "wt")) == NULL) {
			printf("Ошибка открытия файла для записи");
			return 0;
		}

		for (int i = 0; i < sh1; i++) {
			double y = pow(x, 3) + 3 * pow(x, 2) - 3; // из 2-го задания лаб.8
			x += sh;
			fprintf(zadanie2,"|  %.2lf\t|  %.2lf  |\n", x, y);
			fprintf(zadanie2,"--------------------\n");
		}
		
		fclose(zadanie2); // закрыть файл
		break;
	case 2:
		puts("Добавление в существующий файл!");
		if ((out = fopen(fname, "a")) == NULL) {
			printf("Ошибка открытия файла для записи");
			return 0;
		}
		
		for (int i = 0; i < sh1; i++) {
			double y = pow(x, 3) + 3 * pow(x, 2) - 3; // из 2-го задания лаб.8
			x += sh;
			fprintf(out, "\n|  %.2lf\t|  %.2lf  |", x, y);
			fprintf(out, "\n--------------------");
		}
		fclose(out);
		break;
	default:
		printf("\nПроизошли технические неполадки, повторите снова...");
		break;
	}

	// задание 3

	srand(time(NULL));  // Инициализация генератора случайных чисел
	char fname2[100] = "gryzoviki.txt";
	
	printf("\n\t\tЗапись 'Грузовик' : \n");

	GR* gr = (GR*)malloc(SIZE * sizeof(GR));
	if (gr == NULL) {
		printf("Ошибка выделения памяти");
		return 1;  // Проверка на успешное выделение памяти
	}
	fill_array(gr, SIZE);
	writefile(fname2, gr, SIZE);

	printf("\n\tПожауста, проверьте файл 'gryzoviki.txt' \n");
	free(gr);  // Освобождаем выделенную память
}

// Генерация случайных чисел
int randomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}



// Генерация случайных марок/производителей грузовиков
void random_strin(char* str, const char* arr[], int arr_size) {
	int index = rand() % arr_size;
	strcpy(str, arr[index]);
}

// Инициализация массива записями с случайными значениями
void fill_array(GR gr_ik[], int size) {
	const char* marka[] = { "Mercedes Atego", "Mitsubishi F F", "N", "KamAZ-43118", "Y20–40", "MAZ-6501" };
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
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	
	fprintf(gruz_ik, "__________________________________________________________________________________\n");
	fprintf(gruz_ik, "| Марка\t| Производитель\t| Грузоподъемность\t| Год выпуска\t| Дата регистрации\t|\n");
	fprintf(gruz_ik, "----------------------------------------------------------------------------------\n");

	for (int i = 0; i < size; i++) {
		fprintf(gruz_ik, "| %15s | %15s | %10.2f | %10d | %10d |\n", gr_ik[i].marka, gr_ik[i].proizvoditel, gr_ik[i].gr_pod, gr_ik[i].year_vipysk, gr_ik[i].data_registr); // Запись полей структуры
	}
	fclose(gruz_ik);
	return 1;
}
