#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");

	// задание 1
	
    FILE* F;
    char fname[20] = "temp1.txt"; // имя файла

    if ((F = fopen(fname, "r")) == NULL) {
        printf("Ошибка открытия файла для чтения");
        return 0;
    }
    double a; // для хранения считанного числа
    double sum = 0;
    int c = 0; // Счетчик чисел
    while (!feof(F)) { // Проверка на конец файла
        fscanf(F, "%lf", &a);
        sum += a;      // добавление к сумме
        c++;
    }
    fclose(F);
    double srznach = sum / c; // Вычисление среднего арифметического значения
    printf("Среднее арифметическое: %.2f\n", srznach);

    // задание 2  15 - 12 = 3 вариант

    char Name[256];
    FILE* out;
    printf("Введите имя входного файла: ");
    fgets(Name, sizeof(Name), stdin); // считывание введенного имени

    for (int i = 0; Name[i] != '\0'; i++) { // замена символа новой строки на нуль-терминатор
        if (Name[i] == '\n') {
            Name[i] = '\0';
            break;
        }
    }

    out = fopen(Name, "r");  // Открытие начального файла для чтения
    if (out == NULL) {
        printf("Ошибка");
        return 1;
    }

    // Создание нового имени файла
    char new_Name[256];
    snprintf(new_Name, sizeof(new_Name), "%sparity1.dat", Name);

    // Открытие файла для записи
    FILE* output;
    output = fopen(new_Name, "w");
    if (output == NULL) {
        printf("Ошибка");
        fclose(out);
        return 1;
    }
    double number;
    while (fscanf(out, "%lf", &number) != EOF) { // проверка на то, что достигнут конец файла
        if (number > 0) {
            number /= 4.0; // Уменьшаем все положительные числа в 4 раза.
        }
        fprintf(output, "%.2lf\n", number); // Записываем результат в выходной файл
    }

    fclose(out);
    fclose(output);

    printf("Результаты записаны в файл: %s\n", new_Name);

    // задание 3 вариант 15 (Первое и последнее слово заключить в скобки)

    FILE* wint;
    char name[20] = "winter.txt"; // имя файла

    if ((wint = fopen(name, "r")) == NULL) {
        printf("Ошибка открытия файла для чтения");
        return 0;
    }

    FILE* wint_n;
    char NaMe[256];
    printf("Введите название нового файла:   ");
    fgets(NaMe, sizeof(NaMe), stdin);

    for (int i = 0; NaMe[i] != '\0'; i++) { // замена символа новой строки на нуль-терминатор
        if (NaMe[i] == '\n') {
            NaMe[i] = '\0';
            break;
        }
    }

    puts("Создание файла\n");
    wint_n = fopen(NaMe, "w");
    if (wint_n == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    int word_c = 0; // счетчик кол-ва слов
    char line[100]; // для хранения прочитанной строки из файла
    char* words[100]; // для хранения адресов начала каждого слова из файла

    // сначала получаем все слова из файла
    while (fgets(line, sizeof(line), wint) != NULL) { // читаем строки из файла 'wint' в 'line' пока не достигнем конца файла
        char* start = line; // указатель на начало строки
        char* end; // указатель на конец слова
        while (*start != '\0') {
            while (*start == ' ') {
                start++;
            }

            if (*start == '\0') {
                break; // Конец строки
            }
            end = start;
            while (*end != '\0' && *end != ' ') { // проходимся по текущей строке до ее конца
                end++;
            }
            int len = end - start; // длина слова - разница между указателями

            words[word_c] = (char*)malloc(sizeof(char) * (len + 1));

            if (words[word_c] == NULL) {
                perror("Ошибка выделения памяти");
                fclose(wint);
                fclose(wint_n);
                return 1;
            }

            strncpy(words[word_c], start, len); // Копирует слово из текущей позиции строки, по адресу 'start', длиной 'len'
            words[word_c][len] = '\0'; // // Добавляет нуль-терминатор в конец скопированного слова
            word_c++;
            start = end; // для следующего поиска слова
        }
    }
     
    // затем изменяем слова
    if (word_c != 0) {
        char m[1000] = ""; // для измененного текста

        if (word_c >= 1) {
            sprintf(m, "(%s)", words[0]); // Форматируем строку 'm', заключив первое слово в скобки

            for (int i = 1; i < word_c - 1; i++) { //  Цикл for для прохождения по всем словам, кроме первого и последнего
                strcat(m, " ");
                strcat(m, words[i]); // добавляет пробел, затем слово в массив
            }

            strcat(m, " "); // пробел перед последним словом
            char posl[50]; // для последнего слова

            sprintf(posl, "(%s)", words[word_c - 1]);
            strcat(m, posl);

            fprintf(wint_n, "%s", m);

            for (int i = 0; i < word_c; i++) { // освобождение памяти
                free(words[i]);
            }
        }
    }

    fclose(wint);
    fclose(wint_n);
    printf("\nПроверьте файлы на своем компьютере!\n");
}