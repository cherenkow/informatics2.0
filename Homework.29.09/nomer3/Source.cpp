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
	cout << "3 - посчитать среднее арифметическое  факториалов элементов массива" << endl;
}

int fact(int f) {
	if (f == 0) {
		return 1;
	}
	else {
		return f * fact(f - 1);
	}
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



void sortBubble(int* arr, int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
void switchCase(int choice, int& count, int& cap, int*& a) {
	while (choice != 0)
	{
		printMenu();
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "введите новый элемент" << endl;
			int x;
			cin >> x;
			if (count == cap) {
				expandArray(a, cap);
			}
			else {
				a[count] = x;
				count++;
			}
			cout << endl;

			break;
		case 2:
			printArray(a, count);
			cout << endl;
			break;
		case 3:
			int k = 0;
			for (int i = 0; i < count; ++i) {
				k += fact(a[i]);
			};
			cout << float(k) / count << endl << endl;
			break;

		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int cap = 5;
	int count = 0;
	int* a = new int[cap];
	int choice = -1;
	switchCase(choice, count, cap, a);
	return 0;
}