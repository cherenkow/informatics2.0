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
	printf("6 - вывести список на экран \n");
	printf("7 - удалить элемент\n");
	printf("8 - добавить 10 двузначных положительных чисел\n");
	printf("9 - добавить 10 двузначных отрицательных чисел\n");
	printf("10 - перемешать массив\n");
	printf("домашнее задание\n");
	printf("11 - проверить массив на симметричность\n");
	printf("12 - циклический сдвиг на n элементов\n");
	printf("13 - проверить возможность симметричности\n");


	printf("\n");
}



void switchCase(int choice, ArrayList& a) {
	printf("\n");
	switch (choice)
	{
	case 1: {
		printf("введите новый элемент:\n");
		int el1;
		std::cin >> el1;
		a.add(el1);
		std::cout << a.toString() << std::endl << std::endl;
	}
		  break;
	case 2: {
		printf("введите новый элемент:\n");
		int el2;
		std::cin >> el2;
		printf("введите индекс:\n");
		int ix;
		std::cin >> ix;
		a.add(ix, el2);
		std::cout << a.toString() << std::endl << std::endl;
	}
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
	case 4: {
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
	case 5: {
		printf("элементы удалены\n");
		a.clear();
		std::cout << a.toString() << std::endl << std::endl;
	}
		  break;

	case 6: {
		if (a.isEmpty() == true) {
			printf("EMPTY\n");
		}
		else {
			std::cout << a.toString() << std::endl << std::endl;
		}
	}
		  break;
	case 7: {
		printf("введите индекс удаляемого элмента:\n");
		int d;
		std::cin >> d;
		if (a.remove(d) == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
	}
		  break;
	case 8: {
		a.addRandomPositive();
		std::cout << a.toString() << std::endl << std::endl;
	}
		  break;
	case 9: {
		a.addRandomNegative();
		std::cout << a.toString() << std::endl << std::endl;
	}
		  break;
	case 10: {
		if (a.mix() == true) {
			std::cout << a.toString() << std::endl << std::endl;
		}
		else {
			printf("что-то пошло не так\n");
		}
	}
		   break;
	case 11: {
		int check = 0;
		for (int i = 0; i <= (a.length() - 1) / 2; i++) {
			if (a.get(i) == a.get(a.length() - i - 1)) {
				check++;
			}
		}
		if (check == a.length() % 2 + a.length() / 2) {
			printf("массив симметричен\n");
		}
		else {
			printf("массив HE симметричен\n");
		}
	}
		   break;
	case 12: {
		printf("на сколько сдвинуть массив?\n");
		int ns;
		std::cin >> ns;
		if (ns >= 0) {
			for (int i = 0; i < ns; ++i) {
				int temp = a.get(a.length() - 1);
				for (int i = a.length() - 1; i > 0; --i) {
					a.set(i, a.get(i - 1));
				}
				a.set(0, temp);
			}
		}
		else {
			for (int i = 0; i < ns * (-1); ++i) {
				int temp = a.get(0);
				for (int i = 0; i < a.length() - 1; ++i) {
					a.set(i, a.get(i + 1));
				}
				a.set(a.length() - 1, temp);
			}
		}
		std::cout << a.toString() << std::endl << std::endl;
	}
		   break;
	case 13: {
		int s = -1;
		for (int i = 0; i <= (a.length() - 1) / 2; i++) {
			if (a.get(i) != a.get(a.length() - i - 1)) {
				s++;
				if (a.get(i) == a.get(a.length() - i - 2) || a.get(i + 1) == a.get(a.length() - i - 1)) {
					s++;
				}
			}
		}
		if (s == 1) {
			printf("массив может стать симметричным за одно удаление\n");
		}
		else {
			printf("массив HE может стать симметричным за одно удаление\n");
		}
		break;
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
