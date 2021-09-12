#include <iostream>
#include <string>

using namespace std;

void edition(string str, int index = 0) {
	if (index >= str.length()/2) {
		if (index * 2 + 1 == str.length()) {
			cout << str[index];
		}
		return;
	}
	if (str[index] != str[str.length() - 1 - index]) {
		cout << str[index];
	}
	edition(str, index + 1);	
	if (str[index] != str[str.length() - 1 - index]) {
		cout << str[str.length() - 1 - index];
	}
}

int main() {
	string str = "";
	cin >> str;
	edition(str);
	return 0;
}
// 0 1 2 3 4 5 6  - vsego 7
// a s d f g h j