#include<iostream>
#include"set"

using namespace std;

void print(set <int> s)
{
	for (auto x : s)
		cout << x <<" ";
}
template <typename T>
set <T> uni (set <T> v, set <T> w) {
	set <T> u;
	for (auto x : v)
		u.insert(x);
	for (auto x : w)
		u.insert(x);
	return u;
}

int main() {

	set <int> s;
	set <int> v;
	set <int> w;
	int a = 0;
	while (cin >> a) {
		if (s.count(a) == 0) {
			s.insert(a);
		}
		else {
			if (v.count(a) == 0) {
				v.insert(a);
			}
			else {
				w.insert(a);
			}
		}
	}

	for (auto x : v)
		if (w.count(x) == 0) {
			cout << x << " ";
		}
	return 0;
}