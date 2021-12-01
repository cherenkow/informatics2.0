#include<iostream>
#include<cmath>

using namespace std;

const double pi = 3.1415926535;

double F(double phi, double k)
{
	double res = 0;
	res = (pi - ((2 * phi + sin(2 * phi)))) / (pi * (1 + (4 / (3 * pi)) * tan(phi))) - k;
	return res;
}


bool close(double val1, double val2)
{
	double eps = 0.00000001;
	return abs(val1 - val2) < eps;
}

double solution(double k)
{
	double a = 0;
	double b = pi / 2;
	double mid = (a + b) / 2;
	while (!close(F(mid, k), 0))
	{

		if (F(mid, k) > 0)
		{
			a = mid;
		}
		else
		{
			b = mid;
		}
		cout << F(mid, k) << "   " << mid << endl;
		mid = (a + b) / 2;
	}
	return mid;
}


int main()
{
	cout << solution(0.3) << endl;
}