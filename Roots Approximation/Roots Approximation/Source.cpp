#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
	return (2 * x * x - pow(2, x) - 5);
}

double funcDer(double x) {
	return(4 * x  - pow(2, x));
}

void init(double* arr) {
	for (int i = 0; i < 15; ++i) {
		arr[i] = 0;
	}
	return;
}

void print(double* arr) {
	for (int i = 0; i < 15; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}

bool signCheck(double a, double b) {
	return (a * b < 0);
}

void rootsDivision(double step, double*& arr) {
	double x = -3;
	int k = 0;

	while (x + step <= 7) {
		if (func(x) * func(x + step) < 0) {
			arr[k] = x;
			arr[k + 1] = x + step;
			k = k + 2;
		}
		x = x + step;
	}
	return;
}

void bisectionMet(int numOfRoots, double* arr, double eps) {
	for (int i = 0; i < numOfRoots; ++i) {
		double a = arr[2*i];
		double b = arr[2*i + 1];
		double c = (a + b) / 2;
		while (fabs(func(c)) >= eps) {
			if (signCheck(a, c)) {
				b = c;
				c = (a + b) / 2;
			}
			else {
				a = c;
				c = (a + b) / 2;
			}
		}
		cout << "root is " << c << endl;
	}
	return;
}

double newArg(double x) {
	return(x - func(x)/funcDer(x));
}
/*
void newton(int numOfRoots, double* arr, double eps) {
	for (int i = 0; i < numOfRoots; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		double c = (a + b) / 2;
		while (fabs(func(c)) >= eps) {
			if (signCheck(a, c)) {
				b = c;
				c = (a + b) / 2;
			}
			else {
				a = c;
				c = (a + b) / 2;
			}
		}
		cout << "root is " << c << endl;
	}
	return;
}
*/
int main() {

	setlocale(LC_ALL, "Russian");
	double* ends = new double[15];
	init(ends);
	double n = 10000;
	double A = -3;
	double B = 7;
	double ff = 0;
	double epsilon = 1 / pow(10,3);
	double h = (B - A) / n;

	rootsDivision(h, ends);
	print(ends);
	bisectionMet(3, ends, epsilon);
	
	
	return 0;
}