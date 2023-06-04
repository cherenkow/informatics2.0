#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double func(double x) {
	return (1 / (x + 1));
}

double Func(double y) {
	return (-pow(y, 2));
}

double* taylorKoef = new double[6]{ 1, -1, 2, -6, 24, -120 };

double taylor(double x) {
	double res = 1;
	double f = 1;
	for (int i = 1; i < 6; ++i) {
		res += taylorKoef[i] * pow(x, i) / f;
		f *= (i + 1);
	}
	return res;
}

double runge(double h, double y) {
	double k1 = h * Func(y);
	double k2 = h * Func(y + k1 / 2);
	double k3 = h * Func(y + k2 / 2);
	double k4 = h * Func(y + k3);
	return (y + (k1 + 2 * k2 + 2 * k3 + k4) / 6);
}

double euler1(double h, double y) {
	return (y + h * Func(y));
}

double euler2(double h, double y) {
	return (y + h * Func(y + 0.5 * h * Func(y)));
}

double adams(double q0, double q1, double q2, double q3, double q4, double y) {
	return (y + q0 + 0.5 * q1 + 5 * q2 / 12 + 3 * q3 / 8 + 251 * q4 / 720);
}

double** initMatrix(int n, int m)
{
	double** matrix = new double* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double[m] { 0 };
	}
	return matrix;
}

void printMatrix(double** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << setprecision(12) << "Численное решение Задачи Коши для обыкновенного дифференциального уравнения первого порядка" << endl;
	double x0 = 0;
	double y0 = 1;

	cout << "Задача Коши: y'(x) = -y^2(x), y(" << x0 << ") = " << y0 << endl << endl;
	cout << "Точное решение: y(x) = " << ' ' << " 1 / (x+1)" << endl << endl;
	double h;
	int n;
	cout << "Введите значение h" << endl;
	cin >> h;
	cout << "Введите значение N" << endl;
	cin >> n;
	cout << endl << endl;

	double* knot = new double[n + 3];
	for (int i = 0; i < n + 3; ++i) {
		knot[i] = x0 + h * (i - 2);
	}
	double* result = new double[n + 3];

	//exact
	cout << "------- Точные значения -------" << endl << endl;
	for (int i = 0; i < n + 3; ++i) {
		result[i] = func(knot[i]);
		cout << "k = " << i - 2 << ": knot: " << knot[i] << "  value: " << result[i] << endl;
	}
	cout << endl << endl;
	//taylor
	cout << "------- Метод разложения в ряд Тейлора -------" << endl << endl;
	for (int i = 0; i < n + 3; ++i) {
		result[i] = taylor(knot[i]);
		cout << "k = " << i - 2 << ": knot: " << knot[i] << "  value: " << result[i] << endl;
		cout << "Абсолютная фактическая погрешность: " << fabs(func(knot[i]) - result[i]) << endl << endl;

	}
	cout << endl << endl;
	//adams
	cout << "------- Метод Адамса четвертого порядка -------" << endl << endl;
	double** dif = initMatrix(n + 3, 6);
	for (int i = 0; i < 5; ++i) {
		dif[i][0] = result[i];
		dif[i][1] = h*Func(result[i]);
	}
	for (int l = 0; l < 4; ++l) {
		for (int i = 0; i < 5 - l - 1; ++i) {
			dif[i][2 + l] = dif[i + 1][1 + l] - dif[i][l + 1];
		}
	}
	for (int k = 5; k < n + 3; ++k) {
		dif[k][0] = adams(dif[k - 1][1], dif[k - 2][2], dif[k - 3][3], dif[k - 4][4], dif[k - 5][5], dif[k - 1][0]);
		dif[k][1] = h*Func(dif[k][0]);
		for (int j = 2; j < 6; ++j) {
			dif[k - j + 1][j] = dif[k - j + 1][j - 1] - dif[k - j][j - 1];
		}

	}
	for (int k = 5; k < n + 3; ++k) {
		cout << "k = " << k - 2 << ": knot: " << knot[k - 5] << "  value: " << dif[k][0] << endl;
		if (k == n + 2) {
			cout << "Абсолютная фактическая погрешность: " << fabs(func(x0 + n*h) - dif[k][0]) << endl << endl;
		}
	}

	//runge
	for (int i = 0; i <= n; ++i) {
		knot[i] = x0 + h * i;
	}
	result[0] = 1;
	cout << "------- Метод Рунге 4 порядка -------" << endl << endl;
	for (int i = 1; i <= n ; ++i) {
		result[i] = runge(h,result[i-1]);
		cout << "k = " << i << ": knot: " << knot[i] << "  value: " << result[i] << endl;
		if (i == n) {
		cout << "Абсолютная фактическая погрешность: " << fabs(func(knot[i]) - result[i]) << endl << endl;
		}
	}
	cout << endl << endl;
	//Euler I
	cout << "------- Метод Эйлера I -------" << endl << endl;
	for (int i = 1; i <= n; ++i) {
		result[i] = euler1(h, result[i - 1]);
		cout << "k = " << i << ": knot: " << knot[i] << "  value: " << result[i] << endl;
		if (i == n) {
			cout << "Абсолютная фактическая погрешность: " << fabs(func(knot[i]) - result[i]) << endl << endl;
		}
	}
	cout << endl << endl;
	//Euler II
	cout << "------- Метод Эйлера II -------" << endl << endl;
	for (int i = 1; i <= n; ++i) {
		result[i] = euler2(h, result[i - 1]);
		cout << "k = " << i << ": knot: " << knot[i] << "  value: " << result[i] << endl;
		if (i == n) {
			cout << "Абсолютная фактическая погрешность: " << fabs(func(knot[i]) - result[i]) << endl << endl;
		}
	}
	cout << endl << endl;
	return 0;
}