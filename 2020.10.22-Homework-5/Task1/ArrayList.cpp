#include"ArrayList.h"
#include <iostream>

ArrayList::~ArrayList()
{
	delete[] data;
	delete[] str;
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

int  ArrayList::digitCount(int number) {
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
	int length = digitCount(number);
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
	for (int i = 0; i < list.capacity; ++i) {
		add(index, list.data[i]);
		index++;
	}
	return true;
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
	return(count == 0);
}

char* ArrayList::toString() {
	if (isEmpty() == false) {
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
			length += digitCount(data[i]);
		}
		length += digitCount(capacity) + digitCount(count) + 2 * (count - 1) + 7;
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
	}
	else {
		if (str != nullptr) {
			delete[] str;
			str = nullptr;
		}
		int index = 0;
		str = new char[6];
		addSymbolToStr(index, 'E');
		addSymbolToStr(index, 'M');
		addSymbolToStr(index, 'P');
		addSymbolToStr(index, 'T');
		addSymbolToStr(index, 'Y');
		addSymbolToStr(index, '\0');
	}
	return str;

}

bool ArrayList::remove(int index) {
	if (index < 0 || index > count - 1) {
		return false;
	}
	for (int i = index; i < count - 1; ++i) {
		data[i] = data[i + 1];
	}
	count--;
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

bool ArrayList::addRandomPositive(int max, int min) {
	if (count + 10 > capacity) {
		expand();
	}
	for (int i = 0; i < 10; ++i) {
		int a = rand() % (max - min + 1) + min;
		add(a);
	}
	return true;
}

bool ArrayList::addRandomNegative(int max, int min) {
	if (count + 10 > capacity) {
		expand();
	}
	for (int i = 0; i < 10; ++i) {
		int a = rand() % (max - min + 1) + min;
		add(a * (-1));
	}
	return true;
}

bool ArrayList::mix() {
	if (count < 1) {
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


