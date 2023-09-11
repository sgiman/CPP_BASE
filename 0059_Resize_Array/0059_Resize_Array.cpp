﻿//*******************************************************************************************************************
// Изменить размер массива. Удалить. Добавить элемент в массив. Увеличение массива. | C++ для начинающих | Урок #10
// ------------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ------------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//*******************************************************************************************************************

#include <iostream>
#include "utils.h"

using namespace std;

/*
 *   Изменить размер массива.
 *   Добавить элемент в массив.
 *   Удалить элемент массива.
 */

 //void MyDate();
 //void FillArray(int* const arr, const int size, const int max)	// заполнить момссив 
 //void ShowArray(int* const arr, const int size);				// вывод

 /*-----------------------------
   Добавить элемент в массив
 ------------------------------*/
void push_back(int*& arr, int& size, const int value)	// *& - указатель на адрес, & - адрес, * - указатель на данные 
{
	int* newArray = new int[size + 1];		// Выделить память и добавить последний элемент (новый массив) !!!

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size++] = value;				// добавить последний элемент  

	delete[] arr;							// удалить исходный массив 

	arr = newArray;							// указатель на новый массив  
}

/*-----------------------------
   Удалить элемент массива
------------------------------*/
void pop_back(int*& arr, int& size)			// *& - содержит адрес для замены адреса массива
{
	size--;									// уменьшить на один последний элемент 

	int* newArray = new int[size];			// новый массив (данные)

	for (int i = 0; i < size; i++)			// копировать в новый массив
	{
		newArray[i] = arr[i];
	}

	delete[] arr;							// удалить исходный массив 

	arr = newArray;							// указатель на новый массив  
}

/****************************
			main
*****************************/
int main()
{
	setlocale(LC_ALL, "ru");

	int size = 5;
	int* arr = new int[size];		// выделить память

	cout << endl;
	FillArray(arr, size, 100);		// заполнить - utils.h
	ShowArray(arr, size);			// консоль (исходный массив) - utils.h

	push_back(arr, size, 111);		// добавить в конец элемент 
	ShowArray(arr, size);			// вывести обновленный массив - utils.h

	pop_back(arr, size);			// удалить последний элемент 
	ShowArray(arr, size);			// вывести обновленный массив - utils.h  

	delete[] arr;


	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}