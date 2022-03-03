#include<iostream>
#include"set"
#include"map"

using namespace std;

void enumeration() {
	map <int, int> m;
	int a;
	while (cin >> a) {
		if (m.count(a) == 0) {
			m[a] = 1;
		}
		else {
			m[a] += 1;
		}
	}
	for (auto i = m.begin(); i != m.end(); i++)
		cout << "number:" << i->first << " has appeared " << i->second << " times" << endl;
}

int main() {
	enumeration();

	return 0;
}