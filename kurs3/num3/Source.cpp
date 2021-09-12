#include <iostream>;
#include <cmath>;
#include <iomanip>;

using namespace std;

double parallel(double c1, double c2) {
	return (c1 + c2);
}

double sequently(double c1, double c2) {
	return (c1 * c2)/(c1+c2);
}

double bestPr(double c[7], bool used[7], double C, int n, double best) {
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (abs(C - c[i]) < abs(C - best)) {
			best = c[i];
		}
		for (int j = 0; j < n; ++j) {
			if (i == j || used[j]) {
				continue;
			}
			double tempI = c[i];
			double tempJ = c[j];
			used[j] = true;

			c[i] = parallel(tempI, tempJ);
			best = bestPr(c, used, C, n, best);

			c[i] = sequently(tempI, tempJ);
			best = bestPr(c, used, C, n, best);

			c[i] = tempI;
			c[j] = tempJ;
			used[j] = false;
		}
	}
	return best;
}
int main() {
	int n = 0;
	double C = 0;
	cin >> n >> C;
	double c[7] = { 0 };
	bool used[7] = { 0 };
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		used[i] = false;
	}
	cout << fixed << setprecision(6) << bestPr(c,used,C,n,c[0]);
	return 0;
}