//15 �������
#include <stdio.h>
#include <locale.h>
#include <math.h>
main()
{
	setlocale(LC_ALL, "RUS");
	float x = 2.444;
	//puts("������� �������� x...");
	//scanf_s("%f", &x);
	float y = 0.869 * (pow(10, -2));
	//puts("������� �������� y...");
	//scanf_s("%f", &y);
	float z = -0.13 * (pow(10, 3));
	//puts("������� �������� z...");
	//scanf_s("%f", &z);
	float h = (((pow(x, y +1) + exp(y - 1)) / (1 + (x * fabs(y - tan(z))))) * (1 + fabs(y - x))) + (((pow(fabs(y - x), 2)) / 2) - ((pow(fabs(y - x), 3)) / 3));
	printf("�����: %.5f", h);
}