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

double leftRec(int m, double exact, double a, double b, double (*foo)(double)) {
	double h = (b - a) / m;
	double res = foo(a);
	for (int i = 1; i < m; ++i) {
		res += foo(a + h * i);
	}
	res *= h;
	return res;
}

double rightRec(int m, double exact, double a, double b, double (*foo)(double)) {
	double h = (b - a) / m;
	double res = foo(b);
	for (int i = 1; i < m; ++i) {
		res += foo(a + h * i);
	}
	res *= h;
	return res;
}

double middleRec(int m, double exact, double a, double b, double (*foo)(double)) {
	double h = (b - a) / m;
	double res = 0;
	for (int i = 0; i < m; ++i) {
		res += foo(a + h * i + h / 2);
	}
	res *= h;
	return res;
}

double trap(int m, double exact, double a, double b, double (*foo)(double)) {
	double h = (b - a) / m;
	double res = foo(a) + foo(b);
	for (int i = 1; i < m; ++i) {
		res += 2 * foo(a + h * i);
	}
	res *= (h / 2);
	return res;
}

double Simpson(int m, double exact, double a, double b, double (*foo)(double)) {
	double h = (b - a) / m;
	double res = foo(a) + foo(b);
	for (int i = 1; i < m; ++i) {
		res += 2 * foo(a + h * i);
	}
	for (int i = 0; i < m; ++i) {
		res += 4 * foo(a + h * i + h / 2);
	}
	res *= (h / 6);
	return res;
}

double Runge(int d, int l, double j1, double j2) {
	return (pow(l,d+1)*j2 - j1)/(pow(l,d+1) - 1);
}

void factEr(double a, double b) {
	cout << "���������� ����������� �����������: " << fabs(a - b) << endl;
}


int main() {
	cout << setprecision(10);
	setlocale(LC_ALL, "Russian");
	cout << "������ ���������� ��������������. ��������� ������������ �������" << endl;

	cout << "������� ����� ������� ��������������" << endl;
	double a = 0;
	double b = 0;
	cin >> a;
	cin >> b;
	cout << "������� ���������� �������� ���������" << endl;
	int m = 0;
	cin >> m;
	cout << "������� �� ������� ��� ���� ��������� ���������� �������� ���������" << endl;
	int l = 0;
	cin >> l;
	//exact values
	double f = Func(a, b);

	cout << endl << "�������������� ������� f(x) = exp(3 * x) + sin(2 * x) + x " << endl;

	cout << endl << "������� ������ ��������������" << endl;
	double l1 = leftRec(m, f, a, b, func);
	double l2 = leftRec(m*l, f, a, b, func);
	double l3 = Runge(0,l, l1, l2);
	cout << "���������� ��������: " << l2 << endl;
	factEr(l2, f);
	cout << "���������� ��������: " << l3 << endl;
	factEr(l3,f);
	cout << "����������� ��������: " << f << endl;

	cout << endl << "������� ������� ��������������" << endl;
	double r1 = rightRec(m, f, a, b, func);
	double r2 = rightRec(m*l, f, a, b, func);
	double r3 = Runge(0, l, r1, r2);
	cout << "���������� ��������: " << r2 << endl;
	factEr(r2, f);
	cout << "���������� ��������: " << r3 << endl;
	factEr(r3, f);
	cout << "����������� ��������: " << f << endl;

	cout << endl << "������� �������� ��������������" << endl;
	double m1 = middleRec(m, f, a, b, func);
	double m2 = middleRec(m*l, f, a, b, func);
	double m3 = Runge(1, l, m1, m2);
	cout << "���������� ��������: " << m2 << endl;
	factEr(m2, f);
	cout << "���������� ��������: " << m3 << endl;
	factEr(m3, f);
	cout << "����������� ��������: " << f << endl;

	cout << endl << "������� ��������" << endl;
	double t1 = trap(m, f, a, b, func);
	double t2 = trap(m*l, f, a, b, func);
	double t3 = Runge(1, l, t1, t2);
	cout << "���������� ��������: " << t2 << endl;
	factEr(t2, f);
	cout << "���������� ��������: " << t3 << endl;
	factEr(t3, f);
	cout << "����������� ��������: " << f << endl;

	cout << endl << "������� ��������" << endl;
	double s1 = Simpson(m, f, a, b, func);
	double s2 = Simpson(m*l, f, a, b, func);
	double s3 = Runge(3, l, s1, s2);
	cout << "���������� ��������: " << s2 << endl;
	factEr(s2, f);
	cout << "���������� ��������: " << s3 << endl;
	factEr(s3, f);
	cout << "����������� ��������: " << f << endl;

	return 0;
}