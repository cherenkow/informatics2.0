#include<iostream>
using namespace std;

void binary(int*& a, int k) {
	while (k >= 1) {
		for (int i = 0; i < 5; ++i) {
			a[4 - i] = k % 2;
			k = k / 2;
		}
	}
}
void print(int* a) {
	for (int i = 0; i < 5; ++i) {
		cout << a[i] << " ";
	}
}
void sigma0(int*& a) {
	int temp = a[2];
	a[2] = a[1];
	a[1] = a[0];
	a[0] = temp;
	temp = a[3];
	a[3] = a[4];
	a[4] = temp;
}
void sigma1(int*& a) {
	int temp = a[4];
	a[4] = a[3];
	a[3] = a[0];
	a[0] = temp;
	temp = a[1];
	a[1] = a[2];
	a[2] = temp;
}
void stable(int*& a) {
	for (int i = 0; i < 5; ++i) {
		a[i] = i + 1;
	}

}
bool check(int* a) {
	int k = 0;
	int* c = new int[5]{ 1,2,3,5,4 };
	for (int i = 0; i < 5; ++i) {
		if (a[i] != c[i]) {
			++k;
		}
	}
	if (k == 0) { return true; }
	else { return false; }
}

int power(int k) {
	int c = 2;
	for (int i = 1; i < k; ++i) {
		c *= 2;
	}
	return c;
}
void stable2(int*& a) {
	for (int i = 0; i < 5; ++i) {
		a[i] = 0;
	}

}

int main() {
	int* a = new int[5]{ 1, 2,3,4,5 };
	int* b = new int[5]{ 0 };
	int* c = new int[5]{ 0 };
		while (true) {
			////////////////
			if (c[0] == 666) {
				break;
			}
			cout << "enter permutation" << endl;
			for (int i = 0; i < 4; ++i) {
				cin >> c[i];
			}
			for (int k = 0; k < 4; ++k) {
				stable2(b);
				cout << "product of " << 5 - k << " permutations" << endl;
				for (int i = 0; i < power(5 - k); ++i) {
					binary(b, i);
					print(b); cout << " ";
					for (int j = 4; j >= 0 + k; --j) {
						if (b[j] == 0) {
							sigma0(a);
						}
						else {
							sigma1(a);
						}
					}
					if (check(a) == true) {
						cout << "HERE" << endl;
					}
					cout << "{ "; print(a); cout << "}" << endl;
					stable(a);
				}
			}
		}
	/*for (int k = 0; k < 4; ++k) {
		stable2(b);
		cout << "product of " << 5 - k << " permutations" << endl;
		for (int i = 0; i < power(5 - k); ++i) {
			binary(b, i);
			print(b); cout << " ";
			for (int j = 4; j >= 0 + k; --j) {
				if (b[j] == 0) {
					sigma0(a);
				}
				else {
					sigma1(a);
				}
			}
			if (check(a) == true) {
				cout << "HERE" << endl;
			}
			cout << "{ "; print(a); cout << "}" << endl;
			stable(a);
		}
	} */
	return 0;
}