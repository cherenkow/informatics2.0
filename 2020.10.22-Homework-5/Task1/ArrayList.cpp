#include"ArrayList.h"
#include <iostream>

ArrayList::~ArrayList()
{
	delete[] data;
}

bool ArrayList::add(int el) {
	if (count == capacity) {
		expand();
	}
	data[count] = el;
	count++;
	return true;
}

void ArrayList::expand()
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

int  ArrayList::numLength(int number) {
	int k = 1;
	if (number < 0) {
		number *= -1;
	}
	while (number > 9) {
		number /= 10;
		k++;
	}
	return k;
}

void  ArrayList::addSymbolToStr(int& index, char symbol) {
	str[index] = symbol;
	++index;
}

void  ArrayList::addNumberToStr(int& index, int number) {
	int length = numLength(number);
	if (number < 0) {
		addSymbolToStr(index, '-');
		number *= (-1);
	}

	for (int i = 0; i < length; ++i) {
		str[index + length - 1 - i] = '0' + number % 10;
		number /= 10;
	}
	index += length;
}

bool ArrayList::add(int index, int el) {
	if (count == capacity) {
		expand();
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

bool ArrayList::set(int index, int element) {
	if (index < 0 || index >= count || count == 0) {
		return false;
	}
	data[index] = element;
	return true;
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

char* ArrayList::toString() {
	if (str != nullptr) {
		delete[] str;
		str = nullptr;
	}

	int index = 0;
	int length = 0;
	for (int i = 0; i < count; ++i) {
		if (data[i] < 0) {
			length += 1;
		}
		length += numLength(data[i]);
	}
	//третье слагаемое - запятые с пробелами, четвертое - скобки, слэш,\0 и пробел 
	length += numLength(capacity) + numLength(count) + 2 * (count - 1) + 7; 
	str = new char[length];
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');

	for (int i = 0; i < count - 1; ++i) {
		addNumberToStr(index, data[i]);
		addSymbolToStr(index, ',');
		addSymbolToStr(index, ' ');
	}
	addNumberToStr(index, data[count - 1]);
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');
	return str;
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

bool ArrayList::swap(int index1, int index2) {
	if (index1 > count || index1 < 0 || index2 > count || index2 < 0) {
		return false;
	}
	int t = data[index1];
	data[index1] = data[index2];
	data[index2] = t;
	return true;
}

int ArrayList::length() {
	return count;
}

bool ArrayList::addP() {
	if (count + 10 > capacity) {
		expand();
	}
	for (int i = 0; i < 10; ++i) {
		int a = rand() % (99 - 10 + 1) + 10;
		add(a);
	}
	return true;
}

bool ArrayList::addN() {
	if (count + 10 > capacity) {
		expand();
	}
	for (int i = 0; i < 10; ++i) {
		int a = rand() % (99 - 10 + 1) + 10;
		add(a*(-1));
	}
	return true;
}

bool ArrayList::change() {
	if (count < 2) {
		return false;
	}
	int k = data[0];
	int ik = 0;
	int x = data[0];
	int ix = 0;
	for (int i = 1; i < count; ++i) {
		if (k > data[i]) {
			k = data[i];
			ik = i;
		}
	}
	for (int i = 1; i < count; ++i) {
		if (x <= data[i]) {
			x = data[i];
			ix = i;
		}
	}
	return swap(ix, ik);
}

bool ArrayList::mix() {
	if (count <1) {
		return false;
	}
	for (int i = 0; i < count; ++i) {
		int a = 0;
		int b = 0;
		while (a == b) {
			a = rand() % (count);
			b = rand() % (count);
		}
		swap(a, b);
	}
	return true;
}

bool ArrayList::positive() {
	if (count == 0) {
		return false;
	}
	for (int i = 0; i < count; ++i) {
		if (data[i] < 0) {
			data[i] = 0;
		}
	}
	return true;
}
