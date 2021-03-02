#include<iostream>
using namespace std;
template <class T1, class T2>
T1 sum(T1 a, T2 b) {
	return a + b;
}
template <class T1, class T2>
T1 diff(T1 a, T2 b) {
	return a - b;
}
template <class T1, class T2>
T1 mult(T1 a, T2 b) {
	return a * b;
}
template <class T1, class T2>
T1 div(T1 a, T2 b) {
	return a / b;
}
 
int floatCheck(char* s) {
	if (atof(s) - atoi(s) > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int convert(char s) {
	if (s == '+') {
		return 1;
	}
	else if (s == '-') {
		return 2;
	}
	else if (s == '*') {
		return 3;
	}
	else if (s == '/') {
		return 4;
	}
	else {
		return -1;
	}
}

template<class T1, class T2>
T1 calc(T1 a, T2 b, char s) {
	int choice = convert(s);
	T1(*ops[4])(T1, T2) = { sum, diff, mult, div };

	switch (choice) {
	case 1:
		return ops[0](a, b);
		break;
	case 2:
		return ops[1](a, b);		
		break;
	case 3:
		return ops[2](a, b);		
		break;
	case 4:
		return ops[3](a, b);
		break;
	case -1:
		cout << "error";
		return -1;
		break;
	}
	
}

int main(int argc, char* argv[]) {
	int c = -1;
	char s;
	for (int i = 0; i < argc; ++i) {
		if (argv[i] == "+") {
			c = i;
			s = '+';
		}
		else if (argv[i] == "-") {
			c = i;
			s = '-';
		}
		else if (argv[i] == "*") {
			c = i;
			s = '*';
		}
		else if (argv[i] == "/") {
			c = i;
			s = '/';
		}
		else if (i == argc-1 && c<0){
			cout << "error" << endl;
		}
	}
	if (c == 2) {
		if (floatCheck(argv[4]) == 1 && floatCheck(argv[6]) == 1) {
			cout << "result " << calc(atof(argv[2]), atof(argv[6]), s);
		}
		else if (floatCheck(argv[4]) == 1 && floatCheck(argv[6]) == 0) {
			cout << "result " << calc(atof(argv[2]), atoi(argv[6]), s);
		}
		else if (floatCheck(argv[4]) == 0 && floatCheck(argv[6]) == 1) {
			cout << "result " << calc(atoi(argv[2]), atof(argv[6]), s);
		}
		else if (floatCheck(argv[4]) == 0 && floatCheck(argv[6]) == 0) {
			cout << "result " << calc(atof(argv[2]), atof(argv[6]), s);
		}
	}
	if (c == 2) {
		if (floatCheck(argv[4]) == 1 && floatCheck(argv[6]) == 1) {
			cout << "result " << calc(atof(argv[2]), atof(argv[6]), s);
		}
		else if (floatCheck(argv[4]) == 1 && floatCheck(argv[6]) == 0) {
			cout << "result " << calc(atof(argv[2]), atoi(argv[6]), s);
		}
		else if (floatCheck(argv[4]) == 0 && floatCheck(argv[6]) == 1) {
			cout << "result " << calc(atoi(argv[2]), atof(argv[6]), s);
		}
		else if (floatCheck(argv[4]) == 0 && floatCheck(argv[6]) == 0) {
			cout << "result " << calc(atof(argv[2]), atof(argv[6]), s);
		}
	}if (c == 4) {
		if (floatCheck(argv[2]) == 1 && floatCheck(argv[6]) == 1) {
			cout << "result " << calc(atof(argv[2]), atof(argv[6]), s);
		}
		else if (floatCheck(argv[2]) == 1 && floatCheck(argv[6]) == 0) {
			cout << "result " << calc(atof(argv[2]), atoi(argv[6]), s);
		}
		else if (floatCheck(argv[2]) == 0 && floatCheck(argv[6]) == 1) {
			cout << "result " << calc(atoi(argv[2]), atof(argv[6]), s);
		}
		else if (floatCheck(argv[2]) == 0 && floatCheck(argv[6]) == 0) {
			cout << "result " << calc(atof(argv[2]), atof(argv[6]), s);
		}
	}
	if (c == 6) {
		if (floatCheck(argv[2]) == 1 && floatCheck(argv[4]) == 1) {
			cout << "result " << calc(atof(argv[2]), atof(argv[4]), s);
		}
		else if (floatCheck(argv[2]) == 1 && floatCheck(argv[4]) == 0) {
			cout << "result " << calc(atof(argv[2]), atoi(argv[4]), s);
		}
		else if (floatCheck(argv[2]) == 0 && floatCheck(argv[4]) == 1) {
			cout << "result " << calc(atoi(argv[2]), atof(argv[4]), s);
		}
		else if (floatCheck(argv[2]) == 0 && floatCheck(argv[4]) == 0) {
			cout << "result " << calc(atof(argv[2]), atof(argv[4]), s);
		}
	}

	cout << "result " << calc(10.0f, 10, '-');
	return 0;
}