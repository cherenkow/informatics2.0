#include<iostream>
#include<clocale>
using namespace std;
void printMenu()
{
	cout << "выберете действия" << endl;
	cout << "" << endl;
	cout << "0 - выход" << endl;
	cout << "1 - добавить элемент" << endl;
	cout << "2 - вывести массив" << endl;
	cout << "3 - нaйти номер максимального элемента" << endl;
	cout << "4 - найти минимальный элемент" << endl;
	cout << "5 - сумма элементов массива " << endl;
	cout << "6 - вывести массив в обратном порядкe" << endl;
	cout << endl;
}


int maxEl(int*& arr, int& count)
{
	int t = 0;
	for (int i = 1; i < count; ++i) {
		if (arr[t] < arr[i]) {
			t = i;
		}
	}
	return t;

}

int minEl(int*& arr, int& count)
{
	int t = arr[0];
	for (int i = 1; i < count; ++i) {
		if (t > arr[i]) {
			t = arr[i];
		}
	}
	return t;

}

void expandArray(int*& arr, int& capacity)
{
	int newCapacity = capacity * 2;

	int* temp = new int[newCapacity];
	for (int i = 0; i < capacity; ++i)
	{
		temp[i] = arr[i];
	}

	capacity = newCapacity;
	delete[] arr;
	arr = temp;
}

void printArray(int* arr, int count)
{
	cout << "{ ";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "}" << endl;
}

void printBackArray(int* arr, int count)
{
	cout << "{ ";
	for (int i = count - 1; i >= 0; --i)
	{
		cout << arr[i] << " ";
	}
	cout << "}" << endl << endl;
}
int sumArray(int* arr, int length)
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result += arr[i];
	}
	return result;
}
void newEl(int*& arr, int& count,int& cap, int x) {
	if (count == cap) {
		expandArray(arr, cap);
	}
	arr[count] = x;
	count++;

}


void switchCase(int choice, int& count, int& cap, int*& a) {
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "введите новый элемент" << endl;
		int x;
		cin >> x;
		newEl(a, count,cap, x);
		cout << endl;
		break;
	case 2:
		printArray(a, count);
		cout << endl;
		break;
	case 3:
		cout << "индекс макс элемента: " << maxEl(a, count) << endl << endl; ;
		break;
	case 4:
		cout << "минимальный элемент: " << minEl(a, count) << endl << endl;;
		break;
	case 5:
		cout << "сумма элементов массива: " << sumArray(a, count) << endl << endl; ;
		break;
	case 6:
		printBackArray(a, count);
	case 0:
		break;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");

	int cap = 5;
	int count = 0;
	int* a = new int[cap];
	int choice = -1;
	while (choice!=0)
	{
		printMenu();
		cin >> choice;
		switchCase(choice, count, cap, a);
	}
	return 0;
}