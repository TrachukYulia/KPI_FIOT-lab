#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>


using namespace std;

//================ПРОТОТИПИ Ф-ЦІЙ==================

int** create(int); //створення масиву
void input(int**, int);//заповнення масиву рандомними числами 
int input_size(int&);//задання розміру
void output(int**, int);//виведення масиву
void peretvorenya(int **, int);//перетворення масиву
void swap_number(int&, int&);//заміна елементів(чисел)
void delete_m(int**, int);//звільнення пам'яті
void  peresechenia_d(int**, int);//знаходження елемента на перетині діагоналей

//================ГОЛОВНА Ф-ЦІЯ====================

int main()
{
	setlocale(LC_ALL, "Ukr");
	cout << "Трачук Юлiя IС-01, Лабараторна №8" << endl;

	int n = input_size(n);//розмір масиву
	int** arr = create(n);//створення масиву
	input(arr, n);//заповнення масиву радомними числами
	cout << "Початкова матриця:" << endl; output(arr, n);//виведення 
	cout << "Число на перетинi дiагоналей: ";  peresechenia_d(arr, n);//виведення елементу на перетині діагоналей
	cout << "Матриця пiсля перетворення:" << endl; peretvorenya(arr, n); output(arr, n);// перетворення: виклик ф-ції для перетворення та ф-ції виведення масиву 

    delete_m(arr, n);//ф-ції звільнення пам'яті

}
int input_size(int& size) //задання розміру
{ 
    do	
	{
		cout << "Введiть; рoзмiр матрицi(n x n): "; cin >> size;
	} 
	while (size <= 0);
	cout << endl;
	return size;
}
int** create(int size)//створення масиву
{
	int** array = new int* [size];//створення динамічного двовимірного масиву (виділення пам'яті під масив покажчиків)
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];//виділення пам'яті під масив
	}
	return array;
}
void input(int **array, int size)//заповнення масиву рандомними числами 
{
	for (int i = 0; i < size; i++)//строки
	{
		for (int j = 0; j < size; j++)//колонки
			array[i][j] = rand() % 20+1;//заповнення масиву числами в діпазоні [1;20]
	}
}

void output(int** array, int size)//виведення масиву
{
	for (int i = 0; i < size; i++)//строки
	{
		for (int j = 0; j < size; j++)//колонки
		{
			cout << setw(4) << array[i][j];
		}
		cout << setw(4) << endl;
	}
	cout << endl;
}
void peretvorenya(int** array, int size)//перетворення масиву
{
	for (int i = 0; i < size / 2; i++)//до половини строк
	{
		for (int j = 0; j < size; j++)//колонки
		{
			if (i <= j && j + i <= size - 1) //для елементів, що лежать вище головної діагноалі + вище побічної(включно) 
				swap_number(array[i][j], array[size - i - 1][j]);//обмін елементів матриці			
		}
	}
	int** arr2 = create(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			arr2[i][j] = array[i][j];
	}
}

void swap_number(int& n1, int& n2)//заміна елементів(чисел)
{
	int temp = n1; //тимчасова змінна для обміну елементів
	n1 = n2; //n1 - елемент із верхньої, n2- елемент із нижньої частини
	n2 = temp;
}

void peresechenia_d(int **array, int size)//знаходження елемента на перетині діагоналей
{ 
	if (size % 2 != 0)//якщо ми маємо розмір не кратний 2

		cout << array[size / 2][size / 2] << endl; //виводимо центральний елемент 
	else
		cout << "дiагоналi не перетинаються в точцi, де наявне число, оскiльки введено розмiр кратний 2" << endl;
	cout << endl;
}
void delete_m(int** array, int size)//звільнення пам'яті
{
	for (int i = 0; i < size; i++)
	{
		delete[] array[i];
	}
	delete [] array;
}
