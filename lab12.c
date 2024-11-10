#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

main() {
	setlocale(LC_ALL, "RUS");

	// задание 1

	int* pi, i = 5;
	float* pf, f = 2.1f;
	double* pd, d = 3.55f;
	char* pc, c = '!';

	printf("Объем памяти под указатель на int = %lu\n", sizeof(pi));
	printf("Объем памяти под указатель на float = %lu\n", sizeof(pf));
	printf("Объем памяти под указатель на double = %lu\n", sizeof(pd)); //выделяется один и тот же объем памяти на указатели
	printf("Объем памяти под указатель на char = %lu\n", sizeof(pc));

	printf("\n");

	printf("Объем памяти под тип int = %lu\n", sizeof(i));
	printf("Объем памяти под тип float = %lu\n", sizeof(f));
	printf("Объем памяти под тип double = %lu\n", sizeof(d)); //выделяется разный объем памяти под тип данных
	printf("Объем памяти под тип char = %lu\n", sizeof(c));

	printf("\n");

	// задание 2

	float PI = 3.14159, *p1, *p2;
	p1 = p2 = &PI; // получение адреса переменной 

	printf("По адресу p1 = %p хранится *p1 = %g\n", p1, *p1);
	printf("По адресу p2 = %p хранится *p2 = %g\n", p2, *p2);

	printf("\n");

	// задание 3

	int* pa, x = 5; pa = &x;

	printf("По адресу %p хранится *ptr = %d\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr = %d\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr = %d\n", pa, *pa);

	printf("\n");

	double* pad, xd = 5.33f;
	pad = &xd;

	printf("По адресу %p хранится *ptr = %g\n", pad, *pad);
	pad++;
	printf("По адресу %p хранится *ptr = %.1g\n", pad, *pad);
	pad--;
	printf("По адресу %p хранится *ptr = %.1g\n", pad, *pad);

	printf("\n");

	char* pac, xc = '!';
	pac = &xc;

	printf("По адресу %p хранится *ptr = %c\n", pac, *pac);
	pac++;
	printf("По адресу %p хранится *ptr = %c\n", pac, *pac);
	pac--;
	printf("По адресу %p хранится *ptr = %c\n", pac, *pac);

	printf("\n");

	long double* pad1, xd1 = 5.44f;
	pad1 = &xd1;

	printf("По адресу %p хранится *ptr = %.1g\n", pad1, *pad1);
	pad1++;
	printf("По адресу %p хранится *ptr = %.1g\n", pad1, *pad1);
	pad1--;
	printf("По адресу %p хранится *ptr = %.1g\n", pad1, *pad1);

	printf("\n");

	short unsigned int* pasui, xsui = 2;
	pasui = &xsui;

	printf("По адресу %p хранится *ptr = %d\n", pasui, *pasui);
	pasui++;
	printf("По адресу %p хранится *ptr = %d\n", pasui, *pasui);
	pasui--;
	printf("По адресу %p хранится *ptr = %d\n", pasui, *pasui);

	printf("\n");

	_Bool* pab, xb = 1;
	pab = &xb;

	printf("По адресу %p хранится *ptr = %d\n", pab, *pab);
	pab++;
	printf("По адресу %p хранится *ptr = %d\n", pab, *pab);
	pab--;
	printf("По адресу %p хранится *ptr = %d\n", pab, *pab);

	printf("\n");

	// задание 4

	float array[10] = { 1.1, 2.2, 3.3, 4.4 , 5.5 , 6.6 , 7.7 , 8.8 , 9.9 , 10.10 };
	float* ptr_a, *ptr_b;
	ptr_a = &array[0];

	printf("%p \n%p \n%p \n\n", array, &array[0], &array);

	printf("%p , %1.f\n", ptr_a, *ptr_a);
	ptr_a++;
	printf("%p , %1.f\n", ptr_a, *ptr_a);
	ptr_a += 4;
	printf("%p , %1.f\n", ptr_a, *ptr_a);
	ptr_a -= 2;
	printf("%p , %1.f\n", ptr_a, *ptr_a);
	ptr_a = &array[0];

	printf("\n");

	for (int i = 0; i < 10; i += 2, ptr_a += 2) {
		printf("%1.f\n", *ptr_a);
	}

	printf("\n");

	for (ptr_a = &array[9], ptr_b = &array[-1]; ptr_a != ptr_b; ptr_a--) {
		printf("%.2f\n",*ptr_a);
	}

	printf("\n");

	// задание 5

	/* пример
	
	int x_1 = 0x12345678;
	int* prt; // указатель дл исследуемой переменной
	unsigned char* a1, * a2, * a3, * a4; // указатели на байты
	unsigned char* a0; // указатель на байт
	prt = &x_1; // получение адреса переменной

	a0 = (unsigned char*)prt;// преобразование типа для получения указателя на один байт

	a1 = a0 + 3; // 4-ый байт числа х_1
	a2 = a0 + 2; // 3-ий байт числа х_1
	a3 = a0 + 1; // 2-ой байт числа х_1
	a4 = a0; // 1-ый байт числа х_1

	printf("%.2x \n%.2x \n%.2x \n%.2x \n",*a1, *a2, *a3, *a4);
	*/

	int I = 12345;
	int* pI;
	unsigned char* i1, * i2, * i3, * i4; // указатели на байты
	unsigned char* i0; // указатель на байт

	//pI = &I; // получение адреса переменной
	i0 = (unsigned char*)&I; // преобразование типа для полчуние указателя на один байт

	i1 = i0 + 3; // 4-ый байт числа I
	i2 = i0 + 2; // 3-ий байт числа I
	i3 = i0 + 1; // 2-ой байт числа I
	i4 = i0; // 1-ый байт числа I

	printf("Тип данных int:  \n%.2x \n%.2x \n%.2x \n%.2x \n\n", *i1, *i2, *i3, *i4);

	float F = 12345.0;
	float* pF;
	unsigned char* f1, * f2, * f3, * f4; // указатели на байты
	unsigned char* f0; // указатель на байт

	//pF = &F; // получение адреса переменной
	f0 = (unsigned char*)&F; // преобразование типа для полчуние указателя на один байт

	f1 = f0 + 3; // 4-ый байт числа F
	f2 = f0 + 2; // 3-ий байт числа F
	f3 = f0 + 1; // 2-ой байт числа F
	f4 = f0; // 1-ый байт числа F

	printf("Тип данных float:  \n%.2x \n%.2x \n%.2x \n%.2x \n\n", *f1, *f2, *f3, *f4);

	double D = 12345.0;
	double* pD;
	unsigned char* d1, * d2, * d3, * d4, * d5, * d6, * d7, * d8; // указатели на байты
	unsigned char* d0; // указатель на байт

	//pD = &D; // получение адреса переменной
	d0 = (unsigned char*)&D; // преобразование типа для полчуние указателя на один байт

	d1 = d0 + 7; // 8-ой байт числа D
	d2 = d0 + 6; // 7-ой байт числа D
	d3 = d0 + 5; // 6-ый байт числа D
	d4 = d0 + 4; // 5-ый байт числа D
	d5 = d0 + 3; // 4-ый байт числа D
	d6 = d0 + 2; // 3-ий байт числа D
	d7 = d0 + 1; // 2-ой байт числа D
	d8 = d0; // 1-ый байт числа D

	printf("Тип данных double:  \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n\n", *d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8);
}