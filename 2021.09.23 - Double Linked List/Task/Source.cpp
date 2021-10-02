#include <iostream>
#include <cstdlib>
using namespace std;
struct DNode
{
	int data;
	DNode* next;
	DNode* prev;
	DNode(int d = 0, DNode* n = nullptr, DNode* p = nullptr) :
		data(d), next(n), prev(p) {}
};
struct DList
{
	DNode* head, * tail;
	DList() { head = nullptr; tail = nullptr; }
	~DList() {
		DNode* temp = head;
		while (temp != nullptr) {
			DNode* t = temp;
			temp = temp->next;
			delete t;
		}
	}
	// вбивать надо номер узла 
	DNode* getPtr(int num) {
		if (length() < num || num < 0) {
			return nullptr;
		}
		DNode* t = head;
		for (int i = 1; i < num; ++i); {
			t = t->next;
		}
		return t;
	}
	void del() {
		for (int i = 0; i < length(); ++i) {
			delFirst();
		}
	}
	void addFirst(int d)
	{
		DNode* t;
		t = new DNode(d, head, nullptr);
		if (head == nullptr)
		{
			tail = t;
		}
		else
		{
			head->prev = t;
		}
		head = t;
	}
	void addLast(int d) {
		if (length() == 0) {
			addFirst(d);
		}
		DNode* t = new DNode(d, nullptr, tail);
		tail->next = t;
		tail = t;

	}
	void addAfterFirst(int d) {
		if (length() == 0) {
			addFirst(d);
			return;
		}
		else if (length() == 1) {
			addLast(d);
			return;
		}
		DNode* t = new DNode(d, head->next, head);
		DNode* t1 = head->next;
		t1->prev = t;
		head->next = t;
		return;
	}
	void delFirst() // удалить узел из начала списка
	{
		if (head == nullptr)
		{
			cout << "List is empty";
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		DNode* t;
		t = head;
		head = head->next;
		head->prev = nullptr;
		delete t;
	}
	void delLast() {
		if (length() == 0 || length() == 1) {
			delFirst();
		}
		DNode* t = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete t;

	}
	void delSecond() {
		if (length() < 2) {
			cout << "ERROR";
			return;
		}
		if (length() == 2) {
			delLast();
		}
		DNode* t = head->next;
		DNode* t1 = t->next;
		t1->prev = head;
		head->next = t1;
		delete t;

	}
	void insert(int index, int data) {
		if (index < 0 || index > length()) {
			cout << "ERROR" << endl;
			return;
		}
		if (index == 0) {
			addFirst(data);
			return;
		}
		if (index == 1) {
			addAfterFirst(data);
			return;
		}
		if (index == length()) {
			addLast(data);
			return;
		}
		DNode* t1 = getPtr(index);
		DNode* t2 = t1->next;
		DNode* t = new DNode(data, t2, t1);
		t1->next = t;
		t2->prev = t;

	}
	void delp(int index) {
		if (index < 0 || index >= length()) {
			cout << "ERROR" << endl;
			return;
		}
		if (index == 0) {
			delFirst();
			return;
		}
		if (index == length() - 1) {
			delLast();
			return;
		}
		if (index == 1) {
			delSecond();
		}
		DNode* t1 = getPtr(index);
		DNode* t = t1->next;
		DNode* t2 = t->next;
		t1->next = t2;
		t2->prev = t1;
		delete t;
	}
	int length() {
		int k = 0;
		DNode* p = head;
		while (p != nullptr) {
			k++;
			p = p->next;
		}
		return k;
	}
	void print()
	{
		DNode* p = head;
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}
	void printB()
	{
		DNode* p = tail;
		while (p != nullptr)

		{
			cout << p->data << "\t";
			p = p->prev;
		}
		cout << endl;
	}
	void Print()
	{
		print();
		printB();
		cout << endl;
	}
	void reverse() {
		if (length() == 0) {
			cout << "EMPTY" << endl;
			return;
		}
		if (length() == 1) {
			return;
		}
		int l = length();
		DNode* temp = head;
		for (int i = 1; i < l; ++i) {
			temp->prev = temp->next;
			temp = temp->next;
		}
		tail->prev = nullptr;
		DNode* Last = tail;
		tail = head;
		for (int i = l; i >= 2; --i) {
			DNode* t1 = getPtr(i);
			DNode* t2 = getPtr(i - 1);
			t1->next = t2;
			t2->next = nullptr;
		}
		head->next = nullptr;
		head = Last;
	}
};
int main()
{
	DList l;
	l.addFirst(3);
	l.addFirst(2);
	l.addFirst(1);
	l.Print();
	l.addAfterFirst(666);
	l.Print();
	l.delLast();
	l.Print();
	l.delSecond();
	l.Print();
	l.insert(2, 3);
	l.insert(2, 9876);
	l.insert(0, 0);
	l.Print();
	l.delSecond();
	l.Print();
	l.delp(2);
	l.Print();
	l.reverse();
	l.Print();

	return EXIT_SUCCESS;
}