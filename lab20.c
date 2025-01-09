#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");

	// ������� 1
	
    FILE* F;
    char fname[20] = "temp1.txt"; // ��� �����

    if ((F = fopen(fname, "r")) == NULL) {
        printf("������ �������� ����� ��� ������");
        return 0;
    }
    double a; // ��� �������� ���������� �����
    double sum = 0;
    int c = 0; // ������� �����
    while (!feof(F)) { // �������� �� ����� �����
        fscanf(F, "%lf", &a);
        sum += a;      // ���������� � �����
        c++;
    }
    fclose(F);
    double srznach = sum / c; // ���������� �������� ��������������� ��������
    printf("������� ��������������: %.2f\n", srznach);

    // ������� 2  15 - 12 = 3 �������

    char Name[256];
    FILE* out;
    printf("������� ��� �������� �����: ");
    fgets(Name, sizeof(Name), stdin); // ���������� ���������� �����

    for (int i = 0; Name[i] != '\0'; i++) { // ������ ������� ����� ������ �� ����-����������
        if (Name[i] == '\n') {
            Name[i] = '\0';
            break;
        }
    }

    out = fopen(Name, "r");  // �������� ���������� ����� ��� ������
    if (out == NULL) {
        printf("������");
        return 1;
    }

    // �������� ������ ����� �����
    char new_Name[256];
    snprintf(new_Name, sizeof(new_Name), "%sparity1.dat", Name);

    // �������� ����� ��� ������
    FILE* output;
    output = fopen(new_Name, "w");
    if (output == NULL) {
        printf("������");
        fclose(out);
        return 1;
    }
    double number;
    while (fscanf(out, "%lf", &number) != EOF) { // �������� �� ��, ��� ��������� ����� �����
        if (number > 0) {
            number /= 4.0; // ��������� ��� ������������� ����� � 4 ����.
        }
        fprintf(output, "%.2lf\n", number); // ���������� ��������� � �������� ����
    }

    fclose(out);
    fclose(output);

    printf("���������� �������� � ����: %s\n", new_Name);

    // ������� 3 ������� 15 (������ � ��������� ����� ��������� � ������)

    FILE* wint;
    char name[20] = "winter.txt"; // ��� �����

    if ((wint = fopen(name, "r")) == NULL) {
        printf("������ �������� ����� ��� ������");
        return 0;
    }

    FILE* wint_n;
    char NaMe[256];
    printf("������� �������� ������ �����:   ");
    fgets(NaMe, sizeof(NaMe), stdin);

    for (int i = 0; NaMe[i] != '\0'; i++) { // ������ ������� ����� ������ �� ����-����������
        if (NaMe[i] == '\n') {
            NaMe[i] = '\0';
            break;
        }
    }

    puts("�������� �����\n");
    wint_n = fopen(NaMe, "w");
    if (wint_n == NULL) {
        printf("������ �������� ����� ��� ������");
        return 0;
    }
    int word_c = 0; // ������� ���-�� ����
    char line[100]; // ��� �������� ����������� ������ �� �����
    char* words[100]; // ��� �������� ������� ������ ������� ����� �� �����

    // ������� �������� ��� ����� �� �����
    while (fgets(line, sizeof(line), wint) != NULL) { // ������ ������ �� ����� 'wint' � 'line' ���� �� ��������� ����� �����
        char* start = line; // ��������� �� ������ ������
        char* end; // ��������� �� ����� �����
        while (*start != '\0') {
            while (*start == ' ') {
                start++;
            }

            if (*start == '\0') {
                break; // ����� ������
            }
            end = start;
            while (*end != '\0' && *end != ' ') { // ���������� �� ������� ������ �� �� �����
                end++;
            }
            int len = end - start; // ����� ����� - ������� ����� �����������

            words[word_c] = (char*)malloc(sizeof(char) * (len + 1));

            if (words[word_c] == NULL) {
                perror("������ ��������� ������");
                fclose(wint);
                fclose(wint_n);
                return 1;
            }

            strncpy(words[word_c], start, len); // �������� ����� �� ������� ������� ������, �� ������ 'start', ������ 'len'
            words[word_c][len] = '\0'; // // ��������� ����-���������� � ����� �������������� �����
            word_c++;
            start = end; // ��� ���������� ������ �����
        }
    }
     
    // ����� �������� �����
    if (word_c != 0) {
        char m[1000] = ""; // ��� ����������� ������

        if (word_c >= 1) {
            sprintf(m, "(%s)", words[0]); // ����������� ������ 'm', �������� ������ ����� � ������

            for (int i = 1; i < word_c - 1; i++) { //  ���� for ��� ����������� �� ���� ������, ����� ������� � ����������
                strcat(m, " ");
                strcat(m, words[i]); // ��������� ������, ����� ����� � ������
            }

            strcat(m, " "); // ������ ����� ��������� ������
            char posl[50]; // ��� ���������� �����

            sprintf(posl, "(%s)", words[word_c - 1]);
            strcat(m, posl);

            fprintf(wint_n, "%s", m);

            for (int i = 0; i < word_c; i++) { // ������������ ������
                free(words[i]);
            }
        }
    }

    fclose(wint);
    fclose(wint_n);
    printf("\n��������� ����� �� ����� ����������!\n");
}