#pragma once
#pragma once
#include<iostream>

struct ArrayList
{
private:
	int count;
	int capacity;
	int* data;
	char* str;

public:
	ArrayList(int capacity = 10) :count(0), capacity(capacity), data(new int[capacity]), str(nullptr) {}
	ArrayList(const ArrayList& list)
	{
		count = list.count;
		capacity = list.capacity;
		data = new int[capacity];
		str = nullptr;
		for (int i = 0; i < count; data[i] = list.data[i], ++i);
	}
	~ArrayList();

private:
	void expand();
	int digitCount(int number);
	void addSymbolToStr(int& index, char symbol);
	void addNumberToStr(int& index, int number);

public:
	bool add(int element);

	bool add(int index, int element);

	bool addAll(ArrayList& list);

	bool addAll(int index, ArrayList& list);

	void clear();

	bool contains(int element);

	int get(int index);

	bool set(int index, int element);

	int indexOf(int element);

	bool isEmpty();

	char* toString();

	bool remove(int index);

	bool swap(int index1, int index2);

	int length();

	bool addRandomPositive(int max = 99, int min = 10);

	bool addRandomNegative(int max = 99, int min = 10);

	bool mix();
};