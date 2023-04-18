#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x) {
	return (sin(x) + x * x / 2);
}

double Func(double x) {
	return (exp(3 * x));
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

void printTab(double** matrix, int n, int m, int c)
{
	if (c == 0) {
		cout << "x    |    f(x)" << endl;
	}
	else {
		cout << "f(x)    |    x" << endl;
	}

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
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}

}

void fillTab(double**& arr, int m, double a, double b) {
	double h = (b - a) / (m - 1);
	for (int i = 0; i < m; ++i) {
		arr[0][i] = a + h * i;
		arr[1][i] = func(arr[0][i]);
	}
}

void swap(double& a, double& b) {
	double t = a;
	a = b;
	b = t;
	return;
}

void swapTable(double**& arr, int n, int m) {
	for (int i = 0; i < m; ++i) {
		swap(arr[0][i], arr[1][i]);
	}
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
		for (int i = 0; i < n + 1; ++i) {
			if (i != l) {
				count = count * (x - arr[0][i]) / (arr[0][l] - arr[0][i]);
			}
		}
		LagrangePol += count * arr[1][l];
	}
	return (LagrangePol);
}

double equasion(double x, double F, int n, double** arr) {
	return (Lagrange(x, n, arr) - F);
}

bool signCheck(double a, double b) {
	return (a * b < 0);
}

void fillDifTab(double**& arr, double** tabs, int n) {
	int m = 2 * n + 1;
	int k = 0;
	for (int i = 0; i < m; i += 2) {
		arr[i][0] = tabs[0][k];
		arr[i][1] = tabs[1][k];
		++k;
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = i - 1; j < m - i + 1 - 2; j += 2) {
			arr[j + 1][i + 1] = (arr[j + 2][i] - arr[j][i]) / (arr[j + 2 + i - 1][0] - arr[j - i + 1][0]);
		}
	}
	return;
}

double Newton(double** arr, int n, double x) {
	double count = 0;
	double brac = 1;
	for (int i = 0; i < n + 1; ++i) {
		count += brac * arr[i][i + 1];
		brac = brac * (x - arr[2 * i][0]);
	}
	return count;
}

void bisectionMet(double End1, double End2, double eps, double F, int n, double** arr) {
	double a = End1;
	double b = End2;
	double c = (a + b) / 2;
	while (b - a >= 2 * eps) {
		if (signCheck((Newton(arr, n, a) - F), (Newton(arr, n, c) - F))) {
			b = c;
			c = (a + b) / 2;
		}
		else {
			a = c;
			c = (a + b) / 2;
		}
	}

	cout << "Найденное значение корня 2 способом:" << c << endl;
	cout << "Неувязка: " << fabs(Newton(arr, n, c) - F) << endl << endl;
	return;
}

bool rebool(int k) {
	return (k == 1);
}

void InverseInterpolation() {
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
		printTab(tab, 2, m, 0);

		cout << "Введите искомое значение" << endl;
		double F = 0;
		cin >> F;
		cout << "Введите степень интерполяционного многочлена" << endl;
		int n = m + 2;
		while (n >= m) {
			cout << "Внимание! Степень многочлена не должна превосходить " << m - 1 << endl;
			cin >> n;
		}
		swapTable(tab, 2, m);
		sort(F, m, n, tab);
		cout << "Отсортированная таблица узлов" << endl;
		printTab(tab, 2, m, 1);


		cout << "Результат, полученный первым способом:" << endl;
		cout << "(f(F))^-1 ~ = " << Lagrange(F, n, tab) << endl;
		cout << "aбсолютная фактическая погрешность:" << fabs(F - func(Lagrange(F, n, tab))) << endl << endl;

		swapTable(tab, 2, m);
		cout << "Введите точность, с которой хотите отыскать значение" << endl;
		double eps = 0;
		cin >> eps;
		double end1 = a;
		double end2 = b;
		double h = 1 / 10000;
		double** dif = initMatrix(2 * n + 1, n + 2);
		fillDifTab(dif, tab, n);
		if ((Newton(dif, n, end1) - F) == 0) {
			cout << "Найденное значение корня:" << end1 << endl;
			cout << "Неувязка: " << 0 << endl << endl;
		}
		else if ((Newton(dif, n, end2) - F) == 0) {
			cout << "Найденное значение корня:" << end2 << endl;
			cout << "Неувязка: " << 0 << endl << endl;
		}
		else {
			bisectionMet(end1, end2, eps, F, n, dif);
		}
		int ex = 0;
		cout << "Нажмите 1, если хотите выбрать новую степень многочлена и точку интерполирования" << endl;
		cout << "Нажмите 0, чтобы выйти из программы" << endl;
		cin >> ex;
		exit = rebool(ex);
	}
	return;
}

double centralD(double h, double fl, double fr) {
	return ((fr - fl) / (2 * h));
}

double leftD(double h, double fx, double f1, double f2) {
	return ((-3 * fx + 4 * f1 - f2) / (2 * h));
}

double rightD(double h, double fx, double f1, double f2) {
	return ((3 * fx - 4 * f1 + f2) / (2 * h));
}

double secondD(double h, double f1, double fx, double f2) {
	return ((f1+f2-2*fx)/(h*h));
}
double secondLD(double h, double f1, double f2, double f3, double f4) {
	return ((2 * f1 - 5 * f2 + 4 * f3 - f4) / (h * h));
}
double secondRD(double h, double f1, double f2, double f3, double f4) {
	return ((2 * f4 - 5 * f3 + 4 * f2 - f1) / (h * h));
}
void Differenciation() {
	bool exit = true;
	while (exit == true) {
		cout << "Введите количество узлов" << endl;
		int m = 0;
		cin >> m;
		cout << "Введите начальную точку " << endl;
		double a = 0;
		cin >> a;
		cout << "Введите шаг " << endl;
		double h = 0;
		cin >> h;
		double** tab = initMatrix(m, 8);
		for (int i = 0; i < m; ++i) {
			tab[i][0] = a + h * i;
			tab[i][1] = Func(tab[i][0]);
			tab[i][2] = 3 * tab[i][1];
			tab[i][3] = 3 * tab[i][2];
		}

		for (int i = 1; i < m - 1; ++i) {
			tab[i][4] = centralD(h, tab[i - 1][1], tab[i + 1][1]);
			tab[i][5] = fabs(tab[i][4] - tab[i][2]);
			tab[i][6] = secondD(h, tab[i - 1][1], tab[i][1], tab[i + 1][1]);
			tab[i][7] = fabs(tab[i][6] - tab[i][3]);
		}
		//first
		tab[0][4] = leftD(h, tab[0][1], tab[1][1], tab[2][1]);
		tab[0][5] = fabs(tab[0][4] - tab[0][2]);
		tab[0][6] = secondLD(h, tab[0][1], tab[1][1], tab[2][1], tab[3][1]);
		tab[0][7] = fabs(tab[0][6] - tab[0][3]);
		//last
		tab[m - 1][4] = rightD(h, tab[m - 1][1], tab[m - 2][1], tab[m - 2][1]);
		tab[m - 1][5] = fabs(tab[0][4] - tab[0][2]);
		tab[m - 1][6] = secondRD(h, tab[m - 4][1], tab[m - 3][1], tab[m - 2][1], tab[m - 1][1]);
		tab[m - 1][7] = fabs(tab[0][6] - tab[0][3]);

		cout << endl;
		cout << "x    f(x)      f'(x)    |f'точ(x)-f'числ(x)|    f''(x)     |f''точ(x)-f''числ(x)|  " << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (j != 2 && j != 3) {
					cout << tab[i][j] << "  ";
				}

			}
			cout << endl;
		}
		
		int ex = 0;
		cout << "Нажмите 1, если хотите выбрать новую степень многочлена и точку интерполирования" << endl;
		cout << "Нажмите 0, чтобы выйти из программы" << endl;
		cin >> ex;
		exit = rebool(ex);
	}
	return;
}


int main() {
	cout << setprecision(15);
	setlocale(LC_ALL, "Russian");
	cout << "ЗАДАЧА ОБРАТНОГО ИНТЕРПОЛИРОВАНИЯ" << endl;
	cout << "Вариант 11: Необходимо интерполировать функцию f(x) = sin(x) + x^2 / 2" << endl << endl;
	InverseInterpolation();
	cout << endl << endl;
	cout << "ЗАДАЧА ЧИСЛЕННОГО ДИФФЕРЕНЦИРОВАНИЯ" << endl;
	cout << "Вариант 11: Необходимо численно продифференцировать функцию f(x) = exp(3x)" << endl << endl;
	Differenciation();
	return 0;
}