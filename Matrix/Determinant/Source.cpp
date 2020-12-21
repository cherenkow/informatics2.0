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

void randomizeMatrix(int** matrix, int dimention, int a = -9, int b = 9)
{
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			matrix[i][j] = rand() % (b - a + 1) + a;
		}
	}
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

int** sumMatrix(int** a, int** b, int dimention)
{
	int** result = initMatrix(dimention);
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			result[i][j] = a[i][j] + b[i][j];
		}
	}
	return result;
}

int determinant2(int** a)
{
	return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

int determinant3(int** a)
{
	int result = 0;
	result += a[0][0] * a[1][1] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
	result += a[0][1] * a[1][2] * a[2][0] - a[0][1] * a[1][0] * a[2][2];
	result += a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0];
	return result;
}

int** minorMatrix(int** a, int dimention, int row, int column)
{
	int** result = initMatrix(dimention - 1);
	for (int i = 0, ii = 0; i < dimention; ++i, ++ii)
	{
		if (i == row)
		{
			--ii;
			continue;
		}
		for (int j = 0, jj = 0; j < dimention; ++j, ++jj)
		{
			if (j == column)
			{
				--jj;
				continue;
			}
			result[ii][jj] = a[i][j];
		}
	}
	return result;
}

int determinant(int** a, int dimention)
{
	if (dimention == 1)
	{
		return a[0][0];
	}
	int result = 0;
	for (int i = 0; i < dimention; ++i)
	{
		int** minorM = minorMatrix(a, dimention, 0, i);
		int sign = (i % 2 == 0 ? 1 : -1);
		result += determinant(minorM, dimention - 1) * sign * a[0][i];
		freeMatrix(minorM, dimention - 1);
	}
	return result;
}

int main()
{
	const int DIM = 3;
	int** a = initMatrix(DIM);
	randomizeMatrix(a, DIM);

	printMatrix(a, DIM);
	cout << determinant(a, DIM) << endl;
	cout << determinant3(a) << endl;

	freeMatrix(a, DIM);

	return 0;
}