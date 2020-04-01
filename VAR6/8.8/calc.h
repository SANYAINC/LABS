#pragma once
#include "matrix.h"
#include <iostream>

#define MAX_SIZE 1000

using namespace std;

matrix matrixCreate();
int getOption();
template <class T> void input(T& value, const char* message, T lBorder, T rBorder) {
    cin >> value;
    while (cin.fail() or value < lBorder or value > rBorder) {
        cin.clear();
        cin.ignore((2 << 15) - 1, '\n');
        cout << message;
        cin >> value;
    }
    cin.ignore((2 << 15) - 1, '\n');
}
void save(matrix& result, matrix& main);