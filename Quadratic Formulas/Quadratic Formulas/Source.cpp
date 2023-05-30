#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x, int n = 0) {
    return sin(x);
}

double funcWeight(double x, int n = 0) {
    return sin(x)*cos(x);
}

double polyWeight(double x, int n) {
    return pow(x, n)*cos(x);
}

double poly(double x, int n) {
    return pow(x, n) ;
}

double Simpson(int test,int m, double a, double b, double (*foo)(double,int)) {
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

double SimpsonMom(int n, int m, double a, double b, double (*foo)(double, int)) {
    double h = (b - a) / m;
    double res = foo(a, n) + foo(b, n);
    for (int i = 1; i < m; ++i) {
        res += 2 * foo(a + h * i, n);
    }
    for (int i = 0; i < m; ++i) {
        res += 4 * foo(a + h * i + h / 2, n);
    }
    res *= (h / 6);
    return res;
}

double** initMatrix(int dimention)
{
    double** matrix = new double* [dimention] { 0 };
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
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

double* Gauss(double** mat, double * ba, int n)
{
    //saved b
    double* b = new double[n];
    for (int i = 0; i < n; ++i) {
        b[i] = ba[i];
    }

    double* res = new double[n];
    double d = 0;
    for (int k = 0; k < n; k++)
    {
        for (int j = k + 1; j < n; j++)
        {
            d = mat[j][k] / mat[k][k];
            for (int i = k; i < n; i++)
            {
                mat[j][i] = mat[j][i] - d * mat[k][i];
            }
            b[j] = b[j] - d * b[k];
        }
    }
    for (int k = n - 1; k >= 0; k--)
    {
        d = 0;
        for (int j = k + 1; j < n; j++)
        {
            double s = mat[k][j] * res[j];
            d = d + s;
        }
        res[k] = (b[k] - d) / mat[k][k];
    }
    return res;
}

void IKF(int test,int n, double a, double b, double* mom, double* knots, double (*foo)(double, int), double (*fooWeight)(double, int)) {
    double* A = new double[n];
    double** arr = initMatrix(n);
    double exact = Simpson(test,10000, a, b, fooWeight);
    // заполнение матрицы СЛАУ
    for (int i = 0; i < n; ++i) {
        arr[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = pow(knots[j], i);
        }
    }
    //ищем коэффициенты ИКФ
    A = Gauss(arr, mom, n);
    cout << "Найденные коэфициенты ИКФ:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    //считаем результат
    double res = 0;
    for (int i = 0; i < n; ++i) {
        res += A[i] * foo(knots[i], test);
    }
    cout << "Значение интеграла полученное ИКФ: " << res <<endl;
    cout << "Точное значение интеграла: " << exact << endl;
    cout << "Абсолютная фактическая погрешность: " << fabs(res - exact) << endl << endl;
    
}

int main() {
    cout << setprecision(12);
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
    double* mom = new double[n];
    for (int i = 0; i < n; ++i) {
        mom[i] = SimpsonMom(i, 10000, a, b, polyWeight);
    }
    for (int i = 0; i < n; ++i) {
        cout << mom[i] << " ";
    }
    cout << endl << endl;
    double* knots = new double[n];
    double h = (b - a) / (n);
    for (int i = 0; i < n; ++i) {
        knots[i] = a + h * i;
    }
    cout << "узлы:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << knots[i] << " ";
    }
    cout << endl << endl;

    IKF(0,n, a, b, mom, knots, func, funcWeight);
    IKF(n-1, n, a, b, mom, knots, poly, polyWeight);




    return 0;
}