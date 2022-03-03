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
	for (int i = 0; i <= n; ++i)
	{
		sinC[i] = sin(pi * i / (2 * n));
	}
	cout << "Time cons: " << omp_get_wtime() - t << endl;
}

void sinPar(int n)
{
	double t = omp_get_wtime();
#pragma omp parallel sections
	{
#pragma omp section
		{
			for (int i = 0; i < n / 2; i++)
			{
				sinC[i] = sin(pi * i / (2 * n));
			}
		}
#pragma omp section
		{
			for (int i = n / 2; i <= n; i++)
			{
				sinC[i] = sin(pi * i / (2 * n));
			}
		}
	}
	cout << "Time par: " << omp_get_wtime() - t << endl;
}

//задание 2
double func(double x) {
	return (1 / (1 + x * x));
}

double piCons(int n)
{
	double t = omp_get_wtime();
	double sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += func(((2 * i - 1.0) /  (2 * n)));
	}
	cout << "Time cons: " << omp_get_wtime() - t << endl;
	return (4 * sum) / n;
}

double piPar(int n)
{
	double t = omp_get_wtime();
	double sum = 0;
#pragma omp parallel sections reduction(+:sum)
	{
#pragma omp section
		{
			for (int i = 0; i < n/2; i++)
				sum += func(((2 * i - 1.0) / (2 * n)));		}
#pragma omp section
		{
			for (int i = n/2; i <= n ; i++)
				sum += func(((2 * i - 1.0) / (2 * n)));
		}
	}
	cout << "Sum: " << (4*sum) / n  << endl;
	cout << "Time: " << omp_get_wtime() - t << endl;
	return 0;
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
	double t = omp_get_wtime();
	double sum = 0;
	
#pragma omp parallel sections reduction(+:sum)
	{
#pragma omp section
		{
			for (int i = 3; i <= n; i += 4)
				(isPrime(i) ? sum += 1 : 0);
		}
#pragma omp section
			{
			for (int i = 5; i <= n; i += 4)
					(isPrime(i) ? sum += 1 : 0);
			}
		}
		cout << "Sum: " << sum << endl;
		cout << "Time: " << omp_get_wtime() - t << endl;
		return 0;
	}

int main()
{
	int n = 0;
	cin >> n;
	sinCons(n);
	sinPar(n);
	cout << piCons(n) << endl;
    cout << piPar(n) << endl;
	cout << numberOfPrimes(n) << endl;

	return EXIT_SUCCESS;
}