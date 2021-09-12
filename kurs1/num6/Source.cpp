#include <iostream>
#include <string>

using namespace std;

void edition(string str, int index = 0) {
	if (index >= str.length()) {
		return;
	}
	cout << str[index];
	edition(str, index + 1);
	if (str[index] == '(') {
		cout << ")";
	}
	else {
		cout << str[index];
	}
}

int main() {
	string str = "";
	cin >> str;
	edition(str);
	return 0;
}