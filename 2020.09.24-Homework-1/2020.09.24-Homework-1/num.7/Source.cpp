#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int a;
    cin >> a;
    int b;
    cin >> b;
    int k = a;
    for (int i = 1; i < b; ++i) {
        a *= k;
    }
    cout << a;

    return EXIT_SUCCESS;
}