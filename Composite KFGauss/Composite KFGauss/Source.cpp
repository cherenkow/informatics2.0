#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x, int n = 0) {
	return sin(x) * cos(x);
}

double poly(double x, int n) {
	return pow(x, n);
}

void initArr(int n, double*& arr) {
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
	return arr;
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
			if (signCheck(Lezhandr(a, n), Lezhandr(c, n))) {
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

void copy(int n, double*& arr1, double* arr) {
	for (int i = 0; i < n; ++i) {
		arr1[i] = arr[i];
	}
}

void compositeGauss(int test,double (*foo)(double, int)) {
	int exit = 1;
	while (exit != 0) {
		cout << "введите отрезок интегрирования" << endl;
		double a = 0;
		double b = 0;
		cin >> a;
		cin >> b;
		cout << "введите количество дроблений" << endl;
		int m = 0;
		cin >> m;
		cout << "введите количество узлов" << endl;
		int n = 0;
		cin >> n;
		cout << endl;
		double res = 0;
		double h = (b - a) / m;
		double z = a;
		double exact = Simpson(test, 10000, a, b, foo);
		double* intervals = new double[2 * n];
		double* roots = new double[n];
		double* A = new double[n];
		intervals = rootsDivision(n, -1, 1, pow(10, -4));
		roots = bisectionMet(n, intervals);
		A = koefSearch(n, roots);
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << "(" << i + 1 << ")" << "knot: " << roots[i] << "  koef.:" << A[i] << endl;
		}
		double* temproots = new double[n];
		double* tempA = new double[n];
		
		//----------------------------------------------------------
		for (int i = 0; i < m; ++i) {
			copy(n, temproots, roots);
			copy(n, tempA, A);
			rootsReDo(n, z, z+h, temproots);
			koefReDo(n, z, z+h, tempA);
			for (int j = 0; j < n; ++j) {
				res += tempA[j] * foo(temproots[j], test);
			}
			z += h;
		}
		cout << endl << "Значение интеграла полученное КФ Гаусса: " << res << endl;
		cout << "Точное значение интеграла: " << exact << endl;
		cout << "Абсолютная фактическая погрешность: " << fabs(res - exact) << endl << endl;
		
		//--------------------------------------------------------------
		cout << "Если Вы хотите ввести новые параметры, нажмите 1" << endl;
		cout << "Если Вы хотите выйти из програмы, нажмите 0 " << endl << endl;
		cin >> exit;
		cout << endl << endl;
	}
}
int main() {
	cout << setprecision(12);
	setlocale(LC_ALL, "Russian");
	cout << "%%%%%%%%%%%%%%% СКФ ГАУССА %%%%%%%%%%%%%%%" << endl << endl;
	compositeGauss(0, func);
		return 0;
}
