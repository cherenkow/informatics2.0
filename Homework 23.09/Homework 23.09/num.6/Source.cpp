#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int a = 0;

    cin >> a;
    int k = 1;
    for (int i = 1; i <= a; ++i) {
        k *= i;
    }
    cout << k;

    return EXIT_SUCCESS;
}