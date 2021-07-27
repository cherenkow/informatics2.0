#include <iostream>

using namespace std;

bool canGet(int n) {
	if (n < 1) {
		return false;
	}
	if (n == 1) {
		return true;
	}
	return canGet(n - 3) || canGet(n - 5);
}

int main() {
	int n = 0;
	cin >> n;
	cout << (canGet(n)? "YES": "NO");



	return 0;
}


