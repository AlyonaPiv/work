#include <stdio.h>
#include <locale.h>
#include <math.h>

main() {
	setlocale(LC_ALL, "RUS");

	// ������� 3 (�������) , 3 �������

	int a, b;
	char si;
	while (1)
	{
		char l;
		// ������� �������� ������

		printf("������� ������ ����� �������������� ������������: \n");
		scanf_s("%d", &a);
		printf("������� ������ ����� �������������� ������������: \n");
		scanf_s("%d", &b);
		printf("������� ����� ������: \n");
		scanf_s("%c", &si);
		si = getchar();
		printf("\n");
		double c = sqrt(pow(a, 2) + pow(b, 2)); //���������� ������������
		for (int i = 0; i < a; i++) {
			for (int j = 0; j <= i; j++) {
				if (j <= c) {
					printf("%c", si);
				}
			}
			printf("\n");
		}
		printf("\n");
		printf("���������� ? (�� - y, ��� - n)\n");
		if ((l = getchar()) == 'n') break;

	}
}