#include <iostream>
#include <string>

using namespace std;


void edition(string str, int index = 0) {
	if (index == str.length() - 1) {
		cout << str[index];
		return;
	}
	cout << str[index] << "*";
	edition(str, index + 1);
}

int main() {
	string str = "";
	cin >> str;
    edition(str);

	return 0;
}