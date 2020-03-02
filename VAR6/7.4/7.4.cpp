#include "7.4.h"

list::unit::unit(char character, unit* nextPtr) {
    mCharacter = character;
    mNextPtr = nextPtr;
}

char list::unit::getData() {
    return mCharacter;
}

list::list() {
    mHead = nullptr;
    mSize = 0;
}

int list::getSize() {
    return mSize;
}

void list::pushBack(char character) {
    if (mHead == nullptr) {
        mHead = new unit(character);
    } else {
        unit *current = mHead;
        while (current->mNextPtr != nullptr) {
            current = current->mNextPtr;
        }
        current->mNextPtr = new unit(character);
    }
    mSize++;
}

char &list::operator [](const int index) {
    unit *current = mHead;
    int counter = 0;

    while (current != nullptr) {
        if (counter == index) {
            return current->mCharacter;
        }
        current = current->mNextPtr;
        counter++;
    }
}

bool list::find(char character) {
    int size = getSize();
    if (size == 0) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if ((*this)[i] == character) {
            return true;
        }
    }
    return false;
}

void list::pushRepeatsFrom(list list1, list list2) {
    int size1 = list1.getSize();
    int size2 = list2.getSize();
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (list1[i] == list2[j] and !this->find(list1[i])) {
                this->pushBack(list1[i]);
            }
        }
    }
}



