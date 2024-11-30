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
	fgets(str, 100, stdin);
	scanf_s("%s", str);

	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			l++;
		}
		else {
			if (l == 2) {
				dva++;
				l = 0;
			}
			else {
				if (l >= 2) {
					l = 0;
				}
			}
		}
	}
	if (l == 2) {
		dva++;
	}
	printf("The numbers of two-letter words:  %d", dva);
}