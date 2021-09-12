#include <iostream>

using namespace std;

void print(int chain[6], int n) {
	for (int i = 0; i < n; ++i) {
		cout << chain[i] << " ";
	}
	cout << endl;
}
void chains(int chain[6], int k,int n, int index = 0) {
	if (index == n) {
		print(chain, n);
		return;
	}
	for (int i = 1; i <= k; ++i) {
		chain[index] = i;
		chains(chain, k, n, index + 1);
	}
}
int main() {
	int n = 0;
	int k = 0;
	cin >> n >> k;
	int chain[6] = { 0 };
	chains(chain, k, n);
	
}
