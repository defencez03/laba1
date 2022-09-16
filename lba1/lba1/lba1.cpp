//Выполнили студенты группы 21ВВ1.3: Чинов Д.Д., Тюкалов В.Е.

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int Array[10], min = 0, max = 0, res = 0, len = 0;
	for(int i = 0; i < 10; i++){
		Array[i] = rand()/100;
	}
	min = Array[0];
	max = Array[0];
	for(int i = 0; i < 10; i++){
		if(Array[i] > max){
			max = Array[i];
		}
		if(Array[i] < min){
			min = Array[i];
		}
	}
	res = max - min;
	printf("Задание 1, 2:\n");
	printf("Массив случайных чисел\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", Array[i]);
	}
	printf("\nres = %d max = %d min = %d\n", res, max, min);
	/*------------------------------------------------------------------*/
	printf("\nЗадание 3:\n");
	printf("Длина массива: ");
	scanf("%d", &len);
	int *arr = (int*)malloc(len*sizeof(int));
	for(int i = 0; i < len; i++){
		arr[i] = i;
		printf(" %d", arr[i]);
	}
	free(arr);
	/*------------------------------------------------------------------*/
	printf("\n");
	printf("\nЗадание 4:\n");
	int arr4[4][4], sum[4]; 
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			arr4[i][j] = rand()%100;
			printf("%3d1 ", arr4[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < 4; i++){
		sum[i] = 0;
		for(int j = 0; j < 4; j++){
			sum[i] = sum[i] + arr4[i][j];
		}
		printf("sum%d = %d ", i, sum[i]);
	}
	/*------------------------------------------------------------------*/
	struct student{
		char name[20];
		char surname[20];
		int age;
	} People[4];

	char Name[20], Surname[20];
	int Age, rep = 0;
	bool repeat = true, find = true;

	printf("\n");
	printf("\nЗадание 5:\n");
	for(int i = 0; i < 4; i++){
		fflush(stdin);
		printf("Введите имя: ");
		gets(People[i].name);
		printf("Введите фамилию: ");
		gets(People[i].surname);
		printf("Введите возраст: ");
		scanf("%d", &People[i].age);
	}
	while(repeat){
		printf("\nПоиск студента:\n\n");
		fflush(stdin);
		printf("Введите имя: ");
		gets(Name);
		printf("Введите фамилию: ");
		gets(Surname);
		printf("Введите возраст: ");
		scanf("%d", &Age);

		for(int i = 0; i < 4; i++){
			if(strcmp(Name, People[i].name) == 0 || strcmp(Surname, People[i].surname) == 0 || Age == People[i].age){
				printf("\nСтудент: %s %s %d", People[i].name, People[i].surname, People[i].age);
				find = false;
				repeat = false;
				break;
			} 
		}

		if(find){
			printf("\nТакого студента нет\n");
			printf("Хотите продолжить поиск(0 - да, иначе - нет): ");
			scanf("%d", &rep);
			if(rep != 0)
				repeat = false;
		}
	}

	getch();
}

