#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <ctime>
#include <math.h>
using namespace std;

int const n = 5;
double** initMatrix()
{
	double** matrix = new double* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double[n + 1]{ 0 };
	}
	return matrix;
}

void printMatrix(double** matrix)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			printf("%10lf ", matrix[i][j]);
		}
		cout << endl;
	}
}

void fillMatrix(double** matrix) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			matrix[i][j] = rand();
		}

	}
}

void divide(double** a, int k, double el) {
	for (int i = 0; i < n + 1; ++i) {
		a[k][i] = a[k][i] / el;
	}
}
void subtract(double** a, int k1, int k2, double el) {
	for (int i = 0; i < n + 1; ++i) {
		a[k2][i] = a[k2][i] - a[k1][i] * el;
	}
}
void swapStrings(double** a, int k1, int k2)
{
	for (int i = 0; i < n + 1; ++i)
	{
		double temp = a[k1][i];
		a[k1][i] = a[k2][i];
		a[k2][i] = temp;
	}
}
double findMax(double** a, int j, int lim)
{
	//добавить сравнениие по модулю через fabs
	double max = fabs(a[lim][j]);
	int maxi = lim;
	for (int i = lim; i < n; ++i) {
		if (fabs(a[i][j]) > fabs(max)) {
			max = a[i][j];
			maxi = i;
		}
	}
	return maxi;
}
void GaussJordan(double**& a)
{

	for (int i = 0; i < n; ++i) {
		int  maxi = findMax(a, i, i);
		swapStrings(a, i, maxi);
		divide(a, i, a[i][i]);
#pragma omp parallel for schedule(dynamic, 2)
		for (int j = 0; j < n; j++)
		{
			if (j != i) {
				subtract(a, i, j, a[j][i]);
			}
		}
	}
}
int main()
{
	double** a = initMatrix();
	fillMatrix(a);
	printMatrix(a);
	cout << endl;
	GaussJordan(a);
	printMatrix(a);
	return 0;
}