#include <iostream>

using namespace std;

void inverse(int n) {
	if (n == 0) {
		return;
	}
	int x = 0;
	cin >> x;
	inverse(n - 1);
	cout << x << " ";
}
int main() {
	int n = 0;
	cin >> n;
	inverse(n);

	return 0;
}
