//15 вариант
#include <stdio.h>
#include <locale.h>
#define AS 63240 // один световой год равен 63240 астрономичесих единиц

int svet(int sg)
{
	int res = sg * AS;
	return res;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int sg;
	puts("введите число");
	scanf_s("%d", &sg);
	printf("%d световых лет - это %d астрономических единиц", sg, svet(sg));
}