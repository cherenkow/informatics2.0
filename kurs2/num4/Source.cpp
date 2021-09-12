#include <iostream>

using namespace std;

void print(int** & arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void fill(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = 0;
		}
	}
}
void spiral(int** & arr,int n, int k = 0, int index = 1) {
	if (k * 2 >= n) {
		return;
	}
	if (n % 2 == 1) {
		arr[n / 2][n / 2] = n * n;
	}
	for (int i = k; i < n - 1 - k; ++i,++index) {
		arr[k][i] = index;
	}
	for (int i = k; i < n - 1 - k; ++i, ++index) {
		arr[i][n - 1 - k] = index;
	}
	for (int i = n - k - 1; i > k; --i, ++index) {
		arr[n - 1 - k][i] = index;
	}
	for (int i = n - k - 1; i > k; --i, ++index) {
		arr[i][k] = index;
	}
	spiral(arr, n, k + 1, index);
}
int main() {
	int n = 0;
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}
	fill(arr, n);
	spiral(arr,n);
	print(arr, n);

	return 0;
}
