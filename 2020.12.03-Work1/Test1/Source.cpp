#include<iostream>
#include<cmath>
#include <iomanip> 
using namespace std;

double cosinus(double x, int n) {
	double result = 1;
	double sum = -pow(x,2)/2;
	for (int i = 2 ; abs(sum) >= pow(10, -n); i+=2) {
		result += sum;
		sum = (-1) * sum * pow(x, 2) / (i + 1) / (i + 2);
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	const double pi = acos(-1.0);
	cout << "введите угол в градусах" << endl;
	double a;
	cin >> a;
	a = acos(-1.0) / 180 * a;
	cout << "введите количество знаков после запятой" << endl;
	int n;
	cin >> n;
	cout << "косинус введенного угла через бибилиотеку cmath:" << setprecision(n) << cos(a) << endl;
	cout << "косинус посчитанный рядом Тейлора: "<< cosinus(a, n) << endl;
	return 0;
}
