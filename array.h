#ifndef ARRAYS_H
#define ARRAYS_H

#include <locale.h>

//Работа 11
/**
 * Заполнение массива значениями с консоли
 * @param A указатель на первый массив
 * @param B указатель на второй массива
 * @return указатель на заполненный массив
 */
float* full_elements_11(float* A, float* B);

/**
 * Печать элементов массива и поиск среднего значения
 * @param A указатель на первый массив
 * @param B указатель на второй массива
 * @param sr_z среднее арифметическое элементов массива
 * @return среднее арифметическое элементов массива
 */
float put_elements_11(float* A, float* B, float sr_z);

/**
* Сумму элементов массива, расположенных между первым и последним положительными элементами.
* @param A указатель на первый массив
* @return сумму элементов массива, расположенных между первым и последним положительными элементами или -1 если нет положительных или между ними нет чисел
*/
double funtion_homework_11(float* A);


//Работа 14
double func(double x); // функция для получения значений как в работе 8

/**
 * Заполнение массива значениями
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return указатель на заполненный массив
 */
double* full_elements_14(double* ptr_array, int size);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return 0
 */
int put_elements_14(double* ptr_array, int size);

/**
 * Обработка элементов массива: возвести в квадрат значение каждого элемента массива
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return указатель на обработанный массив
 */
double* calc_elements_14(double* ptr_array, int size);

/**
 * Вычисление суммы элементов массива в диапазоне [begin, end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return сумма элементов
 */
double sum_elements_14(double* ptr_array, int begin, int end);

/**
 * Поиск элемента в массиве
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @param element искомый элемент
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element_14(double* ptr_array, int size, double element);

/**
/Поиск максимального значения элемента массива, находящихся до заданной позиции K включительно.
 * @param ptr_array указатель на массив
 * @param k позиция, до которой ищется максимальный элемент
 * @return максимальное значение
*/
double funtion_14(double* ptr_array, int k);

//Работа 16
/**
 * Заполнение массива случайными значениями
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return указатель на заполненный массив
 */
double* full_elements_16(double* ptr_array, int size);

/**
* Удаление элементов значение которых превышает A
* @param ptr_array указатель на массив
* @param size размер массива
* @param a число, которое не должны превышать элементы нового массива
* @param new_size размер нового массива
* @return указатель на заполненный массив
*/
double* calc_elements_16(double* ptr_array, int size, double a, int new_size);

/**
* Вставку -999 после последнего отрицательного
* @param ptr_array указатель на массив
* @param size размер массива
* @return указатель на заполненный массив
*/
double* last_negative(double* ptr_array, int* size);

/**
* Вычисление размера массива D
* @param size_a размер массива A
* @param size_b размер массива B
* @param ptr_array_a указатель на массив A
* @param ptr_array_b указатель на массив B
* @return размер массива D
*/
int find_size_d(int size_a, int size_b, double* ptr_array_a, double* ptr_array_b);

/**
* Заполнение массива D, в котором чередуются четные элементы массива A и нечетные B
* @param ptr_array_a указатель на массив A
* @param ptr_array_b указатель на массив B
* @param ptr_array_d указатель на массив D
* @param size_a размер массива A
* @param size_b размер массива B
* @param size_d размер массива D
* @return указатель на массив D
*/
double* even_uneven(double* ptr_array_a, double* ptr_array_b, double* ptr_array_d, int size_a, int size_b, int size_d);


#endif
