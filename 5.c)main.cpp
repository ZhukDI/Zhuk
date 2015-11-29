﻿/* В программе объявлен массив А целых чисел (размер массива 100).
Пользователь вводит число реально используемой части массива (число N). 
Эта часть затем заполняется случайными числами. Потом распечатываем массив.
Затем удаляем первый элемент массива (сдвигая остальные элементы) и меняем N на единицу.
Потом пользователь вводит произвольное число и оно добавляется в конец используемой части массива и меняем N на единицу.
Потом распечатываем массив. Затем опять удаляем первый элемент массива (сдвигая остальные элементы) и меняем N на единицу.
Потом пользователь вводит произвольное число и оно добавляется в конец используемой части массива и меняем N на единицу.
Потом распечатываем массив.*/

#include <iostream>//Задача c
using std::cin;
using std::cout;
using std::endl;


void initialization(int mas[], int N)//инициализация чисел
{
	for (int i = 0; i<N; i++)
	{
		mas[i] = rand() % 50 - 25;
	}
}

void print(int mas[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl << endl;
}

void remove(int mas[], int &N)
{
	for (int i = 0; i < N; i++)
	{
		mas[i] = mas[i + 1];
	}
	N = N - 1;
}

void addition(int mas[], int &N)
{
	int a=0;
	cout << "Введите число которое хотите добавить в конец   ";
	cin >> a;
	cout << endl;
	N++;
	for (int i = 0; i < N; i++)
	{
		mas[N-1] = a;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int const  A=100;
	int N, mas[A];
	cout << "Введите количество эллементом массива  " << endl;
	cin >> N;
	cout << endl;
	if (N <= 100)
	{
		initialization(mas, N);//инитиализация 
		print(mas, N);

		remove(mas, N);//удаление первого элемента массива
		cout << "Удаление первого элемента массива" << endl << endl;
		print(mas, N);

		addition(mas, N);//добавление введённого пользователем числа в конец массива
		cout << "Добавление введённого пользователем числа в конец массива" << endl << endl;
		print(mas, N);

		remove(mas, N);
		addition(mas, N);
		cout << "Удаление первого элемента массива и добавление введённого пользователем числа в конец массива" << endl << endl;
		print(mas, N);
	}
	else 
		cout << "Вы ввели число которое превышает реально используемую часть массива" << endl << endl;
	return 0;
}