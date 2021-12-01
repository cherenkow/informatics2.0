#include <iostream>
#include <cstdlib>
#include <clocale>
#include <stack>
#include <string>
using namespace std;
bool isDigit(char x) {
	if ('0' <= x && x <= '9') {
		return true;
	}
	return false;
}
double power(int p) {
	int k = 1;
	for (int i = 0; i < p; ++i) {
		k *= 10;
	}
	return k*1.0;
}
bool isOperation(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') {
		return true;
	}
	return false;
}
double operation(double x1, double x2, char x) {
	if (x == '+') {
		return x2 + x1;
	}
	if (x == '-') {
		return x2 - x1;
	}
	if (x == '*') {
		return x2 * x1;
	}
	if (x == '/') {
		return x2 / x1;
	}
	
}
double F2(stack <double> s) {
	cout << "enter the row" << endl;
	string str = "";
	getline(cin, str);
	cout << str << endl;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			continue;
		}
		if (isDigit(str[i])) {
			int k = 0;
			while (isDigit(str[i])) {
				i++;
				k++;
			}
			double x = 0;
			for (int j = 0; j < k; ++j) {
				x+=(str[i - 1 - j] - '0')* power(j);
			}
			s.push(x);
			i--;
			continue;
		}
		if (isOperation(str[i])) {
			double x1 = s.top();
			s.pop();
			double x2 = s.top();
			s.pop();
			s.push(operation(x1, x2, str[i]));
		}
	}
	return s.top();
}
void F1(stack <char> s) {
	cout << "enter the row" << endl;
	string str = "";
	getline(cin, str);
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			continue;
		}
		if (isDigit(str[i])) {
			int k = 0;
			while (isDigit(str[i])) {
				i++;
				k++;
			}
			double x = 0;
			for (int j = 0; j < k; ++j) {
				x += (str[i - 1 - j] - '0') * power(j);
			}
			cout << x << ' ';
			i--;
			continue;
		}
		if (isOperation(str[i])) {
			if (str[i] == '*' || str[i] == '/') {
		

				while (!s.empty() && (s.top() == '*' || s.top() == '/' )) {
					cout << s.top() << ' ';
					s.pop();
				}
				s.push(str[i]);
				continue; 
			}
			if (str[i] == '-' || str [i] == '+'){
				while (!s.empty() && s.top() != '(') {
					cout << s.top() << ' ';
					s.pop();
				}
				s.push(str[i]);
				continue;
			}
		}
		if (str[i] == '(') {
			s.push(str[i]);
			continue;
		}
		if (str[i] == ')') {
			while (s.top() != '(') {
				cout << s.top() << ' ';
				s.pop();
			}
			s.pop();
			continue;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}
int main(){
	setlocale(LC_ALL, "Russian");
	//stack < double > s; // создаем пустой стек
	//cout << F2(s) << endl;
	stack < char > s1;
	F1(s1);
	return 0;
}

