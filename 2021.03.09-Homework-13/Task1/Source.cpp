#include<iostream>
#include<fstream>

using namespace std;

bool isSign(char s) {
	return (s == '+' || s == '-');
}

bool isDigit(char s) {
	return (s >= '0' && s <= '9');
}
bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		return true;
	}
	return false;
}

bool isOrder(string str, int& index) {
	if (str[index] == 'E') {
		int memindex = index;
		index++;
		if (isNatural(str, index) || isSign(str[index++]) && isNatural(str, index)) {
			return true;
		}
		index = memindex;
		return false;
	}
	return false;
}
bool isMantissa(string str, int& index) {
	if (!isNatural(str, index)) {
		return false;
	}
	if (str[index++] == '.' && isNatural(str, index)) {
		return true;
	}
}
bool isNumber(string str, int& index) {
	if (isMantissa(str, index) && isOrder(str, index) || isSign(str[index++]) && isMantissa(str, index) && isOrder(str, index)) {
		return true;
	}
	return false;
}
int main() {
	ifstream fin("in.txt");
	string str;
	while (!fin.eof()) {
		fin >> str;
	}
	cout << str << endl;
	int k = 0;
	if (isNumber(str, k) == true) {
		cout << "=)" << endl;
	}
	else {
		cout << "=(" << endl;
	}
	fin.close();
	return 0;
}