#include <stdio.h>
#include <locale.h>
void house()
{
	puts("                         *          ");
	puts("                         **         ");
	puts("                        ***         ");
	puts("                         *           ");
	puts("                       ****         ");
	puts("                       ****         ");
	puts("                       ****         ");
	puts("          ********************      ");
	puts("         *                    *     ");
	puts("        *                      *    ");
	puts("       *                        *   ");
	puts("      *                          *  ");
	puts("     *                            * ");
	puts("    ********************************");
	puts("    *                              *");
	puts("    *                              *");
	puts("    *  *******            *******  *");
	puts("    *  *  *  *            *  *  *  *");
	puts("    *  *******            *******  *");
	puts("    *  *  *  *  ********  *  *  *  *");
	puts("    *  *******  *      *  *******  *");
	puts("    *           *      *           *");
	puts("    *           *    * *           *");
	puts("    *           *      *           *");
	puts("    *           *      *           *");
	puts("    ********************************");
}
void main()
{
	setlocale(LC_ALL, "RUS");
	puts("��� ���������");
	puts("������� Enter, ����� ���������� . . .");
	getchar();
	house();
}