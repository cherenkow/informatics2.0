#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int x;
    cin >> x;
    for (int i = 0; i < 1000; ++i) {
        int a = i / 100;
        int b = i / 10 - (i / 100) * 10;
        int c = i % 10;
        if (a + b + c == x) {
            for (int j = 0; j < 1000; ++j) {
                int aa = j / 100;
                int bb = j / 10 - (j / 100) * 10;
                int cc = j % 10;
                if (aa + bb + cc == x) {
                    cout << a << b << c << aa << bb << cc << " ";
                }
            }
        }

    }

    return EXIT_SUCCESS;
}