//Работа 16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double* full_elements_16(double* ptr_array, int size);
int put_elements_16(double* ptr_array, int size);
double* calc_elements_16(double* ptr_array, int size, double a, int new_size);
double* last_negative(double* ptr_array, int* size);

int main()
{
	setlocale(LC_ALL, "RUS");
	int size;
	double a;

	puts("Введите размер массива:");
	scanf("%d", &size);
	puts("Введите значение А");
	scanf("%lf", &a);
	

	double* ptr_array;
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}
	
	full_elements_16(ptr_array,size);
	put_elements_16(ptr_array, size);

	int new_size = -1;
	double* new_array = calc_elements_16(ptr_array, size, a, new_size);
	if (new_array == NULL)
	{
		puts("error");
		return -1;
	}
	for (int i = 0; i <= size; i++)
	{
		if (ptr_array[i] <= a)
		{
			new_size += 1;
		}
	}
	puts("Новый массив:");
	put_elements_16(new_array, new_size);
	puts("Массив - после последнего отрицательного -999:");
	double* negative_array = last_negative(ptr_array, &size);
	if (negative_array == NULL)
	{
		puts("error");
		return -1;
	}

	put_elements_16(negative_array, size);

	free(ptr_array);
	free(new_array);
	return 0;
}

double* full_elements_16(double* ptr_array, int size)
{
	double min = -1, max = 1;
	for (int i = 0; i < size; i++)
	{
		double step = 2.0 / (size - 1);
		for (int i = 0; i < size; i++) 
		{
			ptr_array[i] = -1.0 + i * step;
		}
	}
	return ptr_array;
}

int put_elements_16(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("ptr_array[%d] = %lf\n", i, ptr_array[i]);
	}
}

// Удаление элементов значение которых превышает A.
double* calc_elements_16(double* ptr_array, int size, double a, int new_size)
{
	int new_index = 0;
	for (int i = 0; i <= size; i++)
	{
		if (ptr_array[i] <= a)
		{
			new_size += 1;
		}
	}

	double* ptr_array_new;
	ptr_array_new = (double*)malloc(new_size * sizeof(double));
	if (ptr_array_new == NULL)
	{
		puts("error");
		return -1;
	}

	for (int i = 0; i <= size; i++)
	{
		if (ptr_array[i] <= a)
		{
			ptr_array_new[new_index] = ptr_array[i];
			new_index++;
		}
	}
	return ptr_array_new;
}


double* last_negative(double* ptr_array, int *size)
{
	if (ptr_array == NULL) return NULL;
	int last_index = -1;
	
	for (int i = *size - 1; i > 0; i--)
	{
		if (ptr_array[i] < 0)
		{
			last_index = i;
			break;
		}
	}

	int new_size = *size + 1;
	double* last_negative_array = (double*)realloc(ptr_array, new_size * sizeof(double));
	if (last_negative_array == NULL)
	{
		puts("error");
		return ptr_array;
	}
	ptr_array = last_negative_array;
	for (int i = *size - 1; i > last_index; i--)
	{
		ptr_array[i + 1] = ptr_array[i];
	}
	ptr_array[last_index + 1] = -999;
	*size = new_size;
	return ptr_array;
}