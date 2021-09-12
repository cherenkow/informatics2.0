#include <iostream>

using namespace std;

bool isFull(int row[11], int n) {
	for (int i = 1; i <= n; ++i) {
		if (row[i] == 0) {
			return false;
		}
	}
	return true;
}

int getFirst(int row[11], int n) {
	for (int i = 1; i < n; ++i) {
		if (row[i] == 1) {
			return i;
		}
	}
	return -1;
}


void fillRow(int row[11], int n, bool first = true) {
	if (isFull (row,n)) {
		return;
	}
	int index = 1;
	if (!first) {
		index = getFirst(row, n) + 1;
	}
	if (row[index] == 0) {
		cout << index << " ";
		row[index] = 1;
	}
	else {
		cout << -index << " ";
		row[index] = 0;
	}
	fillRow(row,n,!first);
}

int main() {
	int row[11] = { 0 };
	int n = 0;
	cin >> n;
	fillRow(row,n);
	return 0;
}