#include<iostream>
#include<clocale>
using namespace std;
void printMenu()
{
    cout << "выберете действие" << endl;
    cout << "" << endl;
    cout << "0 - выход" << endl;
    cout << "1 - ввести Н чисел с клавиатуры " << endl;
    cout << "2 - добавить Н случайных чисел от А до Б" << endl;
    cout << "3 - вывести массив " << endl;
    cout << "4 - поиск индекса элемента " << endl;
    cout << "5 - добавление массива к массиву" << endl;
    cout << "6 - объединение массивов" << endl;
    cout << "7 - вставка элемента в массив " << endl;
    cout << "8 - удаление несколькх подряд идущих элементов" << endl;
    cout << "9 - поиск подпоследовательности" << endl;
    cout << endl;
}



void expandArray(int*& arr)
{
    int newCapacity = *(arr - 1) * 2;
    int* temp = new int[newCapacity + 2];
    temp += 2;
    for (int i = -2; i < *(arr - 1); i += 1)
    {
        temp[i] = arr[i];
    }
    *(temp - 1) *= 2;
    arr -= 2;
    delete[] arr;
    arr = temp;
}

void unify(int*& arr, int*& crr) {
    int newCapacity = *(arr - 2) + *(crr - 2);
    int* temp = new int[newCapacity + 2];
    temp += 2;
    if (*(arr - 2) < *(crr - 2)) {
        for (int i = 0; i < *(arr - 2); i += 1) {
            *(temp + i * 2) = *(arr + i);
            *(temp + i * 2 + 1) = *(crr + i);
        }
        int k = *(arr - 2);
        for (int i = *(arr - 2) * 2; i < newCapacity; ++i) {
            *(temp + i) = *(crr + k);
            k += 1;
        }
    }
    else {
        for (int i = 0; i < *(crr - 2); i += 1) {
            *(temp + i * 2) = *(arr + i);
            *(temp + i * 2 + 1) = *(crr + i);
        }
        int k = *(crr - 2);
        for (int i = *(crr - 2) * 2; i < newCapacity; ++i) {
            *(temp + i) = *(arr + k);
            k += 1;
        }
    }
    *(temp - 2) = newCapacity;
    *(temp - 1) = newCapacity;
    arr -= 2;
    delete[] arr;
    arr = temp;

}


void printArray(int* arr)
{
    cout << "{ ";
    for (int i = 0; i < *(arr - 2); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

void addEl(int*& arr, int N, int A, int B)
{
    int k = *(arr - 2);
    int c = *(arr - 1);
    for (int i = k; i < k + N; ++i) {
        if (i == *(arr - 1)) {
            expandArray(arr);
        }
        *(arr + i) = rand() % (B - A + 1) + A;
        *(arr - 2) += 1;
    }
}

void newEl(int*& arr, int x) {
    if (*(arr - 2) == *(arr - 1)) {
        expandArray(arr);
    }
    *(arr + *(arr - 2)) = x;
    *(arr - 2) += 1;

}

void keyboard(int*& arr, int n) {
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        newEl(arr, x);
    }
}
int elementSearch(int* arr, int x) {
    for (int i = 0; i < *(arr - 2); ++i)
        if (*(arr + i) == x) {
            return i;
            break;
        }
}

void insert(int*& arr, int n, int x) {
    if (*(arr - 2) == *(arr - 1)) {
        expandArray(arr);
    }
    for (int i = *(arr - 2) - 1; i > n; --i) {
        *(arr + i) = *(arr + i - 1);
    }
    arr[n] = x;
}

void addArray(int*& arr, int* brr) {
    if (*(arr - 2) + *(brr - 2) >= *(brr - 1)) {
        expandArray(arr);
    }
    for (int i = 0; i < *(brr - 1); ++i) {
        *(arr + *(arr - 2)) = *(brr + i);
        *(arr - 2) += 1;
    }
}

int deleteGroup(int*& arr, int si, int count) {
    if ((si + count <= *(arr - 2)) && si > -1 && count > 0) {
        int* temp = new int[*(arr - 1) + 2];
        temp += 2;
        int k = 0;
        for (int i = 0; i < si; i += 1)
        {
            temp[i] = arr[i];
            k++;
        }
        for (int i = si + count; i < *(arr - 2); i += 1)
        {
            temp[k] = arr[i];
            k++;
        }
        *(temp - 1) = *(arr - 1);
        *(temp - 2) = *(arr - 2) - count;
        arr -= 2;
        delete[] arr;
        arr = temp;
        return 0;
    }
    else {
        return 1;
    }

}

int seqSearch(int* arr, int* drr) {
    if (*(arr - 2) < *(drr - 2)) {
        return -1;
    }
    else {
        int k = 0;
        int t =-1;
        for (int i = 0; i <= *(arr - 2) - *(drr - 2); i++) {
            if (*(arr + i) == *(drr + k)) {
                t = i;
                break;
            }
        }
        if (t != -1) {
            for (int i = t; i < t + *(drr - 2); i++) {
                if (*(arr + i) == *(drr + k)) {
                    k += 1;
                }
            }
            if (k == *(drr - 2)) {
                return t;
            }
            else {
                return -1;
            }
        }
        else { return -1; }

    }
}
void switchCase(int choice, int*& a) {
    cout << endl;
    switch (choice)
    {
    case 1:
        cout << "сколько чисел ввести?" << endl;
        int n;
        cin >> n;
        cout << "введите числа" << endl << endl;
        keyboard(a, n);
        printArray(a);
        cout << endl << endl;
        break;
    case 2:
        cout << "введите n, a, b" << endl;
        int N;
        int A;
        int B;
        cin >> N;
        cin >> A;
        cin >> B;
        addEl(a, N, A, B);
        printArray(a);
        cout << endl << endl;
        break;

    case 3:
        printArray(a);
        cout << endl << endl;
        break;
    case 4:
        cout << "какой элемент найти?" << endl;
        int x;
        cin >> x;
        cout << "индекс искомого элеемнта:" << elementSearch(a, x);
        cout << endl << endl;
        break;
    case 5: {
        cout << "сколько элементов добавить?" << endl;
        int l;
        cin >> l;
        int* brr = new int[l];
        brr += 2;
        *(brr - 2) = 0;
        *(brr - 1) = l;
        cout << "введите новые элементы" << endl;
        keyboard(brr, l);
        addArray(a, brr);
        printArray(a);
        cout << endl << endl;
    }
          break;
    case 6: {
        cout << "сколько элементов во втором массиве" << endl;
        int k;
        cin >> k;
        int* crr = new int[k];
        crr += 2;
        *(crr - 2) = 0;
        *(crr - 1) = k;
        cout << "введите элементы массива" << endl;
        keyboard(crr, k);
        unify(a, crr);
        printArray(a);
        cout << endl << endl;
    }
          break;
    case 7:
        cout << "введите индекс" << endl;
        int nn;
        cin >> nn;
        cout << "какой элемент на это место?" << endl;
        int xx;
        cin >> xx;
        insert(a, nn, xx);
        printArray(a);
        cout << endl << endl;
        break;
    case 8:
        cout << "введите индекс первого удаляемого элемента" << endl;
        int si;
        cin >> si;
        cout << "сколько элементов удалить?" << endl;
        int count;
        cin >> count;
        deleteGroup(a, si, count);
        printArray(a);
        cout << endl << endl;
        break;
    case 9:
        cout << "сколько элементов в искомой последовательности?" << endl;
        int m;
        cin >> m;
        int* drr = new int[m];
        drr += 2;
        *(drr - 2) = 0;
        *(drr - 1) = m;
        cout << "введите элементы последовательности" << endl;
        keyboard(drr, m);
        cout << seqSearch(a, drr);
        cout << endl << endl;
        break;


    }


}

int main()
{
    setlocale(LC_ALL, "Russian");

    int* a = new int[5 + 2];
    a += 2;
    *(a - 2) = 0;
    *(a - 1) = 5;
    int choice = -1;
    while (choice != 0)
    {
        printMenu();
        cin >> choice;
        switchCase(choice, a);
    }
    return 0;
}