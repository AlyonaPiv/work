#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

void main() {
	int dva = 0; //  счетчик слов
	int l = 0; // счетчик длины слов
	char str[100];
	printf("Enter the text...\n");
	fgets(str, 100, stdin); // для ввода строки с пробелами
	scanf_s("%s", str);

	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) { // если символ - буква, увеличивается счетчик длины слова
			l++;
		}
		else {
			if (l == 2) { // если слово состоит из двух букв - увеличиваем счетчик слов
				dva++;
				l = 0; // обнуляем счетчик длины после
			}
			else {
				if (l >= 2) { // если длина больше двух символов - обнуляем счетчик длины слова
					l = 0;
				}
			}
		}
	}
	
	printf("The numbers of two-letter words:  %d", dva);
}