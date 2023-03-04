#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x) {
	return (sin(x) + x * x / 2);
}

double** initMatrix(int n, int m)
{
	double** matrix = new double* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double [m] { 0 };
	}
	return matrix;
}

void printTab(double** matrix, int n, int m)
{
	cout << "x    |    f(x)" << endl;
	for (int j = 0; j < m; ++j)
	{
		cout << matrix[0][j] << " | " << matrix[1][j] << endl;
	}
	cout << endl;
}

void printMatrix(double** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

void fillTab(double**& arr, int m, double a, double b) {
	double h = (b - a) / m;
	for (int i = 0; i < m; ++i) {
		arr[0][i] = a + (h * i + h * (i + 1)) / 2;
		arr[1][i] = func(arr[0][i]);
	}
}

void swap(double& a, double& b) {
	double t = a;
	a = b;
	b = t;
	return;
}

void sort(double x, int m, int n, double**& arr) {

	for (int i = 0; i < n + 1; ++i) {
		double t = arr[0][i];
		int k = i;
		for (int j = i; j < m; ++j) {
			if (fabs(x - arr[0][j]) < fabs(x - t)) {
				t = arr[0][j];
				k = j;
			}
		}
		if (k != i) {
			swap(arr[0][k], arr[0][i]);
			swap(arr[1][k], arr[1][i]);
		}

	}
	return;
}

double Lagrange(double x, int n, double** arr) {
	double LagrangePol = 0;
	for (int l = 0; l < n + 1; ++l) {
		double count = 1;
		for (int i = 0; (i != l && i < n + 1); ++i) {
			count = count * (x - arr[0][i]) / (arr[0][l] - arr[0][i]);
		}
		LagrangePol += count * arr[1][l];
	}
	return (LagrangePol);
}

void fillDifTab(double**& arr, double** tabs, int n) {
	int m = 2 * n + 1;
	int k = 0;
	for (int i = 0; i < m;i+=2) {
		arr[i][0] = tabs[0][k];
		arr[i][1] = tabs[1][k];
		++k;
	}
	for (int i = 1; i < n+1; ++i) {
		for (int j = i - 1; j < m - i +1 - 2; j+=2) { 
			arr[j + 1][i + 1] = (arr[j + 2][i] - arr[j][i]) / (arr[j +2 + i - 1][0] - arr[j - i + 1][0]);
		}
	}
	return;
}

double Newton(double** arr, int n, double x) {
	double count = 0;
	double brac = 1;
	for (int i = 0; i < n + 1; ++i) {
		count += brac * arr[i][i+1];
		brac = brac * (x - arr[2 * i][0]);
	}
	return count; 
}

bool rebool(int k) {
	return (k == 1);
}

void guestInterpolation() {
	cout << "Введите количество узлов интерполирования" << endl;
	int m = 0;
	cin >> m;
	cout << "Введите концы отрезка, на котором будет происходить интерполирование" << endl;
	double a = 0;
	double b = 0;
	cin >> a;
	cin >> b;

	bool exit = true;
	
	while (exit == true) {

		double** tab = initMatrix(2, m);
		fillTab(tab, m, a, b);
		cout << "Таблица узлов и значений:" << endl;
		printTab(tab, 2, m);

		cout << "Введите точку интерполирования" << endl;
		double x = 0;
		cin >> x;
		cout << "Введите степень интерполяционного многочлена" << endl;
		int n = m + 2;
		while (n >= m) {
			cout << "Внимание! Степень многочлена не должна превосходить " << m - 1 << endl;
			cin >> n;
		}
		sort(x, m, n, tab);
		cout << "Отсортированная таблица узлов" << endl;
		printTab(tab, 2, m);

		cout << "Результат, полученный интерполяционным многочленом Лагранжа:" << endl;
		cout << "f(x) ~ L(x) = " << Lagrange(x, n, tab) << endl;
		cout << "aбсолютная фактическая погрешность:" << fabs(func(x) - Lagrange(x, n, tab)) << endl << endl;

		double** dif = initMatrix(2 * n + 1, n + 2);
		fillDifTab(dif, tab, n);
		cout << "Таблица разделенных разностей" << endl;
		printMatrix(dif, 2 * n + 1, n + 2);
		cout << "Результат, полученный интерполяционным многочленом Ньютона:" << endl;
		cout << "f(x) ~ N(x) = " << Newton(dif, n, x) << endl;
		cout << "aбсолютная фактическая погрешность:" << fabs(func(x) - Newton(dif, n, x)) << endl;

		int ex = 0;
		cout << "Нажмите 1, если хотите выбрать новую степень многочлена и точку интерполирования" << endl;
		cout << "Нажмите 0, чтобы выйти из программы" << endl;
		cin >> ex;
		exit = rebool(ex);
	}
	return;
}

int main() {
	cout << setprecision(5);
	setlocale(LC_ALL, "Russian");
	guestInterpolation();
	return 0;
}