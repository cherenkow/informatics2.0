#include <iostream>
#include <string>

using namespace std;


int countNumber(string str, int index = 0) {
	if (index >= str.length()) {
		return 0;
	}
	int count = 0;
	if (str[index] >= '0' && str[index] <= '9') {
		count++;
	}
	return count + countNumber(str, index + 1);
}

int main() {
	string str = "";
	cin >> str;
	cout << countNumber(str);

	return 0;
}