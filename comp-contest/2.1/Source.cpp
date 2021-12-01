#include<iostream>
#include<cmath>

const double g = 9.81;
const double Pi = 3.1415926535;
const double h = 0.000001;
const double R = 0.5;

using namespace std;

double func(double x, double y)
{
	return (((2*g)/(R*R))*sin(y));
}

bool close(double val, double val1, double eps = 0.000001)
{
	return (abs(val - val1) < eps);
}

double nexty(double x, double y)
{
	double k1 = h * func(x, y);
	double k2 = h * func(x + h / 2, y + k1 / 2);
	double k3 = h * func(x + h / 2, y + k2 / 2);
	double k4 = h * func(x + h, y + k3);
	double res = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	return res;
}

typedef unsigned long long ulong;

int main()
{
	double T = 1;
	double x0 = 0;
	double y0 = 0.2*Pi;
	double x1 = 0;
	double h = 0.000001;
	double y1 = 0;
	ulong step = 0;

	while (!close(x1, T))
	{
		//cout << x0 << " " << y0 << endl;
		++step;
		x1 = step * h;
		//x1 += h;
		y1 = nexty(x0, y0);
		x0 = x1;
		y0 = y1;
	}

	cout << x0 << " " << y0*R << endl;

	return 0;
}
