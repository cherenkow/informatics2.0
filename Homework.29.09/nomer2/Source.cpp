#include<iostream>
#include<clocale>
using namespace std;
void printMenu()
{
    cout << "выберете действие" << endl;
    cout << "" << endl;
    cout << "0 - выход" << endl;
    cout << "1 -добавить Ќ случайных чисел от ј до Ѕ" << endl;
    cout << "2 - развернуть массив" << endl;
    cout << "3 - помен€ть эдементы массива в парах" << endl;
    cout << "4 - сдвиг вправо на один" << endl;
    cout << "5 -развернуть две половинки массива" << endl;
    cout << endl;
}



void expandArray(int*& arr, int& capacity)
{
    int newCapacity = capacity * 2;

    int* temp = new int[newCapacity];
    for (int i = 0; i < capacity; ++i)
    {
        temp[i] = arr[i];
    }

    capacity = newCapacity;
    delete[] arr;
    arr = temp;
}

void printArray(int* arr, int count)
{
    cout << "{ ";
    for (int i = 0; i < count; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

void addEl(int*& arr, int& count, int& capacity)
{
    cout << "введите n, a, b" << endl;
    int N;
    int A;
    int B;
    cin >> N;
    cin >> A;
    cin >> B;
    int k = count;
    int c = capacity;
    for (int i = k; i < k + N; ++i) {
        if (i < capacity) {
            arr[i] = rand() % (B - A + 1) + A;
            count++;
        }
        else if (i == capacity) {
            expandArray(arr, capacity);
            arr[i] = rand() % (B - A + 1) + A;
            count++;
        }
    }
}


void reverse(int* arr, int k, int count) {

    for (int i = k; i <= count / 2; ++i) {
        int t = arr[i];
        arr[i] = arr[count - i];
        arr[count - i] = t;
    }

}

void reverseN(int* arr, int& count) {
    cout << "введите число раздел€ющее половинки массива" << endl << endl;
    int x;
    cin >> x;
    if ((x >= count - 1) || (x <= 0)) {
        reverse(arr, 0, count - 1);
    }
    else {
        reverse(arr, 0, x - 1);
        reverse(arr, x, count + x - 1);
    }
}

void pairRev(int* arr, int count) {
    if (count % 2 == 0) {
        for (int i = 0; i <= count - 2; i += 2) {
            int t = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = t;
        }
    }
    else {
        for (int i = 0; i <= count - 3; i += 2) {
            int t = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = t;
        }
    }
}


void shiftArray(int* arr, int count) {
    int t = arr[count - 1];
    for (int i = count - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = t;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int cap = 5;
    int count = 0;
    int* a = new int[cap];
    int choice = -1;
    while (choice != 0)
    {
        printMenu();
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            addEl(a, count, cap);
            printArray(a, count);
            cout << endl << endl;
            break;
        case 2:
            count--;
            reverse(a, 0, count);
            count++;
            printArray(a, count);
            cout << endl << endl;
            break;
        case 3:
            pairRev(a, count);
            printArray(a, count);
            cout << endl << endl;
            break;
        case 4:
            shiftArray(a, count);
            printArray(a, count);
            cout << endl << endl;
            break;
        case 5:
            reverseN(a, count);
            printArray(a, count);
            cout << endl << endl;
            break;


        }


    }
    return 0;
}