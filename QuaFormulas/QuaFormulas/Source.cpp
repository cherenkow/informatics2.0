#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x, int n = 0) {
    return sin(x);
}

double funcWeight(double x, int n = 0) {
    return sin(x) * cos(x);
}

double polyWeight(double x, int n) {
    return pow(x, n) * cos(x);
}

double poly(double x, int n) {
    return pow(x, n);
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

double* Gauss(double** mat, double* ba, int n)
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

void IKF(int test, int n, double a, double b, double* mom, double* knots, double (*foo)(double, int), double (*fooWeight)(double, int)) {
    double* A = new double[n];
    double** arr = initMatrix(n);
    double exact = Simpson(test, 10000, a, b, fooWeight);
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
    cout << "Значение интеграла полученное ИКФ: " << res << endl;
    cout << "Точное значение интеграла: " << exact << endl;
    cout << "Абсолютная фактическая погрешность: " << fabs(res - exact) << endl << endl;

}

double polyHelp(double* arr, double x, int n) {
    double res = pow(x, n) + arr[0];
    for (int i = 1; i < n; ++i) {
        res += pow(x, i) * arr[i];
    }
    return res;
}

double* rootsDivision(int n, double a, double b, double step, double* koef) {
    double* arr = new double[2 * n + 2];
    int k = 0;
    double x = a;
    while (x + step <= b) {
        if (polyHelp(koef, x, n) * polyHelp(koef, x + step, n) < 0) {
            arr[k] = x;
            arr[k + 1] = x + step;
            k = k + 2;
        }
        x = x + step;
    }
    cout << "результат отделения корней:" << endl;
    for (int i = 0; i < 2 * n; i += 2) {
        cout << arr[i] << " " << arr[i + 1] << endl; ;
    }
    cout << endl;

    return arr;
}

bool signCheck(double a, double b) {
    return (a * b < 0);
}

double* bisectionMet(int n, double* arr, double* koef) {
    double* res = new double[n];
    for (int i = 0; i < n; ++i) {
        double a = arr[2 * i];
        double b = arr[2 * i + 1];
        double c = (a + b) / 2;
        while (b - a >= 2 * pow(10, -10)) {
            if (signCheck(polyHelp(koef, a, n), polyHelp(koef, c, n))) {
                b = c;
                c = (a + b) / 2;
            }
            else {
                a = c;
                c = (a + b) / 2;
            }
        }
        res[i] = c;
    }
    return res;
}

void KFNAST(int test, int n, double a, double b, double* mom, double (*foo)(double, int), double (*fooWeight)(double, int)) {
    double res = 0;
    double* A = new double[n];
    double* intervals = new double[n];
    double* roots = new double[n];
    //создаем столбец свободных членов
    double* freeCol = new double[n];
    for (int i = 0; i < n; ++i) {
        freeCol[i] = (-1) * mom[n + i];
    }
    double** arr = initMatrix(n);
    double exact = Simpson(test, 10000, a, b, fooWeight);
    // заполнение матрицы СЛАУ
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = mom[j + i];
        }
    }
    //находим ортогональный многочлен
    A = Gauss(arr, freeCol, n);
    cout << "найденный ортогональный многочлен:" << endl;
    cout << A[0] << " + ";
    for (int i = 1; i < n; ++i) {
        cout << A[i] << "* x^(" << i << ") + ";
    }
    cout << "x^( " << n << ")" << endl << endl;
    //отделяем корни и ищем их
    intervals = rootsDivision(n, a, b, pow(10, -4), A);
    roots = bisectionMet(n, intervals, A);
    cout << "Найденные узлы - корни многочлена" << endl << endl;
    for (int i = 0; i < n; ++i) {
        cout << "knot #" << i + 1 << ": " << roots[i] << endl;
    }
    double* K = new double[n];
    double** brr = initMatrix(n);
    // заполнение матрицы СЛАУ
    for (int i = 0; i < n; ++i) {
        brr[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            brr[i][j] = pow(roots[j], i);
        }
    }
    //ищем коэффициенты КФНАСТ
    K = Gauss(brr, mom, n);
    cout << "Найденные коэфициенты КФНАСТ:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    //считаем результат
    for (int i = 0; i < n; ++i) {
        res += K[i] * foo(roots[i], test);
    }
    cout << "Значение интеграла полученное КФНАСТ: " << res << endl;
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

    cout << "ИКФ:" << endl << endl;
    cout << "моменты:" << endl;
    double* mom = new double[2 * n];
    for (int i = 0; i < 2 * n; ++i) {
        mom[i] = SimpsonMom(i, 10000, a, b, polyWeight);
    }
    /*for (int i = 0; i < n; ++i) {
        cout << "mom #" << i << "= " << mom[i] << endl;
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

    cout << "Вычисление заданного интеграла:" << endl << endl;
    IKF(0, n, a, b, mom, knots, func, funcWeight);
    cout << "Проверка на многочлене степени N-1:" << endl << endl;
    IKF(n - 1, n, a, b, mom, knots, poly, polyWeight);
*/
    cout << "КФНАСТ:" << endl << endl;
    cout << "моменты:" << endl;
    for (int i = 0; i < 2 * n; ++i) {
        cout << "mom #" << i << "= " << mom[i] << endl;
    }
    cout << endl;

    cout << "Вычисление заданного интеграла:" << endl << endl;
    KFNAST(0, n, a, b, mom, func, funcWeight);
    cout << "Проверка на многочлене степени 2N-1:" << endl << endl;
    KFNAST(2 * n - 1, n, a, b, mom, poly, polyWeight);

    return 0;
}
//FINAL VERSION