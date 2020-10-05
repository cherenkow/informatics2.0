#include<iostream>

using namespace std;

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

void printArray(int* arr, int count, int capacity)
{
	cout << "[" << count << "/" << capacity << "]";
	cout << "{";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << (i != count - 1 ? ", " : "");
	}
	cout << "}" << endl;
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

int main(int argc, char* argv[])
{

	int cap = 10;
	int* a = new int[cap];

	int count = 0;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (count == cap) {
			expandArray(a, cap);
		}
		a[count] = x;
		count++;
	}

	printArray(a, count, cap);

	cout << "SUM = " << sumArray(a, count) << endl;

	delete[] a;
	return EXIT_SUCCESS;
}