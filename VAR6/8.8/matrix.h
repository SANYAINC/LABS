#pragma once

#include <iostream>
#include "vector.h"

using namespace std;

class matrix {

    string name;

    vector < vector<double> > mMatrix;
    int rows;
    int cols;

    static int counter;


    friend std::ostream& operator<<(std::ostream& out, matrix mx);
    friend std::istream& operator>>(std::istream& in, matrix mx);

public:
    matrix();
    matrix(int row, int col);
    matrix(const matrix& anotherMatrix);
    ~matrix();

    vector <double> operator[](int index);

    matrix operator+(double number);
    matrix operator-(double number);
    matrix operator*(double number);
    matrix operator/(double number);

    matrix operator+(const matrix& anotherMatrix);
    matrix operator-(const matrix& anotherMatrix);
    matrix operator*(const matrix& anotherMatrix);

    matrix operator+=(const matrix& anotherMatrix);
    matrix operator-=(const matrix& anotherMatrix);
    matrix operator*=(const matrix& anotherMatrix);

    bool operator==(const matrix& anotherMatrix);
    bool operator>(const matrix& anotherMatrix);
    bool operator<(const matrix& anotherMatrix);
    bool operator>=(const matrix& anotherMatrix);
    bool operator<=(const matrix& anotherMatrix);

    bool isSquared();
    bool isDiagonal();
    bool isZero();
    bool isIdentity();
    bool isSymmetrical();
    bool isUpperTriangle();
    bool isLowerTriangle();

    matrix transpose();
    matrix power(int power);
    void print();
    void changeName(const char* newName);
    void changeName(const string& newName);

};

int matrix::counter = 1;