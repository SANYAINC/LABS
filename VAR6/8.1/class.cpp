#include "class.h"

ostream& operator << (ostream &output, vector &v) {
    if (v.getSize()) {
        output << "[";
        for (int i = 0; i < v.getSize(); ++i) {
            output << v[i];
            if (i != v.getSize() - 1) {
                output << ", ";
            } else {
                output << "]" << endl;
            }
        }
    } else {
        output << "[ ]" << endl;
    }
    return output;
}
istream& operator >> (istream &input, vector &v) {
    try {
        if (!v.getSize()) {
            throw "FILLING EMPTY VECTOR";
        }
        int buffer;
        for (int i = 0; i < v.getSize(); ++i) {
            input >> buffer;
            if (input.fail()) {
                throw buffer;
            }
            v[i] = buffer;
        }
        return input;
    } catch (const char* errMsg) {
        cerr << errMsg;
        exit(404);
    } catch (int buffer) {
        cerr << "BAD INPUT";
        exit(503);
    }
}
int& vector::operator [] (const int index) const {
    try {
        if (index < 0 or index > mSize - 1) {
            throw index;
        }
    } catch (int invalidIndex) {
        cerr << "INDEX " << invalidIndex <<" IS OUT OF RANGE (" << "0-"  << mSize - 1 << ")" << endl;
        exit(404);
    }
    return mVector[index];
}
vector& vector::operator = (const vector &secondVector) {
    if (&secondVector == this) {
        return *this;
    }
    (*this).resize(secondVector.getSize());
    for (int i = 0; i < secondVector.getSize(); ++i) {
        mVector[i] = secondVector[i];
    }
    return *this;
}


vector::vector() {
    mSize = 0;
    mVector = nullptr;
}
vector::vector(const int size, int filler) {
    mSize = size;
    mVector = new int[mSize];
    for (int i = 0; i < mSize; ++i) {
        mVector[i] = filler;
    }
}
vector::vector(const vector &secondVector) {
    mSize = secondVector.getSize();
    mVector = new int[mSize];
    for (int i = 0; i < secondVector.getSize(); ++i) {
        mVector[i] = secondVector[i];
    }

}
vector::~vector() {
    mSize = 0;
    delete [] (mVector);
}


int vector::getSize() const{
    return mSize;
}
void vector::resize(const int newSize, const int filler) {
    try {
        if (newSize <= 0) {
            throw newSize;
        }
    } catch (int badSize) {
        cerr << "CAN'T RESIZE (TRIED FROM " << mSize << " TO " << badSize << ")" << endl;
        exit(400);
    }

    int *newVector = new int[newSize];
    int i = 0;
    int minSize = mSize < newSize ? mSize : newSize;
    for (; i < minSize ; ++i) {
        newVector[i] = mVector[i];
    }
    if (mSize < newSize) {
        for (; i < newSize; ++i) {
            newVector[i] = filler;
        }
    }
    delete [] mVector;
    mSize =  newSize;
    mVector = newVector;
}
void vector::show() const {
    if (mSize) {
        cout << "[";
        for (int i = 0; i < mSize; ++i) {
            cout << mVector[i];
            if (i != mSize - 1) {
                cout << ", ";
            } else {
                cout << "]" << endl;
            }
        }
    } else {
        cout << "[ ]" << endl;
    }
}
void vector::fillRandom(const int range, const int shift) const {
    srand(time(nullptr));
    for (int i = 0; i < mSize; ++i) {
        mVector[i] = rand()%range + shift;
    }
}
void vector::pushBack(const int element) {
    this->resize(mSize + 1);
    mVector[mSize - 1] = element;
}
void vector::removeAt(const int index) {
    try {
        if (index < 0 or index > mSize - 1) {
            throw index;
        }
    } catch (int invalidIndex) {
        cerr << "INDEX " << invalidIndex <<" IS OUT OF RANGE (" << "0-"  << mSize - 1 << ")" << endl;
        exit(404);
    }

    int *newVector = new int[mSize - 1];
    int newIndex = 0;
    int oldIndex = 0;
    while (newIndex < mSize - 1) {
        if (oldIndex != index) {
            newVector[newIndex++] = mVector[oldIndex++];
        } else {
            oldIndex++;
        }
    }
    delete [] mVector;
    mVector = newVector;
    mSize--;
}
int vector::find(const int element) {
    for (int i = 0; i < mSize; ++i) {
        if (mVector[i] == element) {
            return i;
        }
    }
    return -1;
}