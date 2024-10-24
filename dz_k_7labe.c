#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "RUS");

	// вариант 15

	int m;
	puts("Введите кол-во месяцев...");
	scanf_s("%d", &m);
	switch (m)
	{
	case 0:
	case 1:
		printf("новорожденный\n");
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		printf("младенец\n");
		break;
	case 12:
	case 24:
		printf("раннее детство\n");
		break;
	case 36:
	case 48:
	case 60:
	case 72:
		printf("дошкольник\n");
		break;
	case 84:
	case 96:
	case 108:
	case 120:
	case 132:
	case 144:
		printf("школьник\n");
		break;
	case 156:
	case 168:
	case 180:
	case 192:
		printf("подросток\n");
		break;

	default:
		printf("от 17 лет и старше\n");
		break;

	}
}