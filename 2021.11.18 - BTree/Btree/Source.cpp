#include <iostream>
using namespace std;
struct BNode
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {}
};
void f_print(BNode* r, int d = 0) // d - смещение
{
	if (r == nullptr) return;
	f_print(r->right, d + 3);
	for (int i = 0; i < d; i++)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, d + 3);
}
struct BTree
{
	BNode* root;
	BTree(BNode* p) : root(p) {}
	void print()
	{
		f_print(root);
	}
};
BNode* leftKnot(BNode* r) {
	BNode* k1 = r;
	while (k1->left != nullptr) {
		k1 = k1->left;
	}
	return k1;
}
void delLeftKnot(BNode* r) {
	BNode* k1 = r;
	while (k1->left->left != nullptr) {
		k1 = k1->left;
	}
	if (k1->left->right == nullptr) {
		delete k1->left;
		k1->left = nullptr;
		return;
	}
	else {
		BNode* temp = k1->left->right;
		delete k1->left;
		k1->left = temp;
		return;
	}
}
void addLeft(BNode* r, int data) {
	BNode* k1 = r;
	while (k1->left != nullptr) {
		k1 = k1->left;
	}
	BNode* newnode = new BNode(data);
	k1->left = newnode;
	return;
}
BNode* leftLeave(BNode* r) {
	BNode* k = r;
	while (k->left != nullptr && k->right != nullptr) {
		while (k->left != nullptr) {
			k = k->left;
		}
		if (k->right != nullptr) {
			k = k->right;
		}
	}
	return k;
}
void delLeftLeave(BNode* r) {
	BNode* k = r;
	BNode* k1 = k;
	while (k->left != nullptr && k->right != nullptr) {
		while (k->left != nullptr) {
			k1 = k;
			k = k->left;
		}
		if (k->right != nullptr) {
			k1 = k;
			k = k->right;
		}
	}
	if (k1->left = k) {
		delete k;
		k1->left = nullptr;
		return;
	}
	else {
		delete k; 
		k1->right = nullptr;
	}
}
BNode* secondLeftLeave(BNode* r) {
	BNode* k = r;
	BNode* k1 = k;
	BNode* start = r;
	while (k->left != nullptr && k->right != nullptr) {
		while (k->left != nullptr) {
			if (k->right != nullptr) {
				start = k->right;
			}
			k = k->left;
		}
		if (k->right != nullptr) {
			k = k->right;
		}
	}
	return leftLeave(start);
}

int main()
{
	BNode* p1 = new BNode(1),
		* p4 = new BNode(4),
		* p7 = new BNode(7),
		* p13 = new BNode(13),
		* p6 = new BNode(6, p4, p7),
		* p14 = new BNode(14, p13),
		* p10 = new BNode(10, nullptr, p14),
		* p3 = new BNode(3, p1, p6),
		* p8 = new BNode(8, p3, p10);

	BTree t(p8);
	t.print();
	cout << endl << endl;

	cout << leftKnot(p8)->data << endl << endl;

	delLeftKnot(p8);
	t.print();
	cout << endl << endl;

	addLeft(p8, 66); 
	t.print();
	cout << endl << endl;

	cout << leftLeave(p8)->data << endl << endl;

	delLeftLeave(p8);
	t.print();
	cout << endl << endl;

	cout << secondLeftLeave(p8)->data << endl << endl;

	return EXIT_SUCCESS;
}