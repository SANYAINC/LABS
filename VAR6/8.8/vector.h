#pragma once
#include <iostream>

template <class T>
class vector {
    T* mVector;
    int mSize;

    void validateIndex(int index) const;

    template <class V>
    friend std::ostream& operator<<(std::ostream& out, const vector<V>& vectorToOut);

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

template <class T>
void vector <T>::validateIndex(const int index) const {
    if (index < 0 or index >= mSize) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE (0 - " << mSize - 1 << ")" << std::endl;
        exit(404);
    }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vectorToOut) {
    if (vectorToOut.mSize == 0) {
        out << "[ ]";
    } else {
        out << "[";
        for (int i = 0; i < vectorToOut.mSize; ++i) {
            out << vectorToOut.mVector[i];
            if (i != vectorToOut.mSize -1) {
                out << ", ";
            }
        }
        out << "]";
    }
    return out;
}

template <class T>
T& vector <T>::operator[](const int index) const {
    validateIndex(index);
    return mVector[index];
}

template <class T>
vector<T>& vector <T>::operator=(const vector& anotherVector) {
    if (&anotherVector == this) {
        return *this;
    }
    mSize = anotherVector.mSize;
    delete [] mVector;
    mVector = new T[mSize];
    for (int i = 0; i < mSize; ++i) {
        mVector[i] = anotherVector.mVector[i];
    }
    return *this;
}
