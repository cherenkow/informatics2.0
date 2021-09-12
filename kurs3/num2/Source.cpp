#include <iostream>
using namespace std;

bool canDo(int n, int rest = 8) {
	if (n < 0) {
		return false;
	}
	if (n == 0) {
		return true;
	}
	if (rest <= 0) {
		return false;
	}
	int r = 0;
	while (r * r * r < n) {
		++r;
	}
	for (int i = r; i >= 0; --i) {
		if (canDo(n - i * i * i, rest - 1)) {
			cout << i << " ";
			return true;
		}
	}
	return false;
}

int main() {
	int n = 0;
	cin >> n;
	if (!canDo(n)) {
		cout << "IMPOSSIBLE";
	}
	return 0;
}