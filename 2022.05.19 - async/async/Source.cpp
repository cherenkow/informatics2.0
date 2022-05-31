#include<iostream>
#include<string>
#include <future>

using namespace std;
//const int n = 10'000'000;
const int n = 6;
int block_size(int threads)
{
	return n / threads + (n % threads ? 1 : 0);
}

int count(int a, int b, int power)
{
	int r = s[a]-'0';
	for (int i = 0; i < b - a + 1; ++i) {
		r = (r * (10) + (s[i + 1]-'0'))%17;
	}
	return r * power;
}


int multiThreads(int threads, string s, int* arr)
{
	vector <future <int>> fut(threads);
	int size = block_size(threads);
	int fIndex = 0;
	int i = 0;
	int k = 0;
	int r = 0;
	int a = 0;
	while (fIndex < n) {
		k = fIndex + size - 1; //индекс последнего элемента рассм подстроки
		a = arr[(n - 1 - k) % 16];
		fut[i] = async(count,fIndex, fIndex + size - 1, a);
		fIndex = fIndex + size;
		i++;
	}
	for (int j = 0; j < i; ++j)
	{
		r += fut[j].get();
	}
	return r;
}
int main()
{
	int* arr = new int[16];
	int k = 1;
	for (int i = 0; i < 16; ++i) 
	{
		arr[i] = k % 17;
		k = 10* arr[i];
	}
	for (int i = 0; i < 16; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	string s = "100000";
	int threadsNum = 2;
	cout<< multiThreads(threadsNum, s, arr);

	return 0;

}