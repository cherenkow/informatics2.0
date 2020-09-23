#include<iostream>
#include<math.h>

using namespace std;
int main(int argc, char* argv[])
{
    int a = 0;
    int k;
    cin >> a;
    if (a != 1) {
        if (a / sqrt(a) == sqrt(a)) {
            k = 1;
        }
        else {

            k = 2;
        }
        for (int i = 2; i <= sqrt(a); ++i) {
            if (a % i == 0) {
                k += 2;
            }
        }
        cout << k;
    }
    else { cout << 1; }


    return EXIT_SUCCESS;
}