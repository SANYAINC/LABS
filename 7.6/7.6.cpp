#include "7.6.h"

list::unit::unit(int data, unit *prevPtr, unit *nextPtr) {
    mData = data;
    mPrevPtr = prevPtr;
    mNextPtr = nextPtr;
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


