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



double leftRec(double a, double b, double (*foo)(double)) {
	return (foo(a) * (b - a));
}

double rightRec(double a, double b, double (*foo)(double)) {
	return (foo(b) * (b - a));
}

double middleRec(double a, double b, double (*foo)(double)) {
	return (foo((a + b) / 2) * (b - a));
}

double trap(double a, double b, double (*foo)(double)) {
	return ((foo(a) + foo(b)) * (b - a) / 2);
}

double Simpson(double a, double b, double (*foo)(double)) {
	return ((foo(a) + 4 * foo((a + b) / 2) + foo(b)) * (b - a) / 6);
}

double threeEights(double a, double b, double (*foo)(double)) {
	double h = (b - a) / 3;
	return ((foo(a) + 3 * (foo(a + h) + foo(a + 2 * h)) + foo(b)) * (b - a) / 8);
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
	//exact values
	double f = Func(a, b);
	double f1 = Func1(a, b);
	double f2 = Func2(a, b);
	double f3 = Func3(a, b);
	double f4 = Func4(a, b);

	cout << endl << "ОТЛАДКА Кф" << endl;

	cout << "формула левого прямоугольника" << endl;
	double test1 = leftRec(a, b, func1);
	cout << "полученное значение: " << test1 << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(test1 - f1) << endl << endl;

	cout << "формула правого прямоугольника" << endl;
	double test2 = rightRec(a, b, func1);
	cout << "полученное значение: " << test2 << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(test2 - f1) << endl << endl;

	cout << "формула среднего прямоугольника" << endl;
	double test3 = middleRec(a, b, func2);
	cout << "полученное значение: " << test3 << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(test3 - f2) << endl << endl;

	cout << "формула трапеции" << endl;
	double test4 = trap(a, b, func2);
	cout << "полученное значение: " << test4 << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(test4 - f2) << endl << endl;

	cout << "формула Симпсона " << endl;
	double test5 = Simpson(a, b, func4);
	cout << "полученное значение: " << test5 << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(test5 - f4) << endl << endl;


	cout << endl << "ИНТЕГРИРОВАНИЕ ФУНКЦИИ f(x) = exp(3 * x) + sin(2 * x) + x " << endl;
	double ff = 0;

	cout << "формула левого прямоугольника" << endl;
	ff = leftRec(a, b, func);
	cout << "полученное значение: " << ff << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(ff - f) << endl << endl;

	cout << "формула правого прямоугольника" << endl;
    ff = rightRec(a, b, func);
	cout << "полученное значение: " << ff << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(ff - f) << endl << endl;

	cout << "формула среднего прямоугольника" << endl;
	ff = middleRec(a, b, func);
	cout << "полученное значение: " << test3 << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(ff - f) << endl << endl;

	cout << "формула трапеции" << endl;
	ff = trap(a, b, func);
	cout << "полученное значение: " << ff << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(ff - f) << endl << endl;

	cout << "формула Симпсона " << endl;
	ff = Simpson(a, b, func);
	cout << "полученное значение: " << ff << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(ff - f) << endl << endl;

	cout << "формула трех восьмых " << endl;
	ff = threeEights(a, b, func);
	cout << "полученное значение: " << ff << endl;
	cout << "абсолютная фактическая погрешность: " << fabs(ff - f) << endl << endl;

	return 0;
}