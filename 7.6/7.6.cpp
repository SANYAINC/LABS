#include "7.6.h"

list::unit::unit(int data, unit *prevPtr, unit *nextPtr) {
    mData = data;
    mPrevPtr = prevPtr;
    mNextPtr = nextPtr;
}

void list::unit::print() {
    printf("%d\n", mData);
}

list::list() {
    mSize = 0;
    mHead = nullptr;
    mTail = nullptr;
}

void list::pushBack(int number) {
    if (mSize == 0) {
        mHead = new unit(number);
        mTail = mHead;
    } else {
        mTail = new unit(number);
        unit *current = mHead;
        while (current->mNextPtr != nullptr) {
            current = current->mNextPtr;
        }
        current->mNextPtr = mTail;
        mTail->mPrevPtr = current;
    }
    mSize++;
}

void list::pushBack(int *array, int length) {
    int counter = 1;
    if (mSize == 0) {
        mHead = new unit(array[0]);
        mTail = mHead;
        mSize++;
    }
    for (; counter < length; ++counter) {
        mTail = new unit(array[counter]);
        unit *current = mHead;
        while (current->mNextPtr != nullptr) {
            current = current->mNextPtr;
        }
        current->mNextPtr = mTail;
        mTail->mPrevPtr = current;
        mSize++;
    }
}


int &list::operator [](const int index) {
    int size = getSize();
    unit *current;
    int counter;
    if (index < size / 2) {
        current = mHead;
        counter = 0;
        while (counter != index) {
            current = current->mNextPtr;
            counter++;
        }
        return current->mData;
    } else {
        current = mTail;
        counter = size - 1;
        while (counter != index) {
            current = current->mPrevPtr;
            counter--;
        }
        return current->mData;
    }
}

int list::getSize() {
    return mSize;
}

int list::calculateProd() {
    int max = getSize();
    int sum = 1;
    int cou1 = 0;
    int cou2 = max - 1;
    for (int i = 0; i < max / 2; ++i) {
        sum *= (*this)[cou1++] - (*this)[cou2--];
    }
    return sum;
}

