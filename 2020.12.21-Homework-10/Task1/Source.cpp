#include<iostream>

using namespace std;

int** initMatrix(int dimention)
{
	int** matrix = new int* [dimention] { 0 };
	for (int i = 0; i < dimention; ++i)
	{
		matrix[i] = new int[dimention] { 0 };
	}
	return matrix;
}

void freeMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "введите размер матрицы" << endl;
	cin >> n;
	int** a = initMatrix(n);
	int** b = initMatrix(n);
	int** c = initMatrix(n);
	int** d = initMatrix(n);
	int** e = initMatrix(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = i + 1 + j;
		}
	}
	printMatrix(a, n);
	cout << endl << endl;
	freeMatrix(a, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			b[i][j] = 2 * n - 1 - i - j;
		}
	}
	printMatrix(b, n);
	cout << endl << endl;
	freeMatrix(b, n);

	for (int i = 0; i < n; ++i)
	{
		int k = 1;
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = k;
			k++;
		}
	}
	printMatrix(c, n);
	cout << endl << endl;
	freeMatrix(c, n);

	for (int i = 0; i < n; ++i)
	{
		int k = 1;
		int alarm = -1;
		for (int j = 0; j < n; ++j)
		{
			if (i == j) {
				alarm = 1;
			}
			if (alarm < 0) {
				d[i][j] = k;
				k++;
			}
			else {
				d[i][j] = k;
			}
		}
	}
	printMatrix(d, n);
	cout << endl << endl;
	freeMatrix(d, n);

	int num = 1;
	int mod = 0;
	while (num <= n * n) {

		int  i = mod / 4;
		for (int j = i; j < n - i; ++j) {
			e[i][j] = num;
			num += 1;
		}
		mod += 1;

		int j = n - 1 - mod / 4;
		for (int i = 1 + mod / 4; i < n - mod / 4; ++i) {
			e[i][j] = num;
			num += 1;
		}
		mod += 1;

		i = n - 1 - mod / 4;
		for (int j = n - 2 - mod / 4; j >= mod / 4; --j) {
			e[i][j] = num;
			num += 1;
		}
		mod += 1;

		j = mod / 4;
		for (int i = n - 2 - mod / 4; i > mod / 4; --i) {
			e[i][j] = num;
			num += 1;
		}
		mod += 1;

	}
	printMatrix(e, n);
	freeMatrix(e, n);
	return 0;
}