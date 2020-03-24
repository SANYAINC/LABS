#pragma once
#include <iostream>

template <class T>
class vector {
    T* mVector;
    int mSize;

    bool validateIndex(int index) const;

    friend std::ostream& operator<<(std::ostream& out, const vector& vectorToOut);

public:
    vector();
    vector(int size, T filler);
    vector(const vector& anotherVector);
    ~vector();

    T& operator[](int index) const;
    vector& operator=(const vector& anotherVector);

    vector& pushBack(T data);
    vector& pushAt(int index, T data);
    vector& deleteAt(int index);
    vector& resize(int newSize, T filler);
    void print() const;
    int find(T data) const;
};

template <class T>
vector <T>::vector() {
    mSize = 0;
    mVector = nullptr;
}

template <class T>
vector <T>::vector(int size, T filler) {
    mSize = size;
    mVector = new T[mSize];
    for (int i = 0; i < mSize; ++i) {
        mVector[i] = filler;
    }
}

template <class T>
vector <T>::vector(const vector& anotherVector) {
    mSize = anotherVector.mSize;
    mVector = new T[mSize];
    for (int i = 0; i < mSize; ++i) {
        mVector[i] = anotherVector.mVector[i];
    }
}

template <class T>
vector <T>::~vector() {
    delete [] mVector;
}
