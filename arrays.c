#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"
#define N 10

float* full_elements_11(float* A, float* B)
{

	for (int i = 0; i < N; i++)
	{
		float temp;
		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
	}
	for (int j = 0; j < N; j++)
	{
		float num;
		num = A[j] * A[j];
		B[j] = num;
	}
	return B;
}

float put_elements_11(float* A, float* B, float sr_z)
{ 
	puts("----------------------------------------------------");
	puts("| индекс    |исходное значение|  новое значение    |");
	for (int i = 0; i < N; i++)
	{
		printf("|%10d |%15f  |%20f|\n", i, A[i], B[i]);
	}
	puts("----------------------------------------------------");
	for (int i = 0; i < N; i++)
	{
		sr_z += B[i];
	}
	printf("Среднее арифметическое элементов: %f\n", sr_z / N);
	return 0;
}

double funtion_homework_11(float* A)
{
	int first_p = 0, last_p = 0;
	double  sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > 0)
		{
			first_p = i;
			break;
		}
	}
	for (int i = N - 1; i < N; i--)
	{
		if (A[i] > 0)
		{
			last_p = i;
			break;
		}
	}
	if ((last_p - first_p) > 1)
	{
		for (int i = first_p + 1; i < last_p; i++)
		{
			sum += A[i];
		}
		return sum;
	}
	else
	{
		return -1;
	}
}

double func(double x)
{
	double y;
	y = pow(2, x) - 2 * pow(x, 2) - 1;
	return y;
}

double* full_elements_14(double* ptr_array, int size) {

	double x = 2;
	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = func(x);
		x += 0.2;
	}
	ptr_array[size - 2] = 50;
	ptr_array[size - 5] = 2;
	return ptr_array;
}

int put_elements_14(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("ptr_array[%d] = %.2lf\n", i, ptr_array[i]);
	}
	return 0;
}

double* calc_elements_14(double* ptr_array, int size)
{
	double* ptr_array_new;
	ptr_array_new = (double*)malloc(size * sizeof(double));
	if (ptr_array_new == NULL)
	{
		puts("error");
		return -1;
	}
	for (int j = 0; j < size; j++)
	{
		double num;
		num = ptr_array[j] * ptr_array[j];
		ptr_array_new[j] = num;
	}
	return ptr_array_new;
}

double sum_elements_14(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (int i = begin - 1; i <= end - 1; i++)
	{
		sum += ptr_array[i];
	}
	return sum;
}

int find_element_14(double* ptr_array, int size, double element)
{
	int index = -1;
	for (int i = 0; i <= size; i++)
	{
		if (element == ptr_array[i])
		{
			index = i;
		}
	}
	return index;
}

//ДЗ работа 14
double funtion_14(double* ptr_array, int k)
{
	double max = ptr_array[0];
	for (int i = 0; i <= k; i++)
	{
		if (ptr_array[i] > max)
		{
			max = ptr_array[i];
		}
	}
	return max;
}



double* full_elements_16(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++) {
		ptr_array[i] = -1 + ((double)rand() / RAND_MAX) * (1 - (-1));
	}
	return ptr_array;

}


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

double* last_negative(double* ptr_array, int* size)
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

//Дз 16
int find_size_d(int size_a, int size_b, double* ptr_array_a, double* ptr_array_b)
{
	int size, even = 0, uneven = 0;
	for (int i = 0; i < size_a; i++)
	{
		if (i % 2 == 0) {
			even += 1;
		}
	}
	for (int i = 0; i < size_b; i++)
	{
		if (i % 2 == 1) {
			uneven += 1;
		}
	}
	size = (even < uneven) ? even * 2 : uneven * 2;
	return size;
}

double* even_uneven(double* ptr_array_a, double* ptr_array_b, double* ptr_array_d, int size_a, int size_b, int size_d)
{
	for (int i = 0; i < size_d; i++)
	{
		if (i % 2 == 0)
		{
			ptr_array_d[i] = ptr_array_a[i];
		}
		else {
			ptr_array_d[i] = ptr_array_b[i];
		}
	}
	return ptr_array_d;
}
