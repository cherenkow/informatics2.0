#include<iostream>
#include<clocale>
#include <list>
using namespace std;
struct Subscriber {
	long long number;
	string name;
	string adress;

	Subscriber() : number(0), name("Sanek"), adress("St Petersburg") {}
	Subscriber(long long num, string n, string a) : number(num), name(n), adress(a) {}
};
ostream& operator << (ostream& st, Subscriber z)
{
	return st << "���:" << z.name << " �����:" << z.number << " �����:" << z.adress << endl;
}
istream& operator >> (istream& st, Subscriber& z)
{
	st >> z.name >> z.number >> z.adress;
	return st;
}
void printMenu()
{
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - ������� �������� �� ������" << endl;
	cout << "3 - ����������� ��� � ����� �������� �� ������ ��������" << endl;
	cout << "4 - ������� ����������� ����" << endl;
}
void addAbonent(long long n, string nn, string a, list<Subscriber>& l) {
	Subscriber x(n, nn, a);
	l.push_back(x);
}
void delAbonent(long long n, list <Subscriber>& l) {
	Subscriber x;
	for (auto i = l.begin(); i != l.end(); ++i) {
		x = *i;
		if (x.number == n) {
			l.erase(i);
			return;
		}
	}
	cout << "������";
}
void printAbonent(long long n, list <Subscriber>& l) {
	Subscriber x;
	for (auto i = l.begin(); i != l.end(); ++i) {
		x = *i;
		if (x.number == n) {
			cout << x << endl;
			return;
		}
	}
	cout << "������";
}
void switchCase(int choice, list <Subscriber>& l) {
	cout << endl;
	string na = "sdf";
	string a = "sdf";
	long long x = 0;
	switch (choice) {
	case 1:
		cout << "������� ������ ��������:" << endl;
		cout << "������� �����:" << endl;
		cin >> x;
		cout << "������� ���:" << endl;
		cin >> na;
		cout << "������� �����:" << endl;
		cin >> a;
		addAbonent(x, na, a, l);
		break;
	case 2:
		cout << "������� ����� ��������:" << endl;
		cin >> x;
		delAbonent(x, l);
		break;
	case 3:
		cout << "������� ����� ��������:" << endl;
		cin >> x;
		printAbonent(x, l);
		break;
	case 4:
		cout << "������� �������� � ����:" << endl;
		for (auto i = l.begin(); i != l.end(); ++i) {
			cout << *i << endl;
		}
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int choice = -1;
	list <Subscriber> l;
	Subscriber x (2,"����","��������");
	Subscriber xx(546, "����", "����������");
	Subscriber xxx(547658, "����", "�������");
	l.push_back(x);
	l.push_back(xx);
	l.push_back(xxx);
	for (auto i = l.begin(); i != l.end(); ++i) {
		cout << *i << endl;
	}
	
	while (choice != 0)
	{
		printMenu();
		cin >> choice;
		switchCase(choice, l);
	}

	return 0;
}
//c������ ������ � ������� � �����, ����� �������� � ����� � ��������� ��������� ���
