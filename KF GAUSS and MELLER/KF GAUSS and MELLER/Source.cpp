#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x, int n = 0) {
	return sqrt(x) * cos(x * x);
}

double func1(double x, int n = 0) {
	return cos(2.6 * x) / (0.3 + pow(x, 2)) ;
}

double poly(double x, int n) {
	return pow(x, n);
}

void initArr(int n, double* & arr) {
	for (int i = 0; i < n; ++i) {
		arr[i] = 0;
	}
}

double Lezhandr(double x, int n) {
	if (n == 1) {
		return x;
	}
	double* le = new double[n + 1];
	le[0] = 1; 
	le[1] = x;
	for (int i = 2; i < n + 1; ++i) {
		le[i] = ((2 * i - 1) * le[i - 1] * x - (i - 1) * le[i - 2]) / i;
	}
	return le[n];
}

double Simpson(int test, int m, double a, double b, double (*foo)(double, int)) {
	double h = (b - a) / m;
	double res = foo(a, test) + foo(b, test);
	for (int i = 1; i < m; ++i) {
		res += 2 * foo(a + h * i, test);
	}
	for (int i = 0; i < m; ++i) {
		res += 4 * foo(a + h * i + h / 2, test);
	}
	res *= (h / 6);
	return res;
}

double* rootsDivision(int n, double a, double b, double step) {
	double* arr = new double[2 * n];
	int k = 0;
	double x = a;
	while (x + step <= b) {
		if (Lezhandr(x, n) * Lezhandr(x + step, n) < 0) {
			arr[k] = x;
			arr[k + 1] = x + step;
			k = k + 2;
		}
		x = x + step;
	}
	/*
	cout << "��������� ��������� ������:" << endl;
	for (int i = 0; i < 2 * n; i += 2) {
		cout << arr[i] << " " << arr[i + 1] << endl; ;
	}
	cout << endl;
	*/

	return arr;
}

double newArgSec(int n, double x2, double x1) {
	return(x2 - Lezhandr(x2, n) * (x2 - x1) / (Lezhandr(x2, n) - Lezhandr(x1, n)));
}

double* secantMet(int n, double* arr) {
	double* res = new double[n];
	for (int i = 0; i < n; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		int temp = 0;
		int counter = 0;
		while (fabs(b - a) >= pow(10, -12)) {
			int temp = a;
			a = b;
			b = newArgSec(n, a, temp);
			counter++;
		}
		cout << "���������� ��������: " << counter << endl;
		cout << "��������� ������������ �������� �����:" << b << endl;
		cout << "�����������: " << fabs(b - a) << endl;
		res[i] = b;
	}
	return res;
}

bool signCheck(double a, double b) {
	return (a * b < 0);
}

double* bisectionMet(int n, double* arr) {
	double* res = new double[n];
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		double a = arr[2 * i];
		double b = arr[2 * i + 1];
		double c = (a + b) / 2;
		while (b - a >= 2 * pow(10, -15)) {
			if (signCheck(Lezhandr(a,n), Lezhandr(c,n))) {
				b = c;
				c = (a + b) / 2;
			}
			else {
				a = c;
				c = (a + b) / 2;
			}
			counter++;
		}
		res[i] = c;
		cout << "��������� ������������ �������� �����:" << c << endl;
		//cout << "���������� ��������:" << counter << endl;

	}
	return res;
}

double* koefSearch(int n, double* roots) {
	double* res = new double[n];
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		res[i] = 2 * (1 - pow(roots[i], 2)) / (n * n * pow(Lezhandr(roots[i], n - 1), 2));
	}
	for (int i = 0; i < n; ++i) {
		sum += res[i];
	}
	cout << "�������� (����� ����. �� (-1,1)) " << sum << endl;
	return res;
}

void rootsReDo(int n, double a, double b, double*& roots) {
	double k = (b - a) / 2;
	double l = (b + a) / 2;
	for (int i = 0; i < n; ++i) {
		roots[i] = k * roots[i] + l;
	}
}

void koefReDo(int n, double a, double b, double*& A) {
	double k = (b - a) / 2;
	for (int i = 0; i < n; ++i) {
		A[i] = k * A[i];
	}
}

void kfGauss(int test, int n, double a, double b, double (*foo)(double, int)) {
	double exact = Simpson(test, 10000, a, b, foo);
	double res = 0;
	double* roots = new double[n];
	double* A = new double[n];
	double* intervals = new double[2 * n];
	
	intervals = rootsDivision(n, -1, 1, pow(10, -4));
	roots = bisectionMet(n, intervals);
	cout << endl;
	A = koefSearch(n, roots);
	rootsReDo(n, a, b, roots);
	koefReDo(n, a, b, A);
	for (int i = 0; i < n; ++i) {
		res += A[i] * foo(roots[i], test);
	}
	double count = 0;
	for (int i = 0; i < n; ++i) {
		count += A[i];
	}
	cout << "�������� (����� ����. �� (a,b)) " << count << endl << endl;
	for (int i = 0; i < n; ++i) {
		cout << "(" << i + 1 << ")" << "knot: " << roots[i] << "  koef.:" << A[i] << endl;
	}

	cout << endl << "�������� ��������� ���������� �� ������: " << res << endl;
	cout << "������ �������� ���������: " << exact << endl;
	cout << "���������� ����������� �����������: " << fabs(res - exact) << endl << endl;
}

void kfMeller(double (*foo)(double, int)) {
	int n = 0;
	double* res = new double[6];
	for (int l = 0; l < 3; ++l) {
		cout << "������� ���������� �����" << endl << endl;
		cin >> n;
		cout << endl;
		double* knots = new double[n];
		double count = 0;
		cout << "--------- N = " << n << " --------- " << endl << endl;
		for (int i = 0; i < n; ++i) {
			knots[i] = cos((2.0 * (i+1) - 1) * acos(-1.0) / (2.0 * n));
			count += foo(knots[i], 0);
			cout << "(" << i + 1 << ") " << "knot: " << knots[i] << "   koef: pi/" << n << endl;
		}		
		count *= acos(-1.0) / n;
		res[2*l] = count;
		res[2 * l + 1] = n;
		cout << endl << endl;
	}
	for (int i = 0; i < 3; ++i) {
		cout << "���������� �������� ��������� ��� N = " << res[2*i +1] << ": " << res[2*i]<< endl;
	}
}
int main() {
	cout << setprecision(12);
	setlocale(LC_ALL, "Russian");

	/*
	cout << "%%%%%%%%%%%%%%% �� ������ %%%%%%%%%%%%%%%" << endl << endl;
	int exit = 1;
	while (exit != 0) {
		cout << "������� ������� ��������������" << endl;
		double a = 0;
		double b = 0;
		cin >> a;
		cin >> b;
		cout << endl;

		for (int i = 1; i < 9; ++i) {
			cout << "------------ " << i << " ����� ------------" << endl << endl;
			kfGauss(0, i, a, b, func);
			cout << endl << "----------- �������� �� �������� 2N-1 ------------" << endl;
			kfGauss(2 * i - 1, i, a, b, poly);
		}
		cout << "���� �� ������ ������ ����� ������� ��������������, ������� 1" << endl;
		cout << "���� �� ������ ����� �� ��������, ������� 0 " << endl << endl;
		cin >> exit;
		cout << endl << endl;
	}
	*/

	cout << "%%%%%%%%%%%%%%% �� ������� %%%%%%%%%%%%%%%" << endl << endl;
	kfMeller(func1);
	return 0;
}
