#include <iostream>

using namespace std;

int rooms(char lab [12][12], int a, int b) {
	if (lab[a][b] == '*') {
		return 0;
	}
	int count = 1;
	lab[a][b] = '*';
	count += rooms(lab, a+1, b);
	count += rooms(lab, a, b+1);
	count += rooms(lab, a-1, b);
	count += rooms(lab, a, b-1);
	return count;
}
	
int main() {

	int n = 0;
	cin >> n;
	char lab[12][12];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> lab[i][j];
		}
	}
	int x1 = 0;
	int x2 = 0;
	cin >> x1 >> x2;
	cout << rooms(lab,x1,x2);

	return 0;
}
