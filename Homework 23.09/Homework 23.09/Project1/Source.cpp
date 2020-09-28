#include<iostream>
using namespace std;
void printMenu()
{
    cout << "vibirete deistvie" << endl;
    cout << "" << endl;
    cout << "0 - vihod" << endl;
    cout << "1 - dobavit n sluchainih chisel ot A do B" << endl;
    cout << "2 - razvernut massiv" << endl;
    cout << "3 - pomenyat elementi massiva v parah" << endl;
    cout << "4 - sdvig vpravo na 1" << endl;
    cout << "5 - razvernut dve polovinki massiva" << endl;
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

void dobavEl(int*& arr, int& count, int& capacity)
{
    cout << "vvedite n, a, b" << endl;
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


void perevorot(int* arr, int count) {
    if (count % 2 == 0) {
        for (int i = 0; i < count / 2; ++i) {
            int t = arr[i];
            arr[i] = arr[count - i];
            arr[count - i] = t;
        }
    }
    else {
        for (int i = 0; i <= count / 2; ++i) {
            int t = arr[i];
            arr[i] = arr[count - i];
            arr[count - i] = t;
        }
    }
}


void parper(int* arr, int count) {
    if (count % 2 == 0) {
        for (int i = 0; i <=count-2; i+=2) {
            int t = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = t;
        }
    }
    else {
        for (int i = 0; i <= count-3; i+=2) {
            int t = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = t;
        }
    }
}


void sdvig(int* arr, int count) {
    int t = arr[count - 1];
    for (int i = count - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = t;
}

int main()
{
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
            dobavEl(a, count, cap);
            printArray(a, count);
            cout << endl << endl;
            break;
        case 2:
            count--;
            perevorot(a, count);
            count++;
            printArray(a, count);
            cout << endl << endl;
            break;
        case 3:
            parper(a, count);
            printArray(a, count);
            cout << endl << endl;
            break;
        case 4:
            sdvig(a, count);
            printArray(a, count);
            cout << endl << endl;
            break;
        case 5:
            break;


        }


    }
    return 0;
}