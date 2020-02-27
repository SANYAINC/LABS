#include <cstdlib>
#include "7.5.h"

list::list(const int n) {
    mA = new char[n];
    mB = new int[n];
    for (int i = 0; i < n; ++i) {
        mA[i] = 0;
        mB[i] = -1;
    }
    mBeg = 0;
    mEnd = 0;
    mSize = n;
}

void list::pushBack(char character) {
    if (mEnd == 0) {
        mA[0] =character;
        mB[0] = 0;
        mEnd++;
    } else {
        int current = mBeg;
        while (mB[current] != 0) {
            current = mB[current];
        }
        mA[mEnd] = character;
        mB[current] = mEnd;
        mB[mEnd] = 0;
        mEnd++;
    }
}

int list::getSize() {
    return mEnd;
}

char &list::operator [](const int index) {
    if (index >= mEnd or index < 0) {
        exit(100);
    }
    int counter = 0;
    int current = mBeg;
    while (counter != index) {
        current = mB[current];
        counter++;
    }
    return mA[counter];
}

void list::pushRepeatsFrom(list list1, list list2) {
    int size1 = list1.getSize();
    int size2 = list2.getSize();
    if (!size1 or !size2) {
        return;
    }
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (list1[i] == list2[j] and !this->find(list1[i])) {
                this->pushBack(list1[i]);
            }
        }
    }
}

bool list::find(char character) {
    int size = getSize();
    if (size == 0) {
        return false;
    } else {
        for (int i = 0; i < size; ++i) {
            if ((*this)[i] == character) {
                return true;
            }
        }
        return false;
    }
}





