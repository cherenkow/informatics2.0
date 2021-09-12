#include <iostream>
#include <string>

using namespace std;
 
// a s d f g h    6 надо выводить до 6/2 -1
// a s d f g      5 надо выводить до 

void edition(string str, int index = 0) {
	cout << str[index];
	if ((index+1)*2< str.length()) {
		cout << "(";
		edition(str, index + 1);
		cout << ')';
	}
	if (index != str.length() / 2 ) {
		cout << str[str.length() - 1 - index];
	}
}

int main() {
	string str = "";
	cin >> str;
	
	edition(str);
	

	return 0;
}