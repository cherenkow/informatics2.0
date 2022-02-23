#include <iostream>
#include <algorithm>
using namespace std;

struct BNode
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) : data(d), left(l), right(r) {}
};

void f_print(BNode* r, int d = 0) {
	if (r == nullptr) return;
	f_print(r->right, d + 3);
	for (int i = 0; i < d; i++)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, d + 3);
}
void f_del(BNode*& p)
{
	if (p == nullptr)
		return;
	f_del(p->left);
	f_del(p->right);
	delete p;
	p = nullptr;
}
void f_scale(BNode* cur) {
	if (cur != nullptr) {
		(cur->data) *= 3;
		f_scale(cur->left);
		f_scale(cur->right);
	}
}
int f_sum(BNode* cur) {
	if (cur == nullptr) {
		return 0;
	}
	return cur->data + f_sum(cur->left) + f_sum(cur->right);
}
int f_count_neg(BNode* cur) {
	if (cur == nullptr) {
		return 0;
	}
	return (cur->data < 0) ? 1 : 0 + f_count_neg(cur->left) + f_count_neg(cur->right);
}
int f_height(BNode* cur) {
	if (cur == nullptr) {
		return 0;
	}
	return 1 + max(f_height(cur->left), f_height(cur->right));
}
void f_reflect(BNode* cur) {
	if (cur != nullptr) {
		swap(cur->left, cur->right);
		f_reflect(cur->left);
		f_reflect(cur->right);
	}
}
int f_mult(BNode* cur) {
	if (cur == nullptr) {
		return 1;
	}
	return ((cur->left != nullptr && cur->right != nullptr) ? cur->data : 1) * f_mult(cur->left) * f_mult(cur->right);
}
int f_eval(BNode* cur) {
	if (cur->left == nullptr && cur->right == nullptr) {
		return cur->data;
	}
	if (cur->data == 1) {
		return f_eval(cur->left) + f_eval(cur->right);
	}
	if (cur->data == 2) {
		return f_eval(cur->left) - f_eval(cur->right);
	}
	if (cur->data == 3) {
		return f_eval(cur->left) * f_eval(cur->right);
	}
	if (cur->data == 4) {
		return f_eval(cur->left) / f_eval(cur->right);
	}
}
template <class T>
BNode* f_find(T d, BNode* cur) {
	if (cur != nullptr) {
		if (d == cur->data) {
			return cur;
		}
		BNode* p = f_find(d, cur->left);
		if (p != nullptr) {
			return p;
		}
		p = f_find(d, cur->right);
		return p;
	}
	return nullptr;
}
int f_min(int minimum, BNode* cur) {
	if (cur != nullptr) {
		if (cur->data < minimum) {
			return min(f_min(cur->data, cur->left), f_min(cur->data, cur->right));
		}
		else {
			return min(f_min(minimum, cur->left), f_min(minimum, cur->right));
		}
	}
	return minimum;
}

void f_del0(BNode*& current)
{
	if (current != nullptr)
	{
		if (current->data == 0)
		{
			f_del(current);
		}
		else
		{
			f_del0(current->left);
			f_del0(current->right);
		}
	}
	return;
}
void f_delLeaves(BNode*& current)
{
	if (current != nullptr)
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			delete current;
			current = nullptr;
		}
		else
		{
			f_delLeaves(current->left);
			f_delLeaves(current->right);
		}
	}
	return;
}
void f_enlarge(int d, BNode*& current)
{
	if (current != nullptr)
	{
		f_enlarge(d, current->left);
		 
		f_enlarge(d, current->right);
		if (current->left == nullptr)
		{
			current->left = new BNode(d);
		}
		if (current->right == nullptr) 
		{
			current->right = new BNode(d);
		}
	}
	return;
}

struct BTree
{
	BNode* root;
	BTree(BNode* p) : root(p) {}
	~BTree()
	{
		f_del(root); // удалить дерево
	}
	void print() {
		cout << "~~~~~~~~~~~~~~~~~~" << endl;
		f_print(root);
		cout << "~~~~~~~~~~~~~~~~~~" << endl;
	}
	void scale() {
		f_scale(root);
	}
	int sum() {
		return f_sum(root);
	}
	int countNeg() {
		return f_count_neg(root);
	}
	int height() {
		return f_height(root);
	}
	void reflect() {
		f_reflect(root);
	}
	int mult() {
		return f_mult(root);
	}
	int eval() {
		return f_eval(root);
	}
	template <class T>
	BNode* find(T d) {
		return f_find(d, root);
	}
	int min() {
		return f_min(INT_MAX, root);
	}
	void del0()
	{
		f_del0(root);
	}
	void delLeaves()
	{
		f_delLeaves(root);
	}
	void enlarge(int d)
	{
		f_enlarge(d, root);
	}
};

int main() {
	BNode* p1 = new BNode(1),
		* p4 = new BNode(4),
		* p7 = new BNode(-7),
		* p13 = new BNode(13),
		* p6 = new BNode(6, p4, p7),
		* p14 = new BNode(-14, p13),
		* p10 = new BNode(0, nullptr, p14),
		* p3 = new BNode(0, p1, p6),
		* p8 = new BNode(8, p3, p10);

	BTree t(p8);
	t.print();

	t.scale();
	t.print();

	cout << "sum: " << t.sum() << endl;

	cout << "num neg: " << t.countNeg() << endl;

	cout << "height: " << t.height() << endl;

	t.reflect();
	t.print();

	cout << "mult: " << t.mult() << endl;



	BNode* q1 = new BNode(43),
		* q2 = new BNode(13),
		* q4 = new BNode(-13),
		* q3 = new BNode(3, q1, q2),
		* q5 = new BNode(2, q3, q4);
	BTree q(q5);
	q.print();
	cout << "eval: " << q.eval() << endl;


	cout << "min: " << t.min() << endl;

	cout << q.find(-13)->data << endl;

	t.print();
	t.delLeaves();
	t.print();

	t.enlarge(10);
	t.print();

	t.del0();
	t.print();


	return 0;
}