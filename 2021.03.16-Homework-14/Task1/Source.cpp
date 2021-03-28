#include<iostream>
#include <ctime>
#include<clocale>
using namespace std;


void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void fillSequenceUpArray(int* a, int len, int A)
{
	for (int i = 0; i < len; ++i) {
		a[i] = A;
		++A;
	}
}
void fillSequenceDownArray(int* a, int len, int B)
{
	for (int i = 0; i < len; ++i) {
		a[i] = B;
		--B;
	}
}

void fillArray(int* a, int len)
{
	for (int i = 0; i < len; ++i) {
		a[i] = rand() % 90 + 10;
	}
}


void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}


void bubbleSort(int* a, int len, int*& b, int k)
{
	int srav = 0;
	int pere = 0;

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			srav += 1;
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				pere += 1;
			}
		}
	}
	b[k] += srav;
	b[k + 1] += pere;
}

void insertionSort(int* a, int len, int*& c, int k)
{
	int srav = 0;
	int pere = 0;
	int check = 0;
	for (int i = 1; i < len; ++i)
	{
		srav++;
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t)
		{
			srav++;
			pere++;
			a[j] = a[j - 1];
		--j;
			check++;
		}
		if (check > 0) {
			srav--;
			check = 0;
		}
		a[j] = t;
	}
	c[k] += srav;
	c[k + 1] += pere;
}

void selectionSort(int* a, int len, int*& d, int k)
{
	int srav = 0;
	int pere = 0;
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			srav++;
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		if (i != index) {
			swap(a[i], a[index]);
			pere++;
		}
	}
	d[k] += srav;
	d[k + 1] += pere;
}
void expandArray(int*& arr, int& capacity)
{
	int newCapacity = capacity + 5;

	int* temp = new int[newCapacity];
	for (int i = 0; i < capacity; ++i)
	{
		temp[i] = arr[i];
	}

	capacity = newCapacity;
	delete[] arr;
	arr = temp;
}

void shrinkArray(int*& arr, int& capacity)
{
	capacity = 5;
	int* temp = new int[capacity];
	fillArray(temp, capacity);
	delete[] arr;
	arr = temp;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int len = 5;
	int* b = new int[8]{ 0 };
	int* c = new int[8]{ 0 };
	int* d = new int[8]{ 0 };
	int* a = new int[len];

	cout << "Bubble sort" << endl;
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 1000; ++i) {
			fillArray(a, len);
			bubbleSort(a, len, b, j * 2);
		}
		expandArray(a, len);
	}
	for (int i = 0; i < 8; i += 2) {
		float srav = b[i] / 1000;
		float pere = b[i + 1] / 1000;
		cout << "массив длиной " <<i / 2 * 5 + 5 <<": среднее количество сравнений " << srav << " перестановок "<< pere <<endl;
	}
	shrinkArray(a, len);
	cout <<endl<< "Insertion sort" << endl;
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 1000; ++i) {
			fillArray(a, len);
			insertionSort(a, len, c, j * 2);
		}
		expandArray(a, len);
	}
	for (int i = 0; i < 8; i += 2) {
		float srav = c[i] / 1000;
		float pere = c[i + 1] / 1000;
		cout << "массив длиной " << i / 2 * 5 + 5 << ": среднее количество сравнений " << srav << " перестановок " << pere << endl;
	}
	shrinkArray(a, len);

	cout <<endl<< "Selection sort" << endl;
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 1000; ++i) {
			fillArray(a, len);
			selectionSort(a, len, d, j * 2);
		}
		expandArray(a, len);
	}
	for (int i = 0; i < 8; i += 2) {
		float srav = d[i] / 1000;
		float pere = d[i + 1] / 1000;
		cout << "массив длиной " << i / 2 * 5 + 5 << ": среднее количество сравнений " << srav << " перестановок " << pere << endl;
	}
	delete[] a;

	return 0;
}