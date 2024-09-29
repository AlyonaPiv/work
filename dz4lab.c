//15 вариант
#include <stdio.h>
#include <locale.h>

int s(int D, int L)
{
	int  S = (D * L);
	return S;
}

int money(int D, int L, int X)
{
	int dG = (D * L * X);
	return dG;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int L, D, X;
	puts("Введите длину полотна...");
	scanf_s("%d", &D);
	puts("Введите ширину полотна...");
	scanf_s("%d", &L);
	puts("Введите стоимость за один погонный метр полотна...");
	scanf_s("%d", &X);
	printf("За %d погонных метров Грей заплатит %d золотых монет", s(D,L), money(D,L,X));
}