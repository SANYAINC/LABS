#pragma once

#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

class squareMatrix2D {
    double **mMatrix;
    int mSize;
public:
    squareMatrix2D(int n);

    bool add(squareMatrix2D &mx);
    bool subtract(squareMatrix2D &mx);
    bool multiply(squareMatrix2D &mx);
    bool raise(int n);

    void fillAsIdentity();
    void fillRandom();
    void fillKeyboard();

    void show();
};

class squareMatrix1D {
    double *mMatrix;
    int mSize;
public:
    squareMatrix1D(int n);

    bool add(squareMatrix1D &mx);
    bool subtract(squareMatrix1D &mx);
    bool multiply(squareMatrix1D &mx);
    bool raise(int n);

    void fillAsIdentity();
    void fillRandom();
    void fillKeyboard();

    void show();
};