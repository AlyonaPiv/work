#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

void main() {
	// задание 1
	char Name[50];
	printf("What is your name?\n");
	gets(Name); // для ввода строк с консоли
	scanf_s("%s", Name);

	for (int i = 0; Name[i] != '\0'; i++) {
		Name[i] = toupper(Name[i]); // изменяет символ-букву на прописную
	}

	// задание 2, вариант 15 - 12 = 3
	int l1 = strlen(Name); // возвращаетдлину строки
	for (int i = 0; i < l1; i++) {
		if (i == 0) { // две первые буквы меняются местами
			int j = Name[i];
			Name[i] = Name[i + 1];
			Name[i + 1] = j;
		}
	}

	char Snew[100] = "HELLO! ";
	strcat(Snew, Name); // копирует содержимое строки с именем в строку с приветствием
	printf("%s\n", Snew);
	int l = strlen(Snew); // возвращает длину строки
	int kol_vo = 40 - l;

	for (int i = 0; i < kol_vo; i++) {
		strcat(Snew, "!"); // заполнение свободных элементов '!' знаком
	}
	printf("%s\n", Snew);
}