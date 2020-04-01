#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include "vector.h"

#define SPACING 12

class matrix {

    std::string mName;
    static int sCounter;

    vector < vector<double> > mMatrix;
    int mRows;
    int mCols;

    friend std::ostream& operator<<(std::ostream& out, const matrix& matrixToOut);
    friend std::istream& operator>>(std::istream& in, matrix& matrixToIn);

public:
    matrix();
    matrix(int rows, int cols);
    matrix(const matrix& anotherMatrix);
    ~matrix();

    vector <double>& operator[](int index);

    matrix operator+(double number);
    matrix operator-(double number);
    matrix operator*(double number);
    matrix operator/(double number);
    matrix operator+(const matrix& anotherMatrix);
    matrix operator-(const matrix& anotherMatrix);
    matrix operator*(const matrix& anotherMatrix);

    matrix& operator=(const matrix& anotherMatrix);

    matrix& operator+=(double number);
    matrix& operator-=(double number);
    matrix& operator*=(double number);
    matrix& operator/=(double number);
    matrix& operator+=(const matrix& anotherMatrix);
    matrix& operator-=(const matrix& anotherMatrix);
    matrix& operator*=(const matrix& anotherMatrix);


    bool operator==(const matrix& anotherMatrix);
    bool operator!=(const matrix& anotherMatrix);

    bool isSquared();
    bool isDiagonal();
    bool isZero();
    bool isNull();
    bool isIdentity();
    bool isSymmetrical();
    bool isUpperTriangle();
    bool isLowerTriangle();
    bool isSameSizeWith(const matrix& anotherMatrix);
    bool isCompatibleWith(const matrix& anotherMatrix);

    matrix getTransposed();
    matrix getRaisedIn(int power);
    void fillRandom();
    void fillKeyboard();
    void fillIdentity();
    int getRows();
    int getCols();
    void print();
};