#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int x = 0;
	cin >> x;
	int a = x * x;
	int b = 0;
	b = (a + 1) * (a + x) + 1;
	cout << b;
	return EXIT_SUCCESS;
}