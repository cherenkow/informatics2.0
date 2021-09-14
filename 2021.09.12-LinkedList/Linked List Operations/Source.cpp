#include <iostream>
#include <cstdlib>

using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int d = 0, Node* n = nullptr) :
		data(d), next(n) {}

};
struct List
{
	Node* head;
	List()
	{
		head = nullptr;
	}


	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	int length() {
		Node* p = head;
		int i = 0;
		while (p != nullptr)
		{
			i++;
			p = p->next;
		}
		return i;
	}
	Node* last() {
		Node* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		return p;
	}
	Node* prelast() {
		Node* p = head;
		while (p->next->next != nullptr) {
			p = p->next;
		}
		return p;
	}
	Node* getPtr(int n) {
		if (length() < n || n < 0) {
			return nullptr;
		}
		Node* p = head;
		for (int i = 1; i < n; ++i) {
			p = p->next;
		}
		return p;
	}
	void addFirst(int d)
	{
		Node* tmp;
		tmp = new Node(d, head);
		head = tmp;
	}
	void addAfterFirst(int d) {
		if (length() == 0) {
			addFirst(d);
		}
		else if (length() == 1) {
			Node* t = new Node(d);
			head->next = t;
		}
		else {
			Node* t = new Node(d, head->next);
			head->next = t;
		}

	}
	void addLast(int d) {
		if (length() == 0) {
			addFirst(d);
		}
		else if (length() == 1) {
			addAfterFirst(d);
		}
		else {
			Node* t = new Node(d);
			last()->next = t;
		}
	}
	void delFirst()
	{
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		Node* t = head;
		head = head->next;
		delete t;
	}
	void delLast() {
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		else if (length() == 1) {
			delFirst();
			return;
		}
		Node* t = last();
		Node* pret = prelast();
		pret->next = nullptr;
		delete t;
	}
	void insert(int index = 0, int d = 0) {
		if (index > length() || index < 0) {
			cout << "INVALID INDEX" << endl;
			return;
		}
		if (length() == 0) {
			addFirst(d);
			return;
		}
		if (index == 0) {
			addFirst(d);
			return;
		}
		if (index == length()) {
			addLast(d);
			return;
		}
		Node* pret = getPtr(index);
		Node* t = new Node(d, pret->next);
		pret->next = t;
	}
	void delp(int index) {
		if (length() == 0) {
			cout << "EMPTY" << endl;
			return;
		}
		if (length() == 1) {

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
		Node* pret = getPtr(index);
		Node* t = getPtr(index + 1);
		pret->next = t->next;
		delete t;
	}
	void reverse() {
		if (length() == 0) {
			cout << "EMPTY" << endl;
			return;
		}
		if (length() == 1) {
			return;
		}
		Node* Last = last();
		int l = length();
		for (int i = l; i >= 2; --i) {
			Node* t1 = getPtr(i);
			Node* t2 = getPtr(i - 1);
			t1->next = t2;
			t2->next = nullptr;
		}
		head->next = nullptr;
		head = Last;
	}
	void ptrCheck(int index) {
		Node* t = getPtr(index);
		cout << "data = " << t -> data;
	}
};


int main()
{
	List l;
	l.addAfterFirst(1);
	l.addAfterFirst(3);
	l.addAfterFirst(2);
	l.addLast(5);
	l.print();
	l.delLast();
	l.print();
	l.addLast(4);
	l.insert(1, 666);
	int k = l.length();
	cout << "dlina spiska - " << k << endl;
	l.print();
	l.delp(1);
	l.print();
	List ll;
	l.reverse();
	l.print();
	return EXIT_SUCCESS;
}