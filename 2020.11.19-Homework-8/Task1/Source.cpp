#include<iostream>
#include "LinkedList.h"

using namespace std;

void printList(LinkedList list)
{
	cout << "PRINTED LIST : " << list << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	LinkedList list;
	LinkedList list2;
	LinkedList list3;

	for (int i = 1; i < 6; ++i) {
		list.addToHead(6-i);
	}
	for (int i = 6; i < 11; ++i) {
		list.addToTail(i);
	}
	list3.addToHead(99);
	cout << "list = "<<list << endl;
	cout << "list 2 = "<<list2 << endl;
	cout << "list 3 = "<<list3 << endl << endl;
	cout << "extracting" << endl;
	list.extractHead();
	cout << list << endl;
	list.extractTail();
	cout << list << endl;
	list.extract(0);
	list.extract(23);
	cout << list << endl << endl;

	list2.extractHead();
	cout << list2<< endl;
	list2.extractTail();
	cout << list2 << endl;
	list2.extract(0);
	list2.extract(23);
	cout << list2 << endl << endl;

	list3.extractHead();
	cout << list3 << endl;
	list3.addToHead(99);
	list3.extractTail();
	cout << list3 << endl;
	list3.addToHead(99);
	list3.extract(23);
	list3.extract(0);
	cout << list3 << endl << endl;

	cout << "operator -=" << endl;
	list3.addToHead(99);
	list -= 4;
	list -= 44;
	cout << list << endl << endl;
	list2 -= 67;
	list2 -= 0;
	cout << list2 << endl << endl;
	list3 -= 1;
	cout << list3 << endl;
	list3 -= 0;
	cout << list3 << endl << endl;

	cout << "contains (+indexOf inside contains) func" << endl;
	list3.addToHead(99);
	cout << (list.contains(8) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list.contains(999) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list2.contains(99) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list2.contains(8) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list3.contains(99) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list3.contains(8) == true ? "элемент есть в списке" : "элемента нет в списке") << endl << endl;
	cout << "operator =" << endl;
	LinkedList list0;
	list0 = list;
	cout << "list0 = list " << list0 << endl;
	list0 = list2;
	cout << "list0 = list2 " << list0 << endl;
	list0 = list3;
	cout << "list0 = list3 " << list0 << endl << endl;

	cout << "swap func" << endl;
	int end = list.length() - 1;
	list.swap(0, 2);
	cout << list << endl << endl;
	list.swap(0, 1);
	cout << list << endl << endl;
	list.swap(end, end-1);
	cout << list << endl << endl;
	list.swap(end, end - 2);
	cout << list << endl << endl;
	list.swap(1, 2);
	cout << list << endl << endl;
	list.swap(1, 4);
	cout << list << endl << endl;
	list.swap(1, end-1);
	cout << list << endl << endl;
	list.swap(1, 1);
	cout << list << endl << endl;
	list.swap(1, 22);
	cout << list << endl << endl;
	list3.swap(1, 2);
	cout << list3 << endl << endl;
	list2.swap(1, 2);
	cout << list2 << endl << endl;
	return 0;
}