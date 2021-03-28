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

void quickSort(int* arr, int len) {
	int i = 0;
	int j = len - 1;
	int mid = arr[len / 2];

	while (i <= j) {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (j > 0) {
		quickSort(arr, j + 1);
	}
	if (i < len) {
		quickSort(&arr[i], len - i);
	}
}

int findMax(int* arr, int len) {
	int k = arr[0];
	for (int i = 1; i < len; ++i) {
		if (arr[i] > k) {
			k = arr[i];
		}
	}
	return k;
}

void countingSort(int* arr, int len) {
	int  k = findMax(arr, len);
	int* c = new int[k + 1]{ 0 };
	for (int i = 0; i < len; ++i) {
		++c[arr[i]];
	}
	int b = 0;
	for (int i = 0; i < k + 1; ++i) {
		for (int j = 0; j < c[i]; ++j) {
			arr[b++] = i;
		}
	}
}

int* arrayFusion(int* arr, int* brr, int len1, int len2) {
	int i = 0;
	int j = 0;
	int* c = new int[len1 + len2];
	for (int k = 0; k < len1 + len2; ++k) {
		if (i < len1 && j < len2) {
			if (arr[i] < brr[j]) {
				c[k] = arr[i];
				i++;
				continue;
			}
			else {
				c[k] = brr[j];
				j++;
				continue;
			}
		}
		if (i == len1) {
			c[k] = brr[j];
			j++;
			continue;
		}
		if (j == len2) {
			c[k] = arr[i];
			i++;
			continue;
		}
	}
	return c;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int len1 = 0;
	int len2 = 0;
	cout << "введите длину первого массива" << endl;
	cin >> len1;
	cout << "введите длину второго массива" << endl;
	cin >> len2;
	int* a = new int[len1] { 0 };
	int* b = new int[len2] { 0 };
	cout << "быстрая сортировка" << endl;
	fillArray(a, len1);
	printArray(a, len1);
	quickSort(a, len1);
	printArray(a, len1);

	cout << "сортировка подсчетом" << endl;
	fillArray(b, len2);
	printArray(b, len2);
	countingSort(b, len2);
	printArray(b, len2);

	cout << "слияние массивов" << endl;
	int* c = arrayFusion(a, b, len1, len2);
	printArray(c, len1 + len2);

	return 0;
}