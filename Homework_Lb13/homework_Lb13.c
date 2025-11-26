#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char line[MAX];
	char result_line[MAX];
	int start = 0, i = 0;

	puts("Введите строку:");
	fgets(line, sizeof(line), stdin);
	line[strcspn(line, "\n")] = '\0';
	char* first = strchr(line, ' ');
	char* last = strrchr(line, ' ');
	strncpy(result_line, first + 1, last - first - 1);
	result_line[last - first - 1] = '\0';
	int k = strlen(result_line);
	printf("Количество символов: %d", k);
}