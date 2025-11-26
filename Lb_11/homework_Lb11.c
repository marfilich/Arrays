#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#define MAX 100

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, first_p = 0, last_p = 0;
	int arr[MAX];
	int sum = 0;
	printf("Введите количество элементов массива: ");
	scanf("%d", &n);
	printf("Введите %d элементов\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			first_p = i;
			break;
		}
	}
	for (int i = n - 1; i < n; i--)
	{
		if (arr[i] > 0)
		{
			last_p = i;
			break;
		}
	}
	if ((last_p - first_p) > 1)
	{
		for (int i = first_p + 1; i < last_p; i++)
		{
			sum += arr[i];
		}
		printf("Сумма элементов равно %d", sum);
	}
	else
	{
		printf("Между первым и последним положительными элементами нет других чисел");
	}
	return 0;
}