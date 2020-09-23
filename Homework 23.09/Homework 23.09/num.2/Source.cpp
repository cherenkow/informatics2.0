#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int a = 0;
    int k = -1;
    int b = 0;
    cin >> a;
    cin >> b;
    if (b > a) {
        cout << 0;
    }
    else {
        while (a >= 0) {
            k += 1;
            a = a - b;
        }
        cout << k;
    }

    return EXIT_SUCCESS;
}