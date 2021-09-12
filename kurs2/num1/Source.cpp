#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a == b) {
		return a;
	}
	return (a > b ? gcd(a - b, b) : gcd(b - a, a));
}
int main() {

	int a = 0;
	int b = 0;
	cin >> a >> b;
	cout << gcd(a, b);

	return 0;
}
