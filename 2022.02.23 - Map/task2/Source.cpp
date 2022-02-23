#include<iostream>
#include"set"
#include"map"

using namespace std;

map <int, int> mapping() {
	int n = 0;
	cout << "enter the number of pairs" << endl;
	cin >> n;
	map <int, int> f;
	int key; 
	int value;

	for (int i = 0; i < n; ++i) {
		cin >> key;
		cin >> value;
		f[key] = value;
	}
	return f;
}

void mapping2() {
	map <int, int> m = mapping();
	int a;
	while (cin >> a) {
		if (m.count(a) == 0) {
			cout << a << " not defined" << endl;
		}
		else {
			cout << m[a] << " defined" << endl;
		}
	}
}

template <class T1, class T2>
map <T1, T2> sumMap(map <T1, T2> m1, map <T1, T2> m2) {
	map <T1,T2> m0;
	for (auto i = m1.begin(); i != m1.end(); i++) {
		m0[i] = m1[i] + m2[i];
	}
	return m0;
}

template <class T1, class T2, class T3>
map<T1, T3> compMap(map<T1, T2> m1, map<T2, T3> m2) {
	for (auto i = m1.begin(); i != m1.end(); i++) {
		m0[i] = m2[m1[i]];
	}
	return m0;
}
int main() {

	map <int, int> m;
	// задание 2
	/* m = mapping();
	for (auto i = m.begin(); i != m.end(); i++)
		cout << "key: " << i->first << " info" << i->second << endl; */
	//задание 3
	//mapping2();

	return 0;
}