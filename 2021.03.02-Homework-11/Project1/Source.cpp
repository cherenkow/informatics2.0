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
	for (int i = 0; i < argc;++i) {
		cout << "argv [" << i << "] " << argv[i] << endl;
	}
	
	cout << "result " << calc(10.0f, 3, '/');



	return 0;
}