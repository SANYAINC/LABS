#include <iostream>
#include <ctime>

using namespace std;

template <class T>
T* createArray(int size) {
    T *array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(0);
    }
    return array;
}

template <class T>
void deleteArray(T *array) {
    delete [] array;
    cout << "\nMEMORY FREED\n";
}

template <class T>
void showArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

template <class T>
void fillArrRand(T *array, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(rand()%30+30);
    }
}

template <class T>
void fillArrayKeyboard(T *array, int size) {
    T buff;
    cout << "Please, enter " << size << " values: ";
    for (int i = 0; i < size; ++i) {
        cin >> buff;
        array[i] = buff;
    }
    cout << endl;
}
