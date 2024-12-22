#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define SIZE 6
#define MAX 20

typedef struct gryzovik {
    char marka[50];
    char proizvoditel[100];
    float gr_pod;
    int year_vipysk;
    int data_registr;
} GR;

int randomNumber(int min, int max);                                         // ��������� ��������� �����
void random_strin(char* str, const char* arr[], int arr_size);              // ��������� �����/�������������� ����������
void fill_array(GR gr_ik[], int size);                                      // ���������� ������� ���������� ����������
void print_array(GR* gr_ik, int size);                                      // ����� ���� ����� �������
void print_gr_ik(GR* gryzovik);                                             // ������ �������� ����� ����� ������
int input_file(char* filename, GR* arr, int size);                          // ������ ������� �������� � ���� 
int output_file(char* filename, GR* arr, int  size);                        // ������ ������ ������ �� �����
void search_gr_ik_proizv(GR* gr_ik, int size, const char* proizvoditel);    // �����, ������������ ��������� � ������� ������ (������������� ���������)
int compare(const void* a, const void* b);                                  // ��������� �� ����������������
int compare1(const void* a, const void* b);                                 // ��������� �� ���� �����������


int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));  // ������������� ���������� ��������� �����
    // ������� 1
    
    GR* gr = (GR*)malloc(SIZE * sizeof(GR));
    if (gr == NULL) {
        printf("������ ��������� ������");
        return 1;  // �������� �� �������� ��������� ������
    }
   
    while (1) {
        char o;

        int menu;
        printf("\t\t�������� ����� ����:\n\t1 - ������������� ������;\n\t2 - �������� ������ �� �����;\n\t3 - ����� ������ � ������� �� �������������;\n\t4 - ���������� ������� �� �����;\n\t5 - ���������� ������� ����������� ������� � ����� ����\n\t");
        scanf_s("%d", &menu);
        switch (menu) {
        case 1: {
            fill_array(gr, SIZE); // 1.1
            print_array(gr, SIZE); // 1.2
            break;
        }
        case 2: {
            char filename[50];
            printf("������� ��� ����� ��� �������� ������: ");
            scanf("%s", filename);
            if (input_file(filename, gr,SIZE)) {
                printf("������ ������� ��������� �� �����.\n");
                print_array(gr, SIZE);
            }
            else {
                printf("�� ������� ��������� ������ �� �����.\n");
            }
            break;
        }
        case 3: {
            // ������� 2
            printf("\n\n");
            char mat[MAX];
            printf("������� �������������, �������� �� ������ �����: ");
            scanf("%20s", mat);
            printf("\n\n");
            search_gr_ik_proizv(gr, SIZE, mat); // 2.1
            printf("\n\n");
            break;
        }
        case 4: {
            int sort;
            printf("\n\t\t�������� ����������:\n\t1 - �� ����������������;\n\t2 - �� ���� �����������\n\t");
            scanf_s("%d", &sort);
            switch (sort) {
            case 1: {
                printf("���������� ������� �� ����������������:\n"); // 2.2
                qsort(gr, SIZE, sizeof(GR), compare);
                print_array(gr, SIZE);
                printf("\n");
                break;
            }
            case 2: {
                printf("���������� ������� �� ���� �����������:\n");
                qsort(gr, SIZE, sizeof(GR), compare1);
                print_array(gr, SIZE);
                printf("\n");
                break;
            }
            default:
                printf("��������� ����������� ���������, ��������� �����...");
                break;
            }
        }
        case 5: {
            // ������� 3
            char fname[20] = "gryzovik.txt";
            input_file(fname, gr, SIZE);
            output_file(fname, gr, SIZE);
            break;
        }
        default:
            printf("��������� ����������� ���������� ��������� �����...");
            break;
        }
        printf("\n");

        printf("���������� ? (�� - y, ��� - n)  ");
        o = getchar();

        if (o == 'n') {
            break;
        }
        printf("\n");
    }
    free(gr);
}

// ��������� ��������� �����
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

const char* marka[] = { "Mercedes Atego", "Mitsubishi F F", "N", "KamAZ-43118", "Y20�40", "MAZ-6501" };
const char* proizvoditel[] = { "Mercedes - Benz", "Mitsubishi", "Isuzu", "KamAZ", "Toyota", "MAZ" };

// ��������� ��������� �����/�������������� ����������
void random_strin(char* str, const char* arr[], int arr_size) {
    int index = rand() % arr_size;
    strcpy(str, arr[index]);
}

// ������������� ������� �������� � ���������� ����������
void fill_array(GR gr_ik[], int size) {
    for (int i = 0; i < size; i++) {
        random_strin(gr_ik[i].marka, marka, (sizeof(marka) / sizeof(marka[0])));
        random_strin(gr_ik[i].proizvoditel, proizvoditel, (sizeof(proizvoditel)/sizeof(proizvoditel[0])));
        gr_ik[i].gr_pod = randomNumber(1, 25);
        gr_ik[i].year_vipysk = randomNumber(1959, 2008);
        gr_ik[i].data_registr = randomNumber(2000, 2024);
    }
}

// ������ �������� ����� �������
void print_array(GR* gr_ik , int size) {
    printf("_________________________________________________________________________________________________\n");
    printf("|   ����� \t\t|   ������������� |  ����������������   | ��� ������� \t|���� �����������|\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        print_gr_ik(&gr_ik[i]);
    }
}

// ������ �������� ����� ����� ������
void print_gr_ik(GR* gr_ik) {
    printf("| %15s \t| %15s |  %10.2f  \t| %5.d \t|   %5.d   \t|\n", gr_ik->marka, gr_ik->proizvoditel, gr_ik->gr_pod, gr_ik->year_vipysk, gr_ik->data_registr);
}

// �����, ������������ ��������� � ������� ������ (������������� ���������)
void search_gr_ik_proizv(GR* gr_ik, int size, const char* proizvoditel) {
    printf("��������� ������������� %s \n", proizvoditel);
    int pro = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(gr_ik[i].proizvoditel, proizvoditel) == 0) {
            print_gr_ik(&gr_ik[i]);
            pro = 1;
        }
    }
    if (!pro) {
        printf("��������� ������������� %s �� �������\n", proizvoditel);
    }
}

// ������ ������� �������� � ����
int input_file(char* filename, GR* gr_ik, int size) {
    FILE* out = fopen(filename, "w");
    if (out == NULL) {
        printf("������");
        return 0;
    }
    fprintf(out, "__________________________________________________________________________________\n");
    fprintf(out, "| �����\t| �������������\t| ����������������\t| ��� �������\t| ���� �����������\t|\n");
    fprintf(out, "----------------------------------------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        fprintf(out, "| %s | %s | %.2f | %d | %d |\n", gr_ik[i].marka, gr_ik[i].proizvoditel, gr_ik[i].gr_pod, gr_ik[i].year_vipysk, gr_ik[i].data_registr);
    }
    fclose(out);
    return 1;
}

// ������ ������ ������ �� �����
int output_file(char* filename, GR* gr_ik, int  size) {
    FILE* out = fopen(filename, "r");
    if (out == NULL) {
        printf("������");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        fscanf(out, "%s %s %.2f %d %d", gr_ik[i].marka, gr_ik[i].proizvoditel, gr_ik[i].gr_pod, gr_ik[i].year_vipysk, gr_ik[i].data_registr);
    }
    fclose(out);
    return 1;
   
}

// ��������� �� ����������������
int compare(const void* a, const void* b) {
    const GR* gr_ikA = (const GR*)a;
    const GR* gr_ikB = (const GR*)b;

    if (gr_ikA-> gr_pod< gr_ikB->gr_pod) {
        return -1;
    }
    else if (gr_ikA->gr_pod > gr_ikB->gr_pod) {
        return 1;
    }
    return 0;
}

// ��������� �� ���� �����������
int compare1(const void* a, const void* b) {
    const GR* gr_ikA = (const GR*)a;
    const GR* gr_ikB = (const GR*)b;

    if (gr_ikA->data_registr < gr_ikB->data_registr) {
        return -1;
    }
    else if (gr_ikA->data_registr > gr_ikB->data_registr) {
        return 1;
    }
    return 0;
}