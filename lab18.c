#define _CRT_SECURE_NO_DEPRECATE 
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <math.h> 
#include <string.h> 
#include <time.h> 

struct point { // объявление переменных типа point
    float x;
    float y;
    char name;
};

typedef struct point Point; // создание собственного типа данных

void put_point(Point z);  // отображение точки в отдельной функции
float dist(Point z, Point w); // функция вычисления декартова расстояния между двумя точками
Point newPoint(Point z, Point w); // новая точка - середина отрезка
void chetverti(Point z); // вывод четверти, в которой находится точка

// для дз объявление переменных типа gryzovik
struct gryzovik {
    char marka[50];
    char proizvoditel[100];
    float gr_pod;
    int year_vipysk;
    int data_registr;
};

typedef struct gryzovik GR; // создание собственного типа данных

void put_gryz(GR G); // отбор по параметрам грузовика

void main()
{
    setlocale(LC_CTYPE, "RUS");
    // задание 1 
    Point b, a; // 1.1
    a = (Point){ 1.f, 2.f, 'A' };
    b = (Point){ 1.f, 2.f, 'B' };
    b.name = 'B';
    b.x = 5;
    b.y = -3;
    a.name = 'A';
    a.x = -10;
    a.y = 2;

    put_point(a); // 1.2
    printf("\n");
    put_point(b); 
    printf("\nДекартовое расстояние от точки %c до точки %c = %.3f",a.name,b.name,dist(a, b)); // 1.3
    printf("\n");
    chetverti(a); // 1/5
    printf("\n");
    chetverti(b);
    printf("\n");

    Point c, d; // 1.4
    c = (Point){ 1.f, 2.f, 'C' };
    d = (Point){ 1.f, 2.f, 'D' };
    printf("\nВведите координаты точки C(x, y): \n");
    c.name = 'C';
    scanf_s("%f %f",&c.x, &c.y);
    printf("\nВведите координаты точки D(x, y): \n");
    d.name = 'D';
    scanf_s("%f %f", &d.x, &d.y);

    put_point(c); 
    printf("\n");
    put_point(d);
    printf("\nДекартовое расстояние от точки C до точки D = %f\n", dist(c,d));

    chetverti(c);
    printf("\n");
    chetverti(d);
    printf("\n");

    printf("\nТочка M(%.1f, %.1f) - середина отрезка CD\n", newPoint(c, d).x, newPoint(c, d).y);
    printf("\n");
    chetverti(newPoint(c, d));
    printf("\n");

    // задание 2
    struct tm {
        int tm_sec;     /* секунды - [0,59] */
        int tm_min;     /* минуты - [0,59] */
        int tm_hour;    /* часы - [0,23] */
        int tm_mday;    /* день - [1,31] */
        int tm_mon;     /* месяц - [0,11] */
        int tm_year;    /* год от 1900 */
        int tm_wday;    /* день недели с воскресенья - [0,6] */
        int tm_yday;    /* номер дня с 1 января - [0,365] */
        int tm_isdst;   /* флаг летнего времени устанавливается >0, если <=0, то информация недоступна*/
    };
   
    struct tm* mytime;
    time_t t;
    t = time(NULL);
    mytime = localtime(&t);
    printf("Московское время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec); // 2.1
    const char* month_names[] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь","Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };
    char data[1000]; // буфер для записи строки
    sprintf(data, "День - %d и месяц - %s \n", mytime->tm_mday, month_names[mytime->tm_mon]); // записывает данные в строку
    printf("%s", data); // Вывод строки 2.2

    int data_len = strlen(data); // 2.3
    int otstyp = (80 - data_len) / 2;

    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            printf("%*s%s%*s\n", otstyp, "", data, (80 - data_len - otstyp), ""); //Центрирование
        }
        else {
            printf("%s\n", "*******************************************************************************");
        }
    }

    // задание 3
    printf("\n\t\tЗапись 'Грузовик' : \n");
    GR G1, G2, G3, G4, G5, G6;

    G1 = (GR){ "Mercedes Atego", "Mercedes - Benz", 8, 2004, 2024};
    G2 = (GR){"Mitsubishi Fuso Fighter","Mitsubishi", 20, 1984, 2023};
    G3 = (GR){ "N", "Isuzu", 3.5, 1959, 2017 };
    G4 = (GR){ "КамАЗ-43118","КамАЗ", 11, 1995, 2015 };
    G5 = (GR){ "Y20–40", "Toyota", 1.5, 1979, 2020 };
    G6 = (GR){ "МАЗ-6501","МАЗ", 25, 2008, 2023 };

    put_gryz(G1);
    printf("\n");
    put_gryz(G2);
    printf("\n");
    put_gryz(G3);
    printf("\n");
    put_gryz(G4);
    printf("\n");
    put_gryz(G5);
    printf("\n");
    put_gryz(G6);

}

void put_gryz(GR G) { // отбор по параметрам грузовика
    if (G.data_registr < 2024 && G.gr_pod > 3) {
        printf("Грузовик %s имеет грузоподъемность %.2f, а год регистрации автомобиля - %d\n", G.marka, G.gr_pod, G.data_registr);
    }
}

void put_point(Point z) { // отображение точки в отдельной функции
    printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) { // функция вычисления декартова расстояния между двумя точками
    float ZW = sqrt(pow((w.x - z.x), 2) + pow((w.y - z.y), 2));
    return ZW;
}

Point newPoint(Point z, Point w) { // новая точка - середина отрезка
    Point M;
    M = (Point){ 1.f, 2.f, 'M' };
    M.x = (z.x + w.x) / 2;
    M.y = (z.y + w.y) / 2;
    return M;
}

void chetverti(Point z) { // вывод четверти, в которой находится точка
    if (z.x > 0 && z.y > 0) {
        printf("Точка %c находитмя в первой четверти\n", z.name);
    }
    else if (z.x > 0 && z.y < 0) {
        printf("Точка %c находитмя в четвертой четверти\n", z.name);
    }
    else if (z.x < 0 && z.y < 0) {
        printf("Точка %c находитмя в третьей четверти\n", z.name);
    }
    else if (z.x < 0 && z.y > 0) {
        printf("Точка %c находитмя во второй четверти\n",z.name);
    }
    else if (z.x = 0 && (z.y > 0 || z.y < 0)) {
        printf("Точка %c лежит на оси OY\n", z.name);
    }
    else if (z.y = 0 && (z.x > 0 || z.x < 0)) {
        printf("Точка %c лежит на оси OX\n", z.name);
    }
    else {
        printf("Точка %c - начало координат\n", z.name);
    }
}