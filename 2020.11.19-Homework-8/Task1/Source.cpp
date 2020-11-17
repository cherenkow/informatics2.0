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
	cout << "list 3 = "<<list3 << endl;

	list.extractHead();
	cout << list << endl;
	list.extractTail();
	cout << list << endl;
	list.extract(2);
	list.extract(22);
	cout << list << endl;
	list -= 4;
	list -= 44;
	cout << list << endl;
	cout << list3.indexOf(99) << endl;
	
	cout << list.indexOf(56) << endl;
	cout << (list.contains(8) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list.contains(999) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list2.contains(99) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list2.contains(8) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list3.contains(99) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;
	cout << (list3.contains(8) == true ? "элемент есть в списке" : "элемента нет в списке") << endl;

	cout << endl;
	cout << "LIST" << list << endl;
	cout << list.get(5) << endl;
	cout << list.get(2) << endl;
	list.set(3, 4);
	cout << list << endl;
	list.set(4, 65);
	cout << list << endl;

	cout << "list[2] = " << list[2] << endl;
	list[1] = 12354;
	cout << "list[1] = " << list[1] << endl;
	cout << list << endl;
	list[-12] = -12;
	list[5123] = 1;
	cout << list << endl;

	return 0;
}