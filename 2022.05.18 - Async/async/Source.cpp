#include<iostream>

using namespace std; 

int main()
{
	int a = 1;
	for (int i = 0; i < 5; ++i) {
		cout << "10^"<<i << " % 17 =" << a % 17 << endl;
		a *= 10;
	}
	return 0;
}