#include"ArrayList.h"

ArrayList::ArrayList()
{
	capacity = 10;
	count = 0;
	data = new int[10];
}

ArrayList::ArrayList(int cap)
{
	capacity = cap;
	count = 0;
	data = new int[cap];
}

ArrayList::~ArrayList()
{
	delete[] data;
}
bool ArrayList::add(int el) {
	if (count == capacity) {
		expand(data, capacity);
	}
	data[count] = el;
	count++;
	return true;
}

bool ArrayList::add(int index, int el) {
	if (count == capacity) {
		expand(data, capacity);
	}
	if (index > count || index < 0) {
		return false;
	}
	for (int i = count; i > index; --i) {
		data[i] = data[i - 1];
	}
	data[index] = el;
	count++;
	return true;
}

bool ArrayList::addAll(ArrayList& list) {
	for (int i = 0; i < list.count; i++) {
		add(list.data[i]);
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list) {
	if (index<0 || index>count) {
		return false;
	}
	else {
		if (index == count) {
			addAll(list);
		}
		else {
			for (int i = 0; i < list.capacity; ++i) {
				add(index, list.data[i]);
				index++;
			}
		}
		return true;
	}
}

void ArrayList::clear() {
	int* temp = new int[capacity];
	delete[] data;
	count = 0;
	data = temp;
}

bool ArrayList::contains(int el) {
	for (int i = 0; i < count; ++i) {
		if (el == data[i]) {
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index) {
	if (index < 0 || index > count) {
		return false;
	}
	return data[index];
}

int ArrayList::indexOf(int el) {
	for (int i = 0; i < count; ++i) {
		if (el == data[i]) {
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty() {
	if (count != 0) {
		return true;
	}
	return false;
}

void ArrayList::print()
{
	printf("[%d/%d]{", count, capacity);
	if (count == 0)
	{
		printf("EMPTY");
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
		}
	}
	printf("}\n");
}

bool ArrayList::remove(int index) {
	if (index < 0 || index > count || count == 0) {
		return false;
	}
	int* temp = new int[count - 1];
	for (int i = 0; i < index; ++i) {
		temp[i] = data[i];
	}
	for (int i = index; i < count - 1; ++i) {
		temp[i] = data[i + 1];
	}
	count--;
	delete[] data;
	data = temp;
	return true;

}

void ArrayList::expand(int*& data, int& capacity)
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	capacity *= 2;
	delete[] data;
	data = newData;
}

bool ArrayList::swap(int i1, int i2) {
	if (i1 > count || i1 < 0 || i2 > count || i2 < 0) {
		return false;
	}
	int t = data[i1];
	data[i1] = data[i2];
	data[i2] = t;
	return true;
}


