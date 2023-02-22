#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
	return (2 * x * x - pow(2, x) - 5);
}

double funcDer(double x) {
	return(4 * x - pow(2, x));
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
	cout << "результат отделения корней:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "[" << arr[2 * i] << ";" << arr[2 * i + 1] << "]  ";
	}
	cout << endl << "всего промежутков: 3" << endl <<endl;
	return;
}

void bisectionMet(int numOfRoots, double* arr, double eps) {
	cout << "Bisection Method" << endl;
	for (int i = 0; i < numOfRoots; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		double c = (a + b) / 2;
		int counter = 0;
		cout << "Начальное приближение:" << c << endl;
		while (b - a >= 2 * eps) {
			if (signCheck(a, c)) {
				b = c;
				c = (a + b) / 2;
			}
			else {
				a = c;
				c = (a + b) / 2;
			}
			counter++;
		}
		cout << "Количество итераций: " << counter << endl;
		cout << "Найденное приближенное значение корня:" << c << endl;
		cout << "Длина последнего отрезка: " << (b - a) << endl;
		cout << "Неувязка: " << fabs(func(c)) << endl << endl;
	}
	return;
}

double newArg(double x) {
	return(x - func(x) / funcDer(x));
}

void newtonMet(int numOfRoots, double* arr, double eps) {
	cout << "Newton Method" << endl;
	for (int i = 0; i < numOfRoots; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		double c0 = 0;
		double c1 = (a + b) / 2;
		int counter = 0;
		cout << "Начальное приближение:" << c1 << endl;
		while (fabs(c1 - c0) >= eps) {
			c0 = c1;
			c1 = newArg(c0);
			counter++;
		}
		cout << "Количество итераций: " << counter << endl;
		cout << "Найденное приближенное значение корня:" << c1 << endl;
		cout << "Погрешность: " << fabs(c1-c0) << endl;
		cout << "Неувязка: " << fabs(func(c1)) << endl << endl;
	}
	return;
}

double newArgMod(double x, double x0) {
	return(x - func(x) / funcDer(x0));
}

void newtonMetMod(int numOfRoots, double* arr, double eps) {
	cout << "Modified Newton Method" << endl;
	for (int i = 0; i < numOfRoots; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		double c0 = 0;
		double c1 = (a + b) / 2;
		int counter = 0;
		cout << "Начальное приближение:" << c1 << endl;
		while (fabs(c1 - c0) >= eps) {
			c0 = c1;
			c1 = newArgMod(c0, (a + b) / 2);
			counter++;
		}
		cout << "Количество итераций: " << counter << endl;
		cout << "Найденное приближенное значение корня:" << c1 << endl;
		cout << "Погрешность: " << fabs(c1 - c0) << endl;
		cout << "Неувязка: " << fabs(func(c1)) << endl << endl;
	}
	return;
}

double newArgSec(double x2, double x1) {
	return(x2 - func(x2) * (x2 - x1) / (func(x2) - func(x1)));
}

void secantMet(int numOfRoots, double* arr, double eps) {
	cout << "Secant Method" << endl;
	for (int i = 0; i < numOfRoots; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		int temp = 0;
		int counter = 0;
		cout << "Начальное приближение:" << b << endl;
		while (fabs(b - a) >= eps) {
			int temp = a;
			a = b;
			b = newArgSec(a, temp);
			counter++;
		}
		cout << "Количество итераций: " << counter << endl;
		cout << "Найденное приближенное значение корня:" << b << endl;
		cout << "Погрешность: " << fabs(b - a) << endl;
		cout << "Неувязка: " << fabs(func(b)) << endl << endl;
	}
	return;
}

int main() {

	setlocale(LC_ALL, "Russian");
	double* ends = new double[15];
	init(ends);
	double n = 10000;
	double A = -3;
	double B = 7;
	double ff = 0;
	double epsilon = 1 / pow(10, 5);
	double h = (B - A) / n;
	cout << "НАХОЖДЕНИЕ ПРИБЛИЖЕННЫХ ЗНАЧЕНИЙ КОРНЕЙ НЕЛИНЕЙНОГО УРАНВЕНИЯ" << endl << endl;
	cout << "Исходные параметры задачи:" << endl << endl;
	cout << "Отрезок: [-3;7]  Функция: f(x) = x^2 - 2^x -5  Точность: е = 10^-5" << endl << endl;

	rootsDivision(h, ends);
	
	bisectionMet(3, ends, epsilon);
	newtonMet(3, ends, epsilon);
	newtonMetMod(3, ends, epsilon);
	secantMet(3, ends, epsilon);
	return 0;
}