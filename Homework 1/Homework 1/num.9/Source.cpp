#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{

    int n;
    cin >> n;
    if (n != 0) {
        int k = -1;
        int l = (unsigned int)k >> (32 - n);
        cout << l;
    }
    else { cout << 0; }


    return EXIT_SUCCESS;
}