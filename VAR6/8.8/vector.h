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