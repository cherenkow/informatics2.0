#include <iostream>


using namespace std;

int count(int** messages, int n, int root) {
	int kol = 0;
	for (int i = 0; i < n; ++i) {
		if (root == messages[i][0]) {
			kol++;
		}
		if (root == messages[i][1]) {
			kol += count(messages, n, messages[i][0]);
		}
	}
	return kol;
}

int main() {
	int n = 0;
	cin >> n;
	int** messages = new int* [n];
	for (int i = 0; i < n; ++i) {
		messages[i] = new int[2];
		cin >> messages[i][0] >> messages[i][1];
	}
	int root = 0;
	cin >> root;
	cout << count(messages, n, root);
	
	return 0;
}