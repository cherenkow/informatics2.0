#include<iostream>
using namespace std;

int mod4(int k) {
	if (k >= 0) {
		return k % 4;
	}
	while (k < 0) {
		k += 4;
	}
	return k;
}
int det(int* a) {
	return mod4(a[0] * a[3] - a[2] * a[1]);
}
void print(int* a) {
	for (int i = 0; i < 4; ++i) {
		cout << a[i] << " ";
	}
}
void power(int*& a, int i, int j, int k, int l) {
	int t0 = i * a[0] + k * a[1];
	int t1 = j * a[0] + l * a[1];
	int t2 = i * a[2] + k * a[3];
	int t3 = j * a[2] + l * a[3];
	a[0] = mod4(t0);
	a[1] = mod4(t1);
	a[2] = mod4(t2);
	a[3] = mod4(t3);
}
bool check(int* a) {
	if (mod4(a[0]) == 1 && mod4(a[3]) == 1 && mod4(a[1]) == 0 && mod4(a[2]) == 0) {
		return true;
	}
	return false;
}
int main() {
	int* a = new int[4]{ 1,0,3,1};
   for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				for (int l = 0; l < 4; ++l) {
					a[3] = l;
					a[2] = k;
					a[1] = j;
					a[0] = i;
					if (det(a) != 1) {
						continue;
					}
					int c = 0;
					int cc = 0;
					for (int kol = 0; kol < 5; ++kol) {
						power(a,i,j,k,l);
						if (check(a) == true) {
							c++;
							cc=kol;
						}
					}
					if (c == 1 && cc == 4) {
						cout << i << " " << j << " " << k << " " << l << endl;
					}
				}
			}
		}
	}   
	return 0;
}