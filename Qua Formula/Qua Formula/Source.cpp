#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x) {
	return sin(x);
}
double momWeight(double x, int n) {
	return pow(x, n)*cos(x);
}
double testPoly(double x) {
    return pow(x, 5);
}

double Simpson(int m, double a, double b, double (*foo)(double)) {
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

double SimpsonMom(int n, int m, double a, double b, double (*foo)(double, int)) {
	double h = (b - a) / m;
	double res = foo(a,n) + foo(b,n);
	for (int i = 1; i < m; ++i) {
		res += 2 * foo(a + h * i, n);
	}
	for (int i = 0; i < m; ++i) {
		res += 4 * foo(a + h * i + h / 2, n);
	}
	res *= (h / 6);
	return res;
}

double* gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.00001;  // точность
    x = new double[n];
    k = 0;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}

double **initMatrix(int dimention)
{
    double **matrix = new double* [dimention] { 0 };
    for (int i = 0; i < dimention; ++i)
    {
        matrix[i] = new double[dimention] { 0 };
    }
    return matrix;
}

void printMatrix(double** matrix, int dimention)
{
    for (int i = 0; i < dimention; ++i)
    {
        for (int j = 0; j < dimention; ++j)
        {
            cout << matrix[i][j] << "           ";
        }
        cout << endl;
    }
}

double IKF(int n, double a, double b, double* mom, double * knots, double (*foo)(double)) {
    double* A = new double[n];
    double** arr = initMatrix(n);
    for (int i = 0; i < n; ++i) {
        arr[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = pow(knots[j], i);
        }
    }
    printMatrix(arr, n);
    A = gauss(arr, mom, n);
    double res = 0;
    for (int i = 0; i < n; ++i) {
        res += A[i] * foo(knots[i]);
    }
    return res;
}
int main() {
	cout << setprecision(10);
	setlocale(LC_ALL, "Russian");
	cout << "ИКФ и КФНАСТ" << endl << endl;
	cout << "введите отрезок интегрирования" << endl;
	double a = 0;
	double b = 0;
    cin >> a;
    cin >> b;
	cout << "введите количество узлов" << endl;
	int n = 0;
	cin >> n;
	cout << "моменты:" << endl;
	double * mom = new double[n];
	for (int i = 0; i < n; ++i) {
		mom[i] = SimpsonMom(i, 10000, a, b, momWeight);
	}
	for (int i = 0; i < n; ++i) {
		cout << mom[i] << " ";
	}
	cout << endl << endl;
    double* knots = new double[n];
    double h = (b - a) / (n);
    for (int i = 0; i < n; ++i) {
        knots[i] = a + h*i;
    }
    cout << "узлы:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << knots[i] << " ";
    }
    cout << endl;
    cout << "Значение интеграла полученное ИКФ:" << endl;
    cout << (IKF (n , a, b, mom, knots, testPoly) - 1.0/6) << endl;


    
	
	return 0;
}