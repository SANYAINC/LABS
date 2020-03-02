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
        mHead = new unit(number); //Связь с головой
        mTail = mHead;  //Связь с хвостом
    } else {
        mTail = new unit(number); //Связь с хвостом
        unit *current = mHead;
        while (current->mNextPtr != nullptr) { //Поиск до последнего элемента
            current = current->mNextPtr;
        }
        current->mNextPtr = mTail; // Связь последнего с новым
        mTail->mPrevPtr = current; // Связь хвоста с новым
    }
    mSize++;
}

void list::pushBack(int *array, int length) {
    int counter = 0;
    if (mSize == 0) {
        mHead = new unit(array[counter++]);
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
    if (index < size / 2) { //Поиск с начала
        current = mHead;
        counter = 0;
        while (counter != index) {
            current = current->mNextPtr;
            counter++;
        }
        return current->mData;
    } else { //Поиск с конца
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
    int cou1 = 0; //счетчик от нуля до половины
    int cou2 = max - 1; //Счетчик от конца до половины
    for (int i = 0; i < max / 2; ++i) {
        sum *= (*this)[cou1++] - (*this)[cou2--]; //Перемножение
    }
    return sum;
}

