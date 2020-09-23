#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int a = 0;
    cin >> a;
    if (a > 2) {
        for (int i = 1; i < a; i += 2) {
            int k = 0;
            if (i == 1) {
                cout << 2 << " ";
            }
            else {
                for (int j = 2; j <= i / 2 + 1; ++j) {
                    if (i % j == 0) {
                        k += 1;
                    }
                    else {
                        k += 0;
                    }
                }
                if (k == 0) {
                    cout << i << " ";
                }

            }
        }
    }
    else { cout << "takix chisel net"; }


    return EXIT_SUCCESS;
}