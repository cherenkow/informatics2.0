#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void enlarge(vector <double>& v) {
	vector <double> v1;
	for (unsigned int i = 0; i < v.size() - 1; ++i) {
		v1.push_back(v[i]);
		v1.push_back(v[i] + v[i + 1]);
	}
	vector <double> ::iterator i;
	i = v.end() - 1;
	v1.push_back(*i);
	v = v1;
}
void del(vector <double>& v) {
	vector <double> v1;
	for (unsigned int i = 1; i < v.size(); i += 2) {
		v1.push_back(v[i]);
	}
	v = v1;
}
void print(vector <double> v) {
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << ' ';
	cout << endl;
}
vector <double> contact(vector <double> v, vector <double>v1) {
	vector <double> w(v.size() + v1.size());
	copy(v.begin(), v.end(), w.begin());
	copy(v1.begin(), v1.end(), w.begin() + v.size());
	return w;
}
vector <double> repeat(vector <double> v, int n) {
	vector <double> w(v.size() * n);
	for (int i = 0; i < n; ++i) {
		copy(v.begin(), v.end(), w.begin() + i * v.size());
	}

	return w;
}
vector <double>::iterator secondFind(vector <double> v, double k) {
	vector <double>::iterator i;
	i = find(v.begin(), v.end(), k);
	vector <double>::iterator ii;
	i = find(i, v.end(), k);
	return i;
}
int main()
{
	cout << "which element do you want to find" << endl;
	int kk = 0;
	cin >> kk;
	vector <double> v;
	double x;
	while (cout << "Enter data", cin >> x) {
		v.push_back(x);
	}
	print(v);
	enlarge(v);
	print(v);

	vector <double>::iterator ii = secondFind(v, kk);
	cout << *(ii - 1);
	del(v);
	print(v);
	double* arr = new double[v.size()];
	copy(v.begin(), v.end(), arr);
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	vector <double> v1{ 1,2,3,4,5,6,7 };
	vector <double> v3;
	v3 = contact(v, v1);
	print(v3);
	v3 = repeat(v, 3);
	print(v3);
	return 0;
}