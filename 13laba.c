#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

void main() {
	// ������� 1
	char Name[50];
	printf("What is your name?\n");
	gets(Name); // ��� ����� ����� � �������
	scanf_s("%s", Name);

	for (int i = 0; Name[i] != '\0'; i++) {
		Name[i] = toupper(Name[i]); // �������� ������-����� �� ���������
	}

	// ������� 2, ������� 15 - 12 = 3
	int l1 = strlen(Name); // ��������������� ������
	for (int i = 0; i < l1; i++) {
		if (i == 0) { // ��� ������ ����� �������� �������
			int j = Name[i];
			Name[i] = Name[i + 1];
			Name[i + 1] = j;
		}
	}

	char Snew[100] = "HELLO! ";
	strcat(Snew, Name); // �������� ���������� ������ � ������ � ������ � ������������
	printf("%s\n", Snew);
	int l = strlen(Snew); // ���������� ����� ������
	int kol_vo = 40 - l;

	for (int i = 0; i < kol_vo; i++) {
		strcat(Snew, "!"); // ���������� ��������� ��������� '!' ������
	}
	printf("%s\n", Snew);
}