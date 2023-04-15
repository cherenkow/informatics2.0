#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x) {
	return exp(3 * x) + sin(2 * x) + x;
}
double Func(double a, double b) {
	return ((exp(3 * b) - exp(3 * a)) / 3 - (cos(2 * b) - cos(2 * a)) / 2 + (b * b - a * a) / 2);
}
double dfunc(double x) {
	return 3 * exp(3 * x) + 2 * cos(2 * x) + 1;
}
double d2func(double x) {
	return 9 * exp(3 * x) - 4 * sin(2 * x);
}
double d4func(double x) {
	return 81* exp(3 * x) + 16*sin(2 * x);
}

double func1(double x) {
	return 1;
}
double Func1(double a, double b) {
	return (b - a);
}

double func2(double x) {
	return (2 * x + 1);
}
double Func2(double a, double b) {
	return ((b * b - a * a) + b - a);
}

double func3(double x) {
	return (3 * pow(x, 2) + 2 * x + 1);
}
double Func3(double a, double b) {
	return ((pow(b, 3) - pow(a, 3)) + (b * b - a * a) + b - a);
}

double func4(double x) {
	return (4 * pow(x, 3) + 3 * pow(x, 2) + 2 * x + 1);
}
double Func4(double a, double b) {
	return ((pow(b, 4) - pow(a, 4)) + (pow(b, 3) - pow(a, 3)) + (b * b - a * a) + b - a);
}


void leftRec(int m, double exact, double a, double b, double (*foo)(double)) {
	cout << endl << "формула левого прямоугольника" << endl;
	double h = (b - a) / m;
	double res = foo(a);
	for (int i = 1; i < m; ++i) {
		res += foo(a + h * i);
	}
	res *= h;
	cout << "полученное значение: " << res << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(res - exact) << endl;
}

void rightRec(int m, double exact, double a, double b, double (*foo)(double)) {
	cout << endl << "формула правого прямоугольника" << endl;
	double h = (b - a) / m;
	double res = foo(b);
	for (int i = 1; i < m; ++i) {
		res += foo(a + h * i);
	}
	res *= h;
	cout << "полученное значение: " << res << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(res - exact) << endl;
}

void middleRec(int m, double exact, double a, double b, double (*foo)(double)) {
	cout << endl << "формула среднего прямоугольника" << endl;
	double h = (b - a) / m;
	double res = 0;
	for (int i = 0; i < m; ++i) {
		res += foo(a + h * i + h / 2);
	}
	res *= h;
	cout << "полученное значение: " << res << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(res - exact) << endl;
}

void trap(int m, double exact, double a, double b, double (*foo)(double)) {
	cout << endl << "формула трапеции" << endl;
	double h = (b - a) / m;
	double res = foo(a) + foo(b);
	for (int i = 1; i < m; ++i) {
		res += 2 * foo(a + h * i);
	}
	res *= (h / 2);
	cout << "полученное значение: " << res << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(res - exact) << endl;
}

void Simpson(int m, double exact, double a, double b, double (*foo)(double)) {
	cout << endl << "формула Симпсона " << endl;
	double h = (b - a) / m;
	double res = foo(a) + foo(b);
	for (int i = 1; i < m; ++i) {
		res += 2 * foo(a + h * i);
	}
	for (int i = 0; i < m; ++i) {
		res += 4 * foo(a + h * i + h / 2);
	}
	res *= (h / 6);
	cout << "полученное значение: " << res << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(res - exact) << endl;
}

double maxF(double a, double b, double (*foo)(double)) {
	double x = a;
	double h = (b - a) / 10000;
	for (int i = 0; i <= 10000;++i) {
		if (fabs(foo(x)) < fabs(foo(a + i * h))) {
			x = a + i * h;
		}
	}
	return fabs(foo(x));
}

int main() {
	cout << setprecision(10);
	setlocale(LC_ALL, "Russian");
	cout << "ЗАДАЧА ЧИСЛЕННОГО ИНТЕГРИРОВАНИЯ" << endl;

	cout << "введите концы отрещка интегрирования" << endl;
	double a = 0;
	double b = 0;
	cin >> a;
	cin >> b;
	cout << "введите количсетво отрезков разбиения" << endl;
	int m = 0;
	cin >> m;
	//exact values
	double f = Func(a, b);
	double f1 = Func1(a, b);
	double f2 = Func2(a, b);
	double f3 = Func3(a, b);
	double f4 = Func4(a, b);

	cout << endl << "ОТЛАДКА СОСТАВНЫХ КФ " << endl;

	leftRec(m, f1, a, b, func1);
	rightRec(m, f1, a, b, func1);
	middleRec(m, f2, a, b, func2);
	trap(m, f2, a, b, func2);
	Simpson(m, f4, a, b, func4);

	cout << endl << "ИНТЕГРИРОВАНИЕ ФУНКЦИИ f(x) = exp(3 * x) + sin(2 * x) + x " << endl;

	leftRec(m, f, a, b, func);
	cout << "теоретическая оценка погрешности: " << pow(b-a, 2)/(2*m)*maxF(a,b,dfunc)<< endl<<endl;
	rightRec(m, f, a, b, func);
	cout << "теоретическая оценка погрешности: " << pow(b - a, 2) / (2 * m) * maxF(a, b, dfunc) << endl << endl;
	middleRec(m, f, a, b, func);
	cout << "теоретическая оценка погрешности: " << pow(b - a, 3) / (24 * m*m) * maxF(a, b, d2func) << endl << endl;
	trap(m, f, a, b, func);
	cout << "теоретическая оценка погрешности: " << pow(b - a, 3) / (12 * m * m) * maxF(a, b, d2func) << endl << endl;
	Simpson(m, f, a, b, func);
	cout << "теоретическая оценка погрешности: " << pow(b - a, 5) / (2880 * pow(m, 4)) * maxF(a, b, d4func) << endl << endl;


	return 0;
}