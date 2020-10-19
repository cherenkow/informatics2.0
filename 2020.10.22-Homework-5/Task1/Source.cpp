#include<iostream>
#include<clocale>
#include"ArrayList.h";

void printMenu()
{
	printf("выберете действие:\n");
	printf("\n");
	printf("0 - выход\n");
	printf("1 - добавить элемент в конец\n");
	printf("2 - добавить новый элемент в определенное место\n");
	printf("3 - добавить список элементов\n");
	printf("4 - добавить список элементов в определенное место\n");
	printf("5 - удалить все элементы списка\n");
	printf("6 - проверить наличие элемента в списке\n");
	printf("7 - получить элемент по индексу\n");
	printf("8 - найти инлкс элмента\n");
	printf("9 - проверить список на наличие элементов\n");
	printf("10 - вывести список на экран \n");
	printf("11 - удалить элемент\n");
	printf("12 - поменять элементы местами\n");
	printf("13 - поменять значение элемента\n");
	printf("14 - добавить 10 двузначных положительных чисел\n");
	printf("15 - добавить 10 двузначных отрицательных чисел\n");
	printf("16 - поменять местами первый минимальный и последний максимальный элементы местами\n");
	printf("17 - заменить отрицательные числа нулями\n");
	printf("18 - перемешать массив\n");

	printf("\n");
}



void switchCase(int choice, ArrayList& a) {
	printf("\n");
	switch (choice)
	{
	case 1:
		printf("введите новый элемент:\n");
		int el1;
		std::cin >> el1;
		a.add(el1);
		std::cout << a.toString() << std::endl << std::endl;

		break;
	case 2:
		printf("введите новый элемент:\n");
		int el2;
		std::cin >> el2;
		printf("введите индекс:\n");
		int ix;
		std::cin >> ix;
		a.add(ix, el2);
		std::cout << a.toString() << std::endl << std::endl;
		break;
	case 3: {
		printf("сколько элементов в добавляемом списке? \n");
		int k;
		std::cin >> k;
		ArrayList list(k);
		printf("введите элементы списка: \n");
		for (int i = 0; i < k; ++i) {
			int el3;
			std::cin >> el3;
			list.add(el3);
		}
		a.addAll(list);
		std::cout << a.toString() << std::endl << std::endl;
	}
		  break;
	case 4:
	{
		printf("сколько элементов в добавляемом списке? \n");
		int kk;
		std::cin >> kk;
		ArrayList list1(kk);
		printf("введите элементы списка: \n");
		for (int i = 0; i < kk; ++i) {
			int el4;
			std::cin >> el4;
			list1.add(el4);
		}
		printf("введите индекс:");
		int ii;
		std::cin >> ii;
		a.addAll(ii, list1);
		std::cout << a.toString() << std::endl << std::endl;
	}
	break;
	case 5:
		printf("елементы удалены\n");
		a.clear();
		std::cout << a.toString() << std::endl << std::endl;
		break;
	case 6:
		printf("введите искомый элемент: \n");
		int el5;
		std::cin >> el5;
		printf("%d\n", a.contains(el5));
		break;
	case 7:
		printf("введите индекс:\n");
		int index;
		std::cin >> index;
		if (a.get(index) != false) {
			printf("элемент с индексом %d в списке: %d\n", index, a.get(index));
		}
		else {
			printf("ошибка; попробуйте еще раз\n");
		}
		break;
	case 8:
		printf("введите искомый элемент: \n");
		int el6;
		std::cin >> el6;
		if (a.indexOf(el6) > -1) {
			printf("элемент %d в списке имеет инлекс: %d\n", el6, a.indexOf(el6));
		}
		else {
			printf("ошибка; попробуйте еще раз\n");
		}
		break;
	case 9:
		if (a.isEmpty() == true) {
			printf("list is NOT EMPTY\n");
		}
		else {
			printf("list is EMPTY\n");
		}
		break;
	case 10:
		if (a.isEmpty() == false) {
			printf("list is EMPTY\n");
		}
		else {
			std::cout << a.toString() << std::endl << std::endl;
		}
		break;
	case 11:
		printf("введите индекс удаляемого элмента:\n");
		int d;
		std::cin >> d;
		if (a.remove(d) == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
		break;
	case 12:
		printf("введите индексы элментов:\n");
		int in1;
		std::cin >> in1;
		int in2;
		std::cin >> in2;
		if (a.swap(in1, in2) == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
		break;
	case 13:
		printf("введите индекс элемента\n");
		int ind;
		std::cin >> ind;
		printf("введите новое значение элмента\n");
		int nov;
		std::cin >> nov;
		if (a.set(ind, nov) == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
		break;
	case 14:
		a.addP();
		std::cout << a.toString() << std::endl << std::endl;
		break;
	case 15:
		a.addN();
		std::cout << a.toString() << std::endl << std::endl;
		break;
	case 16:
		if (a.change() == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
		break;
	case 17:
		if (a.positive() == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
		break;
	case 18:

		if (a.mix() == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList a;

	int choice = -1;
	while (choice != 0)
	{
		printMenu();
		std::cin >> choice;
		switchCase(choice, a);
	}

	return 0;
}