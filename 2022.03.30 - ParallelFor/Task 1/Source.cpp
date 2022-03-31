#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <cmath>
using namespace std;

double pi = acos(-1);

double* sinC = new double[10000000];
double* sinP = new double[10000000];

//задание 1 
void sinCons(int n)
{
	double t = omp_get_wtime();
#pragma omp parallel for schedule(static, 20000)
	for (int i = 0; i <= n; ++i)
	{
		sinC[i] = sin(pi * i / (2.0 * n));
	}
	cout << "Time static: " << omp_get_wtime() - t << endl;

	double t1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 20000)
	for (int i = 0; i <= n; ++i)
	{
		sinC[i] = sin(pi * i / (2.0 * n));
	}
	cout << "Time dynamic: " << omp_get_wtime() - t1 << endl;

	double t2 = omp_get_wtime();
#pragma omp parallel for schedule(guided, 20000)
	for (int i = 0; i <= n; ++i)
	{
		sinC[i] = sin(pi * i / (2.0 * n));
	}
	cout << "Time guided: " << omp_get_wtime() - t2 << endl;

	double t3 = omp_get_wtime();
	for (int i = 0; i <= n; ++i)
	{
		sinC[i] = sin(pi * i / (2.0 * n));
	}
	cout << "Time posl: " << omp_get_wtime() - t3 << endl;
}

//задание 2
double func(double x) {
	return (1 / (1 + x * x));
}

double piCons(int n)
{
	double sum = 0;
	double t = omp_get_wtime();
#pragma omp parallel for schedule(static, 20000) reduction(+: sum)
	for (int i = 1; i <= n; ++i)
	{
		sum += func((double(2) * i - 1) / (double(2) * n));
	}
	cout << "Time static: " << omp_get_wtime() - t << endl;

	double t1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 20000) reduction(+: sum)
	for (int i = 1; i <= n; ++i)
	{
		sum += func((double(2) * i - 1) / (double(2) * n));
	}
	cout << "Time dynamic: " << omp_get_wtime() - t1 << endl;

	double t2 = omp_get_wtime();
#pragma omp parallel for schedule(guided,20000) reduction(+: sum)
	for (int i = 1; i <= n; ++i)
	{
		sum += func((double(2) * i - 1) / (double(2) * n));
	}
	cout << "Time guided: " << omp_get_wtime() - t2 << endl;

	double t3 = omp_get_wtime();
	for (int i = 1; i <= n; ++i)
	{
		sum += func((double(2) * i - 1) / (double(2) * n));
	}
	cout << "Time posl: " << omp_get_wtime() - t3 << endl;

	return sum / n;
}


//задание 3
bool isPrime(int n)
{
	if (n == 1) return false;
	if (n % 2 == 0 && n != 2)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int numberOfPrimes(int n) {
	int count = 0;
	double t = omp_get_wtime();
#pragma omp parallel for schedule(static, 20000) reduction(+:count)
	for (int i = 1; i <= n; i += 2)
	{
		count += isPrime(i);
	}
	cout << "Time static: " << omp_get_wtime() - t << endl;

	double t1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 20000) reduction(+:count)
	for (int i = 1; i <= n; i += 2)
	{
		count += isPrime(i);
	}
	cout << "Time dynamic: " << omp_get_wtime() - t1 << endl;

	double t2 = omp_get_wtime();
#pragma omp parallel for schedule(guided, 20000) reduction(+:count)
	for (int i = 1; i <= n; i += 2)
	{
		count += isPrime(i);
	}
	cout << "Time guided: " << omp_get_wtime() - t2 << endl;

	
	return count / 3;
}


//задание 4
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
	if (ii == 0 && jj == m - 1) {
		return mx[0][m - 2] + mx[1][m - 1] + mx[1][m - 2];
	}
	//left down
	if (ii == n - 1 && jj == 0) {
		return mx[n - 2][0] + mx[n - 1][1] + mx[n - 2][1];
	}
	//right down
	if (ii == n - 1 && jj == m - 1) {
		return mx[n - 1][m - 2] + mx[n - 2][m - 2] + mx[n - 2][m - 1];
	}
	//up
	if (ii == 0) {
		return mx[0][jj - 1] + mx[0][jj + 1] + mx[1][jj - 1] + mx[1][jj] + mx[1][jj + 1];
	}
	//down
	if (ii == n - 1) {
		return mx[n - 1][jj - 1] + mx[n - 1][jj + 1] + mx[n - 2][jj - 1] + mx[n - 2][jj] + mx[n - 2][jj + 1];
	}
	//left
	if (jj == 0) {
		return mx[ii - 1][0] + mx[ii + 1][0] + mx[ii - 1][1] + mx[ii][1] + mx[ii + 1][1];
	}
	//right
	if (jj == m - 1) {
		return mx[ii - 1][m - 1] + mx[ii + 1][m - 1] + mx[ii - 1][m - 2] + mx[ii][m - 2] + mx[ii + 1][m - 2];
	}

	return mx[ii - 1][jj - 1] + mx[ii - 1][jj] + mx[ii - 1][jj + 1] + mx[ii + 1][jj - 1] + mx[ii + 1][jj] + mx[ii + 1][jj + 1] + mx[ii][jj - 1] + mx[ii][jj + 1];
}
void assignMatrix(int**& a, int** b, int n, int m) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = b[i][j];
		}

	}
}

int** game(int**& mx, int n, int m, int k) {
	int** result = initMatrix(n, m);
	for (int l = 0; l < k; ++l)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (mx[i][j] == 1 && (count(mx, i, j, n, m) > 3 || count(mx, i, j, n, m) < 2)) {
					result[i][j] = 0;
					continue;
				}
				if (mx[i][j] == 0 && count(mx, i, j, n, m) == 3) {
					result[i][j] = 1;
					continue;
				}
			}

		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				mx[i][j] = result[i][j];
			}

		}
	}

	return mx;
}
int main()
{
	int n = 0;
	cin >> n;
	cout << "Task 1" << endl;
	sinCons(n);
	cout << endl << "Task 2" << endl;
	cout << piCons(n) << endl;
	cout << endl << "Task 3" << endl;
	cout << numberOfPrimes(n) << endl;

	return EXIT_SUCCESS;
}