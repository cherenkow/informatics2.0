#include<iostream>
using namespace std;

double average(int n, ...)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int* ptr = &n + i + 1;
		sum += *ptr;
	}
	double result = (double) sum / n;
	return result;
}

int main()
{
	cout << average(6, 4, 2, 1, 5, 5, 0) << endl;
	return 0;
}

