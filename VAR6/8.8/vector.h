#pragma once
#include <iostream>

template <class T>
class vector {
    T* mVector;
    int mSize;

    void raiseException(int type, int value) const;

    template <class V>
    friend std::ostream& operator<<(std::ostream& out, const vector<V>& vectorToOut);

public:
    vector();
    vector(int size, T filler);
    vector(const vector& anotherVector);
    ~vector();

    T& operator[](int index) const;
    vector& operator=(const vector& anotherVector);

    vector& resize(int newSize);
    vector& pushBack(T data);
    vector& pushAt(int pos, T data);
    vector& deleteAt(int pos);
    vector& clear(int index);
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
void vector <T>::raiseException(const int type, const int value) const {
    switch (type) {
        case 900: {
            std::cerr << "INDEX " << value << " IS OUT OF RANGE (0 - " << mSize - 1 << ")" << std::endl;
            exit(type);
        }
        case 901: {
            std::cerr << "CAN'T RESIZE TO " << value << std::endl;
            exit(type);
        }


        default: {
            return;
        }
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
    if (index < 0 or index >= mSize) {
        raiseException(900, index);
    }
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

template <class T>
vector<T>& vector <T>::resize(const int newSize) {
    if (newSize < 0) {
        raiseException(901, newSize);
    }
    if (newSize == 0) {
        delete mVector;
        mVector = nullptr;
        mSize = 0;
        return *this;
    }
    if (newSize == mSize) {
        return *this;
    }
    T *newVector = new T[newSize];
    int index = 0;
    if (newSize > mSize) {
        for (; index < mSize; ++index) {
            newVector[index] = mVector[index];
        }
        for (; index < newSize; ++index) {
            newVector[index] = mVector[0];
        }
    } else {
        for (; index < newSize; ++index) {
            newVector[index] = mVector[index];
        }
    }
    delete [] mVector;
    mVector = newVector;
    mSize = newSize;
    return *this;
}

template <class T>
vector<T>& vector <T>::pushBack(T data) {
    resize(mSize+1);
    mVector[mSize-1] = data;
    return *this;
}

template <class T>
vector<T>& vector <T>::pushAt(int pos, T data) {
    if (pos < 0 or pos > mSize) {
        raiseException(900, pos);
    }
    if (pos == mSize) {
        pushBack(data);
        return *this;
    }
    T* newVector = new T[++mSize];
    int index = 0;
    for (; index < pos; ++index) {
        newVector[index] = mVector[index];
    }
    newVector[pos] = data;
    index++;
    for (; index < mSize; ++index) {
        newVector[index] = mVector[index - 1];
    }
    delete [] mVector;
    mVector = newVector;
    return *this;
}

template <class T>
vector<T>& vector <T>::deleteAt(int pos) {
    if (pos < 0 or pos >= mSize) {
        raiseException(900, pos);
    }
    if (mSize == 1) {
        mSize = 0;
        mVector = nullptr;
    }
    T *newVector = new T[--mSize];
    int index = 0;
    for (; index < pos; ++index) {
        newVector[index] = mVector[index];
    }
    ++index;
    for (; index < mSize; ++index) {
        newVector[index - 1] = mVector[index];
    }
    delete [] mVector;
    mVector = newVector;
    return *this;
}

template <class T>
vector<T>& vector <T>::clear(int index) {
    delete [] mVector;
    mVector = nullptr;
    mSize = 0;
}

template <class T>
void vector <T>::print() const {
    if (mSize == 0) {
        std::cout << "[ ]";
    } else {
        std::cout << "[";
        for (int i = 0; i < mSize; ++i) {
            std::cout << mVector[i];
            if (i != mSize -1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }
}

template <class T>
int vector <T>::find(T data) const {
    for (int i = 0; i < mSize; ++i) {
        if (mVector[i] == data) {
            return i;
        }
    }
    return -1;
}
