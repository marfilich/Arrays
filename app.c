#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "array.h"

#define N 10
#define MAX 100

int main() {
    setlocale(LC_ALL, "RUS");
    
    int operation, size;
    puts("==== Лабораторные работы 11, 14, 16: Работа с массивами ===\n");

    puts("========== Лабораторная работа 11 ===============");
    task11();
    printf("\n");
    puts("---------------------------------");
    puts("Укажите размер массива");
    scanf("%d", &size);

    puts("========== Лабораторная работа 14 ===============");
    task14(size);
    printf("\n");

    puts("========== Лабораторная работа 16 ===============");
    task16(size);

    return 0;
}


int task11(){
    setlocale(LC_ALL, "RUS");
    float A[N];
    float B[N];
    float sr_z = 0;
    full_elements_11(A, B);
    put_elements_11(A, B, sr_z);
    printf("Сумму элементов массива, расположенных между первым и последним положительными элементами равна %lf\n", funtion_homework_11(A));

}

int task14(int size) {

    setlocale(LC_ALL, "RUS");
    int begin, end, k;
    double a;

    puts("Введите начальный индекс:");
    scanf("%d", &begin);
    puts("Введите конечный индекс:");
    scanf("%d", &end);
    puts("Введите значение элемента");
    scanf("%lf", &a);
    puts("Введите позицию элемента для поиска максимального");
    scanf("%d", &k);

    double* ptr_array;
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL)
    {
        puts("error");
        return -1;
    }

    // Задание 1. Заполнение массива

    full_elements_14(ptr_array, size);
    put_elements_14(ptr_array, size);

    // Задание 2. Преобразование массива

    puts("Элементы массива возведены в квадрат");
    put_elements_14(calc_elements_14(ptr_array, size), size);
    printf("Сумма чисел от %d до %d равна %.4lf\n", begin, end, sum_elements_14(ptr_array, begin, end));
    printf("Индекс элемента %lf равен %d\n", a, find_element_14(ptr_array, size, a));

    // Домашнее задание
    printf("Максимальное значение до числа на позиции %d равно %.4lf\n", k, funtion_14(ptr_array, k));

    free(ptr_array);
}

int task16(int size) {

    setlocale(LC_ALL, "RUS");
    double a;

    puts("Введите значение А");
    scanf("%lf", &a);


    double* ptr_array_16;
    ptr_array_16 = (double*)malloc(size * sizeof(double));
    if (ptr_array_16 == NULL)
    {
        puts("error");
        return -1;
    }

    // Задание 1. Заполнение массива

    full_elements_16(ptr_array_16, size);
    put_elements_14(ptr_array_16, size);

    // Задание 2. Преобразование массива
    int new_size = -1;
    double* new_array = calc_elements_16(ptr_array_16, size, a, new_size);
    if (new_array == NULL)
    {
        puts("error");
        return -1;
    }
    for (int i = 0; i <= size; i++)
    {
        if (ptr_array_16[i] <= a)
        {
            new_size += 1;
        }
    }
    puts("Новый массив:");
    put_elements_14(new_array, new_size);
    puts("Массив - после последнего отрицательного -999:");
    double* negative_array = last_negative(ptr_array_16, &size);
    if (negative_array == NULL)
    {
        puts("error");
        return -1;
    }

    put_elements_14(negative_array, size);

    // Домашнее задание
    srand(time(NULL));
    int size_a, size_b, size_c, size_d;
    size_a = 10 + rand() % 41;
    size_b = 10 + rand() % 41;
    size_c = 10 + rand() % 41;

    double* ptr_array_a = (double*)malloc(size_a * sizeof(double));
    if (ptr_array_a == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    ptr_array_a = full_elements_16(ptr_array_a, size_a);

    double* ptr_array_b = (double*)malloc(size_b * sizeof(double));
    if (ptr_array_b == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    ptr_array_b = full_elements_16(ptr_array_b, size_b);

    double* ptr_array_c = (double*)malloc(size_c * sizeof(double));
    if (ptr_array_c == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    ptr_array_c = full_elements_16(ptr_array_c, size_c);

    size_d = find_size_d(size_a, size_b, ptr_array_a, ptr_array_b);
    double* ptr_array_d = (double*)malloc(size_d * sizeof(double));
    if (ptr_array_d == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    ptr_array_d = even_uneven(ptr_array_a, ptr_array_b, ptr_array_d, size_a, size_b, size_d);
    puts("Массив А");
    put_elements_14(ptr_array_a, size_a);
    puts("Массив B");
    put_elements_14(ptr_array_b, size_b);
    puts("Массив C");
    put_elements_14(ptr_array_c, size_c);
    puts("Массив D");
    put_elements_14(ptr_array_d, size_d);

    free(ptr_array_16);
    free(new_array);
    free(ptr_array_a);
    free(ptr_array_b);
    free(ptr_array_c);
    free(ptr_array_d);
    return 0;

}
