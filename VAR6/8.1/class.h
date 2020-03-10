#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class vector {
    int *mVector;
    int mSize;
public:
    vector();
    vector(int size, int filler = 0);
    vector(const vector &secondVector);

    int& operator [] (int index) const;
    vector& operator = (const vector &secondVector);

    int getSize() const;
    void resize(int newSize, int filler = 0);
    void show() const;
    void fillRandom(int range = 100, int shift = 0) const;
    void pushBack(int element);
    void removeAt(int index);
    int find(int element) const;
    void insert(int element, int index);

    ~vector();
};

ostream &operator << (ostream &output, vector &v);
istream &operator >> (istream &input, vector &v);