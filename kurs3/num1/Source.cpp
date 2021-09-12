#include <iostream>;
using namespace std;

void sort(int*& arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-i-1; ++j) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void print(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
}

int sum(int* arr, int n) {
	int k = 0;
	for (int i = 0; i < n; ++i) {
		k += arr[i];
	}
	return k;
}

bool canDo(int* coins, int*& used,int n, int M, int count = 0 ) {
	for (int i = 0; i < M; ++i) {
		if (used[i]) {
			continue;
		}
		count += coins[i];
		if (count == n) {
			return true;
		}
		for (int j = 0; j < M; ++j) {
			if (i == j || used[j]) {
				continue;
			}
			int tempI = coins[i];
			int tenpJ = coins[j];
			used[j] = true;
			count += coins[j];
		}
	}
	return false;
}
int main() {
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int M = 2 * m;
	int* coins = new int[M];
	bool* used = new bool[M]{ 0 };
	for (int i = 0; i < m; ++i) {
		cin >> coins[2*i];
		coins [2*i + 1] = coins[2*i];
	}
	sort(coins, M);
	print(coins,M);
	return 0;
}