#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#define N 10
#define MAX 100


float func(float x);

int main()
{
	//task11_1();
	//task11_2();
	task13_2();
	//task13_2();

}

//Вариант 4
int task11_1()
{
	setlocale(LC_ALL, "RUS");
	float A[N];
	float B[N];
	float sr_z = 0;
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
	printf("Среднее арифметические элементов: %f", sr_z / N);
}

int task11_2()
{
	setlocale(LC_ALL, "RUS");
	float NUM[MAX];
	float x = 2;

	for (int i = 0; i < MAX; i++)
	{
		NUM[i] = func(x);
		x += 0.2;
		printf("%f ", NUM[i]);
	}

	float p = 0, o = 0, sr_z;
	int k_p = 0, k_o = 0;
	
	for (int i = 0; i < MAX; i++)
	{
		if (NUM[i] >= 0) {
			p += NUM[i];
			k_p += 1;
		}
		else {
			o += NUM[i];
			k_o += 1;
		}
	}
	sr_z = p / k_p;
	printf("\nИмя массива: NUM Значение положительных %f отрицательных %f Количество положительных %d отрицательных %d Среднее значение положительных %f", p, o, k_p, k_o, sr_z);
}

float func(float x) 
{
	float y;
	y = pow(2, x) - 2 * pow(x, 2) - 1;
	return y;
}

int task13_1()
{
	char Name[20];
	char Snew[50] = "Hello ";
	printf("Your name\n");
	scanf("%s", Name);
	strcat(Snew, Name);

	for (int i = 0; i < strlen(Snew); i++)
	{
		Snew[i] = toupper(Snew[i]);
	}
	while (strlen(Snew) != 40)
	{
		strcat(Snew, "!");
	}
	printf("%s", Snew);
	return 0;
}

int task13_2()
{
	char Name[20];
	char Snew[20] = "Hello";
	char Result[50] = "";
	printf("Your name\n");
	scanf("%s", Name);
	int s_len = strlen(Snew), n_len = strlen(Name);
	char snew[2] = {Snew[s_len - 1], '\0'}, name[2] = { Name[n_len - 1], '\0' };
	strncat(Result, Snew, s_len - 1);
	strcat(Result, "_");
	strcat(Result, snew);
	strcat(Result, ", ");
	strncat(Result, Name, n_len - 1);
	strcat(Result, "_");
	strcat(Result, name);
	printf("%s", Result);
	return 0;
}