#include<iostream>
#include<clocale>
using namespace std;
void printMenu()
{
	cout << "�������� ��������" << endl;
	cout << "" << endl;
	cout << "0 - �����" << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� ������" << endl;
	cout << "3 - ��������� ������� ��������������  ����������� ��������� �������" << endl;
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

int countF(int* arr, int count) {
	int k = fact(arr[0]);
	int t = k;
	for (int i = 1; i < count; ++i) {
		if (arr[i] != arr[i - 1]) {
			for (int j = arr[i - 1] + 1; j <= arr[i]; ++j) {
				t *= j;
			}
		}
		k += t;
	}
	return k;
}

void switchCase(int choice, int& count, int& cap, int*& a) {
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "������� ����� �������" << endl;
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
		sortBubble(a, count);
		cout << float(countF(a,count)) / count << endl << endl;
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
	while (choice != 0)
	{
		printMenu();
		cin >> choice;
		switchCase(choice, count, cap, a);
	}
	return 0;
}