#include<iostream>
#include<clocale>
#include"ArrayList.h";

int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList list1, list2;
	list1 += 4; list1 += 1; list1 += 2; list1 += 3; list1 += 4; list1 += 6;
	list2 += 19; list2 += 18; list2 += 15; list2 += 14; list2 += 13; list2 += 12;
	ArrayList list3;
	std::cout << "list1 = " << list1 << std::endl;
	list1 -= 2;
	std::cout << "list1 = " << list1 << std::endl;
	std::cout << "list2 = " << list2 << std::endl;
	std::cout << "list3 = " << list3 << std::endl;
	std::cout << std::endl;
	std::cout << "list3 = list1 + 5 " << std::endl;
	list3 = list1 + 5;
	std::cout << "list1 = " << list1 << std::endl;
	std::cout << "list3 = " << list3 << std::endl;
	std::cout << std::endl;
	std::cout << "list3 = 34 + list1 " << std::endl;
	list3 = 34 + list1;
	std::cout << "list1 = " << list1 << std::endl;
	std::cout << "list3 = " << list3 << std::endl;
	std::cout << std::endl;
	std::cout << "list3 = list1 + list2 ";
	std::cout << std::endl;
	list3 = list1 + list2;
	std::cout << "list1 = " << list1 << std::endl;
	std::cout << "list2 = " << list2 << std::endl;
	std::cout << "list3 = " << list3 << std::endl;
	std::cout << std::endl;
	std::cout << "list3 = 18 - list2" << std::endl;
	std::cout << std::endl;
	list3 = 18 - list2;
	std::cout << "list2 = " << list2 << std::endl;
	std::cout << "list3 = " << list3 << std::endl;
	std::cout << std::endl;
	std::cout << "list3 =list2 - 13";
	std::cout << std::endl;
	list3 =list2 - 13;
	std::cout << "list2 = " << list2 << std::endl;
	std::cout << "list3 = " << list3 << std::endl;
	return 0;
}