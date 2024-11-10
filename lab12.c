#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

main() {
	setlocale(LC_ALL, "RUS");

	// ������� 1

	int* pi, i = 5;
	float* pf, f = 2.1f;
	double* pd, d = 3.55f;
	char* pc, c = '!';

	printf("����� ������ ��� ��������� �� int = %lu\n", sizeof(pi));
	printf("����� ������ ��� ��������� �� float = %lu\n", sizeof(pf));
	printf("����� ������ ��� ��������� �� double = %lu\n", sizeof(pd)); //���������� ���� � ��� �� ����� ������ �� ���������
	printf("����� ������ ��� ��������� �� char = %lu\n", sizeof(pc));

	printf("\n");

	printf("����� ������ ��� ��� int = %lu\n", sizeof(i));
	printf("����� ������ ��� ��� float = %lu\n", sizeof(f));
	printf("����� ������ ��� ��� double = %lu\n", sizeof(d)); //���������� ������ ����� ������ ��� ��� ������
	printf("����� ������ ��� ��� char = %lu\n", sizeof(c));

	printf("\n");

	// ������� 2

	float PI = 3.14159, *p1, *p2;
	p1 = p2 = &PI; // ��������� ������ ���������� 

	printf("�� ������ p1 = %p �������� *p1 = %g\n", p1, *p1);
	printf("�� ������ p2 = %p �������� *p2 = %g\n", p2, *p2);

	printf("\n");

	// ������� 3

	int* pa, x = 5; pa = &x;

	printf("�� ������ %p �������� *ptr = %d\n", pa, *pa);
	pa++;
	printf("�� ������ %p �������� *ptr = %d\n", pa, *pa);
	pa--;
	printf("�� ������ %p �������� *ptr = %d\n", pa, *pa);

	printf("\n");

	double* pad, xd = 5.33f;
	pad = &xd;

	printf("�� ������ %p �������� *ptr = %g\n", pad, *pad);
	pad++;
	printf("�� ������ %p �������� *ptr = %.1g\n", pad, *pad);
	pad--;
	printf("�� ������ %p �������� *ptr = %.1g\n", pad, *pad);

	printf("\n");

	char* pac, xc = '!';
	pac = &xc;

	printf("�� ������ %p �������� *ptr = %c\n", pac, *pac);
	pac++;
	printf("�� ������ %p �������� *ptr = %c\n", pac, *pac);
	pac--;
	printf("�� ������ %p �������� *ptr = %c\n", pac, *pac);

	printf("\n");

	long double* pad1, xd1 = 5.44f;
	pad1 = &xd1;

	printf("�� ������ %p �������� *ptr = %.1g\n", pad1, *pad1);
	pad1++;
	printf("�� ������ %p �������� *ptr = %.1g\n", pad1, *pad1);
	pad1--;
	printf("�� ������ %p �������� *ptr = %.1g\n", pad1, *pad1);

	printf("\n");

	short unsigned int* pasui, xsui = 2;
	pasui = &xsui;

	printf("�� ������ %p �������� *ptr = %d\n", pasui, *pasui);
	pasui++;
	printf("�� ������ %p �������� *ptr = %d\n", pasui, *pasui);
	pasui--;
	printf("�� ������ %p �������� *ptr = %d\n", pasui, *pasui);

	printf("\n");

	_Bool* pab, xb = 1;
	pab = &xb;

	printf("�� ������ %p �������� *ptr = %d\n", pab, *pab);
	pab++;
	printf("�� ������ %p �������� *ptr = %d\n", pab, *pab);
	pab--;
	printf("�� ������ %p �������� *ptr = %d\n", pab, *pab);

	printf("\n");

	// ������� 4

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

	// ������� 5

	/* ������
	
	int x_1 = 0x12345678;
	int* prt; // ��������� �� ����������� ����������
	unsigned char* a1, * a2, * a3, * a4; // ��������� �� �����
	unsigned char* a0; // ��������� �� ����
	prt = &x_1; // ��������� ������ ����������

	a0 = (unsigned char*)prt;// �������������� ���� ��� ��������� ��������� �� ���� ����

	a1 = a0 + 3; // 4-�� ���� ����� �_1
	a2 = a0 + 2; // 3-�� ���� ����� �_1
	a3 = a0 + 1; // 2-�� ���� ����� �_1
	a4 = a0; // 1-�� ���� ����� �_1

	printf("%.2x \n%.2x \n%.2x \n%.2x \n",*a1, *a2, *a3, *a4);
	*/

	int I = 12345;
	int* pI;
	unsigned char* i1, * i2, * i3, * i4; // ��������� �� �����
	unsigned char* i0; // ��������� �� ����

	//pI = &I; // ��������� ������ ����������
	i0 = (unsigned char*)&I; // �������������� ���� ��� �������� ��������� �� ���� ����

	i1 = i0 + 3; // 4-�� ���� ����� I
	i2 = i0 + 2; // 3-�� ���� ����� I
	i3 = i0 + 1; // 2-�� ���� ����� I
	i4 = i0; // 1-�� ���� ����� I

	printf("��� ������ int:  \n%.2x \n%.2x \n%.2x \n%.2x \n\n", *i1, *i2, *i3, *i4);

	float F = 12345.0;
	float* pF;
	unsigned char* f1, * f2, * f3, * f4; // ��������� �� �����
	unsigned char* f0; // ��������� �� ����

	//pF = &F; // ��������� ������ ����������
	f0 = (unsigned char*)&F; // �������������� ���� ��� �������� ��������� �� ���� ����

	f1 = f0 + 3; // 4-�� ���� ����� F
	f2 = f0 + 2; // 3-�� ���� ����� F
	f3 = f0 + 1; // 2-�� ���� ����� F
	f4 = f0; // 1-�� ���� ����� F

	printf("��� ������ float:  \n%.2x \n%.2x \n%.2x \n%.2x \n\n", *f1, *f2, *f3, *f4);

	double D = 12345.0;
	double* pD;
	unsigned char* d1, * d2, * d3, * d4, * d5, * d6, * d7, * d8; // ��������� �� �����
	unsigned char* d0; // ��������� �� ����

	//pD = &D; // ��������� ������ ����������
	d0 = (unsigned char*)&D; // �������������� ���� ��� �������� ��������� �� ���� ����

	d1 = d0 + 7; // 8-�� ���� ����� D
	d2 = d0 + 6; // 7-�� ���� ����� D
	d3 = d0 + 5; // 6-�� ���� ����� D
	d4 = d0 + 4; // 5-�� ���� ����� D
	d5 = d0 + 3; // 4-�� ���� ����� D
	d6 = d0 + 2; // 3-�� ���� ����� D
	d7 = d0 + 1; // 2-�� ���� ����� D
	d8 = d0; // 1-�� ���� ����� D

	printf("��� ������ double:  \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n%.2x \n\n", *d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8);
}