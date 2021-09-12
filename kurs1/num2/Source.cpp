#include <iostream>
#include <string>

using namespace std;

int maxN(int a, int b) {
	return (a > b ? a : b);
}
int maxNumber(string str, int max = -1, int index = 0) {
	if (max == 9) {
		return max;
	}
	if (index >= str.length()) {
		return max;
	}
	max = maxN(max, str[index] - '0');
	return maxNumber(str, max, index + 1);

}

int main() {
	string str = "";
	cin >> str;
	cout << maxNumber(str);

	return 0;
}


