#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <ctime>
using namespace std;


int** initMatrix(int n, int m)
{
	int** matrix = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m] { 0 };
	}
	return matrix;
}

void printMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
}

void fillMatrix(int** matrix, int n, int m) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = rand() % 2;
		}
		
	}
}

int count(int** mx, int ii, int jj, int n, int m) {
	//left up
	if (ii == 0 && jj == 0) {
		return mx[0][1] + mx[1][0] + mx[1][1];
	}
	//right up
	if (ii == 0 && jj == m-1) {
		return mx[0][m-2] + mx[1][m-1] + mx[1][m-2];
	}
	//left down
	if (ii == n-1 && jj == 0) {
		return mx[n-2][0] + mx[n-1][1] + mx[n-2][1];
	}
	//right down
	if (ii == n-1 && jj == m-1) {
		return mx[n-1][m-2] + mx[n-2][m-2] + mx[n-2][m-1];
	}
	//up
	if (ii == 0) {
		return mx[0][jj-1] + mx[0][jj+1] + mx[1][jj-1] + mx[1][jj] + mx[1][jj+1];
	}
	//down
	if (ii == n-1) {
		return mx[n-1][jj-1] + mx[n-1][jj+1] + mx[n-2][jj-1] + mx[n-2][jj] + mx[n-2][jj+1];
	}
	//left
	if (jj == 0) {
		return mx[ii-1][0] + mx[ii+1][0] + mx[ii-1][1] + mx[ii][1] + mx[ii+1][1];
	}
	//right
	if (jj == m-1) {
		return mx[ii-1][m-1] + mx[ii+1][m-1] + mx[ii-1][m-2] + mx[ii][m-2] + mx[ii+1][m-2];
	}

	return mx[ii-1][jj-1] + mx[ii-1][jj] + mx[ii-1][jj+1] + mx[ii+1][jj -1] + mx[ii+1][jj] + mx[ii+1][jj+1] + mx[ii][jj-1] + mx[ii][jj+1];
}

void sumMatrix(int**& a, int** b, int n, int m) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] += b[i][j];
		}

	}
}

int** game(int** mx, int n, int m) {
	int** result = initMatrix(n, m);
	
#pragma omp parallel sections
	{
#pragma omp section
		{
			int** result1 = initMatrix(n,m);
			for (int i = 0; i < n/2; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (mx[i][j] == 1 && count(mx, i, j, n, m) != 3) {
						result1[i][j] = 0;
						continue;
					}
					if (mx[i][j] == 0 && count(mx, i, j, n, m) == 3) {
						result1[i][j] = 1;
						continue;
					}
					result1[i][j] = mx[i][j];
				}

			}
#pragma omp atomic
			sumMatrix(result, result1, n, m);
		}
#pragma omp section
		{
			int** result2 = initMatrix(n, m);
			for (int i = n/2; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (mx[i][j] == 1 && count(mx, i, j, n, m) != 3) {
						result2[i][j] = 0;
						continue;
					}
					if (mx[i][j] == 0 && count(mx, i, j, n, m) == 3) {
						result2[i][j] = 1;
						continue;
					}
					result2[i][j] = mx[i][j];
				}

			}
#pragma omp atomic
			sumMatrix(result, result2, n, m);
		}
	}
	return result;
}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n;
	cin >> m;
	int** a = initMatrix(n,m);
	fillMatrix(a, n, m);
	printMatrix(a,n,m);
	cout << endl << "after" << endl;
	printMatrix(game(a, n, m), n, m);


	return EXIT_SUCCESS;
}