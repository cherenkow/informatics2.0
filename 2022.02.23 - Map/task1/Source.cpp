#include<iostream>
#include"set"
#include"map"

using namespace std;

void print(set <int> s)
{
	for (auto x : s)
		cout << x << " ";
}
template <typename T>
set <T> uni(set <T> v, set <T> w) {
	set <T> u;
	for (auto x : v)
		u.insert(x);
	for (auto x : w)
		u.insert(x);
	return u;
}

int main() {


	map <int, int> m;
	int a;
	while (cin >> a) {
		if (m .count(a) == 0) {
			m[a] = 1;
		}
		else {
			m[a] += 1;
		}
	}
	for (auto i = m.begin(); i != m.end(); i++)
		cout <<"number:" << i->first << " has appeared " << i->second << " times"<< endl;
	
	return 0;
}